vector<int> prim(int raiz){
    vector<int> d(n+2,-1);
    vector<bool> marcas(n+1,false);
    priority_queue <pair<int, int> > cola;
    d[raiz]=0;
    pair<int,int> p=make_pair(0,raiz);
    cola.push(p);
    while(!cola.empty()){ 
        int u = cola.top().second; cola.pop();
        if(!marcas[u]){
            marcas[u] = true;
            for(int i=0; i<grafo[u].size(); i++){
                int v=grafo[u][i].first,v2=grafo[u][i].second;
                if( !marcas[v] && (d[v]==-1 || d[v]>v2)){
                    d[v]=v2;
                    if(!marcas[v])cola.push(make_pair(-d[v],v));
                }
            }
        }
    }
    return(d);
}