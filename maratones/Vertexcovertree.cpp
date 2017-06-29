#include <bits/stdc++.h>
using namespace std;

#define FOR(i,f,t) for(int i=f; i<t; i++)
#define ms(obj, val) memset(obj, val, sizeof(obj))
#define pb push_back
#define SYNC ios_base::sync_with_stdio(false)
#define inf 2248012
#define mp make_pair
#define sci(x) scanf("%d",&x)
#define scii(x,y) scanf("%d %d",&x,&y)
#define sciii(x,y,z) scanf("%d %d %d",&x,&y,&z)

typedef long long ll;

vector <int> grafo[MAXN];

ll vertexCover(int v,int r){
	if(!r) return min(vertexCover(v,r+1),vertexCover(v,r+2));
	else if(r==1){
		ll sum=1;
		FOR(i,0,grafo[v].size()){
			int u = grafo[v][i];
			sum+=vertexCover(u,0);
		}
		return sum;
	}else{
		ll sum=0;
		FOR(i,0,grafo[v].size()){
			int u = grafo[v][i];
			sum+=vertexCover(u,1);
		}
		return sum;
	}
}

int main(){
	
}