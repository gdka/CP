#include <bits/stdc++.h>

using namespace std;

#define FOR(i,f,t) for(int i=(int)f; i<(int)t; i++)
#define FORR(i,f,t) for(int i=(int)f; i>(int)t; i--)
#define ms(obj, val) memset(obj, val, sizeof(obj))
#define pb push_back
#define SYNC ios_base::sync_with_stdio(false)
#define st(v) sort(v.begin(),v.end());
#define F first
#define S second
#define ri(x) scanf("%d",&x)
#define rii(x,y) scanf("%d %d",&x,&y)
#define riii(x,y,z) scanf("%d %d %d",&x,&y,&z)
#define lri(x) scanf("%lld",&x)
#define lrii(x,y) scanf("%lld %lld",&x,&y)
#define lriii(x,y,z) scanf("%lld %lld %lld",&x,&y,&z)

typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> ii;


// All intervals are semi-closed [x,y)
// The root is T[1] and represents [0,N)

// An update is applied to a node and saved in it for
// its children. 

#define no_lazy 0
// other updates

//int A[123456];

struct stnode{
    ll s;
    void merge(stnode& L, stnode& R){
        s = L.s + R.s;
    }
    void operator=(ll x){
        s = x;
    }

    void upd(int l, int r, ll u){
        s += ((r-l)*1ll*u);
    }
    //...
};

struct ST{
    vector<stnode> T;
    vector<ll> lazy;
    int N;
    void init(int n){
        T.resize(4*n + 20);
        lazy.resize(4*n + 20,0);
        N = n;
    }
    void build(){build(1,0,N);}
    void build(int id, int l, int r){
        lazy[id] = no_lazy;
        if(l > r) return; 
        if(r - l < 2){
            T[id] = 0;
            return;
        }
        int M = (l+r)>>1, L=id<<1, R=L|1;
        build(L, l, M); build(R, M, r);
        T[id].merge(T[L],T[R]);
    }

    // this supposes u!=no_lazy (normally this holds)
    void upd(int id, int l, int r, ll u){
        T[id].upd(l,r,u);
        if(r - l >= 2){
            lazy[id<<1] += u;
            lazy[(id<<1)+1] += u;
        }   
    }

    void shift(int id, int l, int r){
        if(lazy[id] == no_lazy) return;
        upd(id, l, r, lazy[id]);
        lazy[id] = no_lazy;
    }

    void update(int x, int y, ll v){update(x, y, v, 1, 0, N);}
    void update(int x, int y, ll v, int id, int l, int r){
        shift(id, l, r);
        if(x >= r || l >= y) return;
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
        shift(id, l, r);
        if(x == l && y == r) return T[id];
        int M = (l+r)>>1, L=id<<1, R=L|1;
        if(x>=M)    return query(x,y,R,M,r);
        if(y<=M)    return query(x,y,L,l,M);

        stnode res,ln=query(x, M, L, l, M),rn=query(M, y, R, M, r);
        return res.merge(ln, rn), res;
    }
};


int main(){
    int tc;
    ri(tc);
    FOR(TC,0,tc){
        int n,c;
        rii(n,c);
        ST seg;
        seg.init(n+1000);
        seg.build();
        FOR(y,0,c){
            int t,p,q,v;
            ri(t);
            if(t){
                rii(p,q);
                p--;
                printf("%lld\n",seg.query(p,q).s); 
            }else{
                rii(p,q);
                ri(v);
                p--;
                seg.update(p,q,v);
            }
        }
    }
}