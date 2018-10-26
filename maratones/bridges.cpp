struct edge{
    int from,to,w,id;
};

int k=0,n,s,t,m,td[MAXN],low[MAXN],memo[MAXN],bridges[MAXN];
int AP[MAXN];
vector<edge> GM[MAXN];

void dfs(int v,int id){
    memo[v]=1;
    td[v]=k++; //tiempo de inicializacion
    low[v]=td[v]; //low de cada nodo
    int child = 0;
    FOR(i,0,GM[v].size()){
        int u=GM[v][i].to,nid=GM[v][i].id; //id de las aristas
        if(!memo[u]){
            child++;
            dfs(u,nid);
            low[v]=min(low[v],low[u]);
            if(low[u]==td[u]) bridges[nid]=1; //es un puente
            if(parent[v]==-1 && child>1) AP[v]=1;
            if(parent[v]!=-1 && low[v]>=dis[u]) AP[v]=1; 
        }else if(nid!=id) low[v]=min(low[v],td[u]);
    }
}
