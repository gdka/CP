#include <vector>
using namespace std;

typedef vector<int> vi;

// All intervals are semi-closed [x,y)

// An update is applied to a node and saved in it for
// its children. 

#define no_lazy -1
// other updates

struct stnode{
	//////////////////
	int lazy=no_lazy;
	stnode *l=NULL, *r=NULL;
	void merge(){merge(*l, *r);}
	void merge(stnode& L, stnode& R){
		/////////////////////
	}
	void operator=(int x){/////////}
	void upd(ll l, ll r, int u){///////}
};
typedef stnode* pstnode;

struct ST{
	vector<pstnode> all;
	ll N;

	void clear(){
		FOR(i,0,all.size()) delete all[i];
		all.clear();
		N=0;
	}
	pstnode new_node(ll l, ll r){
		pstnode v = new stnode();
		//v->upd(l,r,);///////////////
		all.pb(v);
		return v;
	}
	void init(ll n){
		new_node(0,n);
		N = n;
	}

	// this supposes u!=no_lazy (normally this holds)
	void upd(pstnode v, ll l, ll r, int u){
		v->lazy = u;
		v->upd(l,r,u);
	}

	void shift(pstnode v, ll l, ll r){
		ll M = (l+r)>>1;
		if(!v->l){
			v->l = new_node(l,M);
			v->r = new_node(M,r);
		}
		if(v->lazy == no_lazy) return;
		upd(v->l, l, M, v->lazy);
		upd(v->r, M, r, v->lazy);
		v->lazy = no_lazy;
	}
	// careful with val type
	void update(ll x, ll y, int val){update(x, y, val, all[0], 0, N);}
	void update(ll x, ll y, int val, pstnode v, ll l, ll r){
		if(x >= r || l >= y) return;
		if(x <= l && r <= y){
			upd(v, l, r, val);
			return;
		}
		shift(v, l, r);
		ll M = (l+r)>>1;
		update(x, y, val, v->l, l, M);
		update(x, y, val, v->r, M, r);
		v->merge();
	}

	stnode query(ll x, ll y){return query(x,y,all[0],0,N);} ///////////
	stnode query(ll x, ll y, pstnode v, ll l, ll r){
		if(x == l && y == r) return *v;
		shift(v, l, r);
		ll M = (l+r)>>1;
		if(x>=M)	return query(x,y,v->r,M,r);
		if(y<=M)	return query(x,y,v->l,l,M);
		stnode res,ln=query(x, M, v->l, l, M),rn=query(M, y, v->r, M, r);
		return res.merge(ln, rn), res;
	}
};






int main(){}