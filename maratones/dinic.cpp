#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <cctype>
#include <set>
#include <limits>
using namespace std;

#define FOR(i,f,t) for(int i=f; i<t; i++)
#define ms(obj, val) memset(obj, val, sizeof(obj))
#define pb push_back
#define ri(x) scanf("%d", &x)
#define rii(x,y) scanf("%d %d", &x, &y)
#define SYNC ios_base::sync_with_stdio(false)

typedef long long ll;

const int MAXN = 5e3+3;
const ll INF = 1LL<<61;
 
struct edge {
	int a, b;
	ll cap, flow;
};
 
int N, M, s, t, d[MAXN], ptr[MAXN];
vector<edge> e; //con add_edge
vector<int> G[MAXN]; //no lo lleno yo se limpia
 
void add_edge(int a, int b, ll cap) {
	edge e1 = { a, b, cap, 0 };
	edge e2 = { b, a, 0, 0 };
	G[a].pb((int)e.size());
	e.pb(e1);
	G[b].pb((int) e.size());
	e.pb(e2);
}
 
bool bfs() {
	queue<int> q;
	q.push(s);
	memset (d, -1, (N+1) * sizeof d[0]);
	d[s] = 0;
	while(!q.empty() && d[t] == -1) {
		int v = q.front(); q.pop();
		FOR(i,0,G[v].size()){
			int id = G[v][i], to = e[id].b;
			if(d[to] == -1 && e[id].flow < e[id].cap){
				q.push(to);
				d[to] = d[v] + 1;
			}
		}
	}
	return d[t] != -1;
}
 
ll dfs(int v, ll flow){
	if(!flow) return 0;
	if (v == t)  return flow;
	for (; ptr[v]<(int)G[v].size(); ++ptr[v]) {
		int id = G[v][ptr[v]], to = e[id].b;
		if(d[to] != d[v]+1) continue;
		int pushed = dfs(to, min(flow, (ll) e[id].cap - e[id].flow));
		if(pushed){
			e[id].flow += pushed;
			e[id^1].flow -= pushed;
			return pushed;
		}
	}
	return 0;
}
 
ll dinic() {
	ll flow = 0;
	while(true){
		if (!bfs())  break;
		memset (ptr, 0, (N+1) * sizeof ptr[0]);
		while (ll pushed = dfs(s, INF))
			flow += pushed;
	}
	return flow;
}
