struct edge{
    int from,to,w,id;
};

int k=0,n,s,t,m,td[MAXN],low[MAXN],memo[MAXN],bridges[MAXN];
vector<edge> GM[MAXN];

void dfs(int v,int id){
    
    memo[v]=1;
    td[v]=k++; //tiempo de inicializacion
    low[v]=td[v]; //low de cada nodo
    
    FOR(i,0,GM[v].size()){
        int u=GM[v][i].to,nid=GM[v][i].id; //id de las aristas
        
        if(!memo[u]){
            dfs(u,nid);
            low[v]=min(low[v],low[u]);
            if(low[u]==td[u]) bridges[nid]=1; //es un puente
        }else if(nid!=id) low[v]=min(low[v],td[u]);
    }
}
