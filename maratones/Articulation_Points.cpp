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

const int MAXN = 1e4+100; //AREGLAAAAAAAAR!!!!

int k=0,td[MAXN],low[MAXN],memo[MAXN],bridges[MAXN],parent[MAXN];
int AP[MAXN];
vector<int> GM[MAXN];

void dfs(int v){
    memo[v]=1;
    td[v]=k++; //tiempo de inicializacion
    low[v]=td[v]; //low de cada nodo
    int child = 0;
    FOR(i,0,GM[v].size()){
        int u=GM[v][i]; //id de las aristas
        if(!memo[u]){
            child++;
            parent[u]=v;
            dfs(u);
            low[v]=min(low[v],low[u]);
            if(parent[v]==-1 && child>1) AP[v]=1;
            if(parent[v]!=-1 && low[u]>=td[v]) AP[v]=1; 
        }else if(parent[v]!=u) low[v]=min(low[v],td[u]);
    }
}


int main(){
    int n,m;
    while(1){
        rii(n,m);
        int t=1;
        if(!n && !m) return 0;
        FOR(i,0,m){
            int u,v;
            rii(u,v);
            u--; v--;
            GM[u].pb(v);
            GM[v].pb(u);
        }
        parent[0]=-1;
        dfs(0);
        int cnt = 0;
        FOR(i,0,n) if(AP[i]) cnt++;
        printf("%d\n",cnt);
        ms(parent,0);
        ms(memo,0);
        ms(low,0);
        ms(td,0);
        ms(AP,0);
        FOR(i,0,n) GM[i].clear();
        k=0;
    }
}