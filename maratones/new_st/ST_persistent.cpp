#include <vector>
#include <cstdio>
using namespace std;

#define FOR(i,f,t) for(int i=f; i<(int)t; i++)
#define pb push_back
typedef vector<int> vi;

// All intervals are semi-closed [x,y)

struct stnode{
	int sum;
	stnode *l=NULL, *r=NULL;
	void merge(){merge(*l, *r);}
	void merge(stnode& L, stnode& R){sum = L.sum + R.sum;} ////////////////
	void upd(int x){sum = x;} ////////////////
};
typedef stnode* pstnode;

struct ST{
	vector<pstnode> root, all;
	int N;
	void clear(){
		FOR(i,0,all.size()) delete all[i];
		all.clear(); root.clear();
		N=0;
	}
	pstnode new_node(){
		all.pb(new stnode());
		return all.back();
	}
	void init(int n){
		root.pb(new_node());
		N = n;
	}
	void build(){build(root[0],0,N);}
	void build(pstnode v, int l, int r){
		if(r - l < 2){
			v->upd(0); ////////////////
			return;
		}
		int M = (l+r)>>1;
		v->l = new_node();
		v->r = new_node();
		build(v->l, l, M); build(v->r, M, r);
		v->merge();
	}

	int query(int x, int y, int ver){
		return query(x,y,root[ver],0,N).sum; ////////////////
	}
	stnode query(int x, int y, pstnode v, int l, int r){
		if(x == l && y == r)	return *v;
		int M = (l+r)>>1;
		if(x>=M)	return query(x,y,v->r,M,r);
		if(y<=M)	return query(x,y,v->l,l,M);
		stnode res,ln=query(x, M, v->l, l, M),rn=query(M, y, v->r, M, r);
		return res.merge(ln, rn), res;
	}

	int update(int p, int x){
		root.pb(update(p, x, root.back(), 0, N));
		return root.size()-1;
	}
	pstnode update(int p, int x, pstnode v, int l, int r){
		pstnode u = new_node();
		if(r - l < 2){
			u->upd(x);
			return u;
		}
		int M = (l+r)>>1;
		u->l = v->l, u->r = v->r;
		if(p < M) u->l = update(p, x, v->l, l, M);
		else u->r = update(p, x, v->r, M, r);
		u->merge();
		return u;
	}
};
















int main(){}
