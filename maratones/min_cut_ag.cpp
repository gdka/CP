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
 
const int MAXN = 600;
const ll INF = 1LL<<61;
 
int N;
ll cap[MAXN][MAXN], flow[MAXN][MAXN], cost[MAXN][MAXN];
ll dist[MAXN], pi[MAXN], width[MAXN];
pair<int, int> dad[MAXN];
bool found[MAXN];
 
vector<int> G[MAXN];
 
void add_edge(int from, int to, ll u, ll c) {
	cap[from][to] = u;
	cost[from][to] = c;
}
 
void relax(int s, int k, ll u, ll c, int dir, priority_queue<pair<ll, int> > &pq) {
	ll val = dist[s] + pi[s] - pi[k] + c;
	if (u && val < dist[k]) {
		dist[k] = val;
		pq.push({-val, k});
		dad[k] = {s, dir};
		width[k] = min(u, width[s]);
	}
}
 
ll dijk(int s, int t) {
	fill(found, found+N+1, false);
	fill(dist, dist+N+1, INF);
	fill(width, width+N+1, 0);
	dist[s] = 0;
	width[s] = INF;
 
	priority_queue<pair<ll, int> > pq;
	pq.push({0,s});
 
	while(!pq.empty()){
		int s = pq.top().second; pq.pop();
		if(found[s]) continue;
		found[s] = true;
		FOR(i, 0, G[s].size()){
			int k = G[s][i];
			if(found[k]) continue;
			relax(s, k, cap[s][k] - flow[s][k], cost[s][k], 1, pq);
			relax(s, k, flow[k][s], -cost[k][s], -1, pq);
		}
	}
 
	FOR(k, 0, N)
		pi[k] = min(pi[k] + dist[k], INF);
 
	return width[t];
}
 
pair<ll, ll> get_max_flow(int s, int t) {
	ll totflow = 0, totcost = 0;
	while(ll amt = dijk(s, t)){
		totflow += amt;
		for (int x = t; x != s; x = dad[x].first) {
			if (dad[x].second == 1) {
				flow[dad[x].first][x] += amt;
				totcost += amt * cost[dad[x].first][x];
			} else {
				flow[x][dad[x].first] -= amt;
				totcost -= amt * cost[x][dad[x].first];
			}
		}
	}
	return {totflow, totcost};
}
 
int cnt[MAXN];
 
int main(){
	int TC; ri(TC);
	while(TC--){
		ms(cap,0);
		ms(flow,0);
		ms(cost,0);
		ms(pi,0);
		ri(N);
		ms(cnt,0);
		FOR(i,0,N+2) G[i].clear();
		FOR(i,0,N){
			int x; ri(x);
			cnt[x]++;
		}
		FOR(i,1,N+1){
			G[0].pb(i);
			G[i].pb(0);
			add_edge(0, i, cnt[i], 0);
			G[i].pb(N+1);
			G[N+1].pb(i);
			add_edge(i,N+1, 1, 0);
		}
		N = N+2;
		int M; ri(M);
		FOR(i,0,M){
			int u,v; rii(u,v);
			add_edge(u,v,10*N,1);
			add_edge(v,u,10*N,1);
			G[u].pb(v);
			G[v].pb(u);
		}
		ll min_cost = get_max_flow(0,N-1).second;
		printf("%lld\n", min_cost);
	}
 
}
