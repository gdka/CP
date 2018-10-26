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

const int MAXN = ;
const int INF = 1<<29;
const int NIL = 0;

// A enumerado de 1 a A
// B enumerado de A+1 a A+B < MAXN
vi G[MAXN];
int A, B, match[MAXN], dist[MAXN];

bool bfs() {
	queue<int> q;
	FOR(i,1,A+1){
		if(match[i]==NIL) {
			dist[i]=0;
			q.push(i);
		} else dist[i]=INF;
	}
	dist[NIL] = INF;
	while(!q.empty()) {
		int u = q.front(); q.pop();
		if(u!=NIL) {
			FOR(i,0,G[u].size()){
				int v = G[u][i];
				if(dist[match[v]]==INF) {
					dist[match[v]] = dist[u] + 1;
					q.push(match[v]);
				}
			}
		}
	}
	return (dist[NIL]!=INF);
}

bool dfs(int u) {
	if(u!=NIL) {
		FOR(i,0,G[u].size()){
			int v = G[u][i];
			if(dist[match[v]]==dist[u]+1) {
				if(dfs(match[v])) {
					match[v] = u;
					match[u] = v;
					return true;
				}
			}
		}
		dist[u] = INF;
		return false;
	}
	return true;
}

int HK(){
	ms(match, 0);
	int MBM = 0;
	while(bfs())
		FOR(i,1,A+1)
			if(match[i]==NIL && dfs(i))
			MBM++;
	return MBM;
}


/*
 * 
 * int L, R, k;
vector<vector<int>> adj;
vector<int> matchL, matchR;
vector<int> depth;

bool bfs(int from, int to) {
	depth.assign(L+1,INT_MAX);
	queue<int> q;
	for (int i = from; i < to; i++) if (matchL[i] == R) {
		depth[i] = 0; q.push(i);
	}
	while (!q.empty()) {
		int i = q.front(); q.pop();
		if (depth[i] >= depth[L]) continue;
		for (const auto &j : adj[i]) {
			if (depth[matchR[j]] == INT_MAX) {
				depth[matchR[j]] = depth[i] + 1;
				q.push(matchR[j]);
			}
		}
	}
	return depth[L] < INT_MAX;
}

bool dfs(int i) {
	if (i == L) return true;
	for (const auto &j : adj[i]) {
		if (depth[matchR[j]] == depth[i] + 1 && dfs(matchR[j])) {
			matchL[i] = j; matchR[j] = i; return true;
		}
	}
	depth[i] = INT_MAX;
	return false;
}

int max_matching(int from, int to) {
	int res = 0;
	while (bfs(from,to)) {
		for (int i = from; i < to; i++) {
			if (matchL[i] == R && dfs(i)) res++;
		}
	}
	return res;
}
* 
* 
* int main() {
	int m, n;
	cin >> m >> n >> k;
	L = m+1, R = n; // L MAYOR

	adj.resize(m+2);
	matchL.resize(L,R);
	matchR.resize(R,L);
	* 
	* }
	* 
	* /// QUERIES max_matching(0,m) //sin incluir m
* 
* */
