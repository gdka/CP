#include <bits/stdc++.h>
using namespace std; 
#define MAXN 100005

#define pb push_back

int V, num, scc[MAXN];
vector<int> G[MAXN],GT[MAXN];
bool vis[MAXN];
stack<int> S;
queue<int> Q;

void dfs(int v){
    vis[v] = true;
    for(int i=0;i<G[v].size(); i++)
        if(!vis[G[v][i]])
            dfs(G[v][i]);
    S.push(v);
}

void bfs(int v){
    Q.push(v);
    vis[v] = true;
    int aux;
    while(!Q.empty()){
        aux = Q.front();
        scc[aux] = num;
        Q.pop();
        for(int i=0;i<GT[aux].size();i++){
            if(!vis[GT[aux][i]]){
                Q.push(GT[aux][i]);
                vis[GT[aux][i]] = true;
            }
        }
    }
}

void SCC(){
    memset(vis,false,sizeof(vis));
    for(int i=0;i<V;++i) if(!vis[i]) dfs(i);
    num=0;
    int aux;
    memset(vis,false,sizeof(vis));
    while(!S.empty()){
        aux = S.top();
        S.pop();
        if(!vis[aux]){
            bfs(aux);
            ++num;
        }
    }
}

int main(){
    int e;
    scii(V,e);

    for(int a,b,i=0; i<e; i++){
        scii(a,b)
        G[a].pb(b);
        G[b].pb(a);

    }
    SCC();
}