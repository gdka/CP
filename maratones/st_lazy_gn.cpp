#include <vector>
using namespace std;

typedef vector<int> vi;

// All intervals are semi-closed [x,y)
// The root is T[1] and represents [0,N)

// An update is applied to a node and saved in it for
// its children. 

#define no_lazy 0
// other updates

struct stnode{
    void merge(stnode& L, stnode& R){ }
    void operator=(int x){ }
    void upd(int l, int r, int u){ }
    //...
};
struct ST{
    vector<stnode> T;
    vi lazy;
    int N;
    void init(int n){
        T.resize(4*n + 4);
        lazy.resize(4*n + 4);
        N = n;
    }
    void build(){build(1,0,N);}
    void build(int id, int l, int r){
        lazy[id] = no_lazy;
        if(r - l < 2){
            // T[id] = A[l];
            return;
        }
        int M = (l+r)>>1, L=id<<1, R=L|1;
        build(L, l, M); build(R, M, r);
        T[id].merge(T[L],T[R]);
    }

    // this supposes u!=no_lazy (normally this holds)
    void upd(int id, int l, int r, int u){
        if(l!=r){
            lazy[id<<1] += u;  ////////////////
            lazy[(id<<1)+1] += u;
        }   
        T[id].upd(l,r,u);
        lazy[id] = no_lazy;
    }

    void shift(int id, int l, int r){
        if(lazy[id] == no_lazy) return;
        int M = (l+r)>>1, L=id<<1, R=L|1;
        upd(L, l, M, lazy[id]);
        upd(R, M, r, lazy[id]);
        lazy[id] = no_lazy;
    }

    void update(int x, int y, int v){update(x, y, v, 1, 0, N);}
    void update(int x, int y, int v, int id, int l, int r){
        if(x >= r || l >= y) return;
        shift(id, l, r);
        if(x <= l && r <= y){
            upd(id, l, r, v);
            return;
        }
        int M = (l+r)>>1, L=id<<1, R=L|1;
        update(x, y, v, L, l, M);
        update(x, y, v, R, M, r);
        T[id].merge(T[L], T[R]);
    }

    stnode query(int x, int y){return query(x,y,1,0,N);} ///////////
    stnode query(int x, int y, int id, int l, int r){
        if(x == l && y == r) return T[id];
        shift(id, l, r);
        int M = (l+r)>>1, L=id<<1, R=L|1;
        if(x>=M)    return query(x,y,R,M,r);
        if(y<=M)    return query(x,y,L,l,M);

        stnode res,ln=query(x, M, L, l, M),rn=query(M, y, R, M, r);

        return res.merge(ln, rn), res;
    }
};








int main(){}