#include <vector>
using namespace std;

// All intervals are semi-closed [x,y)
// The root is T[1] and represents [0,N)

struct stnode{
	void merge(stnode& L, stnode& R){ }
	void operator=(int x){ }
	//...
};
struct ST{
	vector<stnode> T;
	int N;
	void init(int n){
		T.resize(4*n + 4);
		N = n;
	}
	void build(){build(1,0,N);}
	void build(int id, int l, int r){
		if(r - l < 2){
			//T[id] = A[l];
			return;
		}
		int M = (l+r)>>1, L=id<<1, R=L|1;
		build(L, l, M); build(R, M, r);
		T[id].merge(T[L],T[R]);
	}

	stnode query(int x, int y){return query(x,y,1,0,N);}
	stnode query(int x, int y, int id, int l, int r){
		if(x == l && y == r)	return T[id];
		int M = (l+r)>>1, L=id<<1, R=L|1;
		if(x>=M)	return query(x,y,R,M,r);
		if(y<=M)	return query(x,y,L,l,M);
		stnode res,ln=query(x, M, L, l, M),rn=query(M, y, R, M, r);
		return res.merge(ln, rn), res;
	}

	void update(int p, int x){update(p, x, 1, 0, N);}
	void update(int p, int x, int id, int l, int r){
		if(r - l < 2){
			//T[id]=x; ////////////////////////
			return;
		}
		int M = (l+r)>>1, L=id<<1, R=L|1;
		if(p < M) update(p, x, L, l, M);
		else update(p, x, R, M, r);
		T[id].merge(T[L],T[R]);
	}
};


















int main(){}
