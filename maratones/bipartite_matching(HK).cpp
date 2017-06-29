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
