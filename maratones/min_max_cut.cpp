//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
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
#define MAXN 1100
#define inf 0x3f3f3f3f

struct node {
	int v , f , c , val ;
	node(){}
	node(int _v, int _f , int _c , int _val ) {
		v = _v, f = _f , c = _c , val = _val ;
	}
};

vector<node> edges;
vector<int> graph[MAXN];
int v;
int dist[MAXN], ptr[MAXN] , pai[MAXN];
// val == cost 
// c == capacity 
void add( int u , int v , int c , int val ) {
	edges.pb(node(v,0,c,val));
	graph[u].pb(edges.size()-1);
	edges.pb(node(u,0,0,-val));
	graph[v].pb(edges.size()-1);
}


ii operator+(ii a,ii b){
	a.F += b.F;
	a.S += b.S;
	return a;
}

bool dijkstra( int s , int t ){
	for( int i = 0 ; i < v ; i++){
		dist[i] = inf;
		pai[i] = -1;
	}
	dist[s] = 0 ;
	priority_queue<ii,vector<ii>,greater<ii> > q;
	q.push(ii(0,s));
	while (!q.empty()){
		int d = q.top().F , u = q.top().S;
		q.pop();
		if(d > dist[u]) continue ;
		for( auto e : graph[u] ) {
			if(dist[u] + edges[e].val < dist[edges[e].v] && edges[e].c-edges[e].f > 0 ){
				dist[edges[e].v] = dist[u]+edges[e].val;
				pai[edges[e].v] = u;
				q.push({dist[edges[e].v],edges[e].v});
			}
		}
	}
	return dist[t]!=inf;
}

ii dfs(int s , int t , int f){
	if(s==t) return ii (0,f);
	
	for ( int &i = ptr[s]; i < graph[s].size() ; i++){
		int e = graph[s][i];
		if(pai[edges[e].v]==s && dist[edges[e].v]==dist[s]+edges[e].val && edges[e].c-edges[e].f > 0){
			ii x = ii(edges[e].val,0)+dfs(edges[e].v,t,min(f,edges[e].c-edges[e].f));
			if(x.S){
				edges[e].f += x.S;
				edges[e^1].f -= x.S;
				return x ;
			}
		}
	}
	return ii(0,0) ; 
}

ii get(int s,int t){
	ii ans(0,0);
	while(dijkstra(s,t)) {
		memset(ptr,0,sizeof ptr) ;
		ii x;
		while((x=dfs(s,t,inf)).S)
			ans = ans + x;
	}
	return ans ; //.F == cost .S flow
}


int main(){
	
}
