#include <bits/stdc++.h>

using namespace std;

#define inf 200005
#define pb push_back
#define mp make_pair

typedef long long ll;
vector <pair<int,int> > grafo[MAXN]
int n;

vector<int> dijkstra(int raiz){
    vector<int> d(n+5,-1);
    vector<bool> marcas(n+1,false);
    priority_queue <pair<int, int> > cola;
    d[raiz]=0;
    cola.push(mp(0,raiz));
    while(!cola.empty()){  //ESTE WHILE ITERA N VECES
        int u = cola.top().second; cola.pop();
        if(!marcas[u]){
            marcas[u] = true;
            for(int i=0; i<grafo[u].size(); i++){  // este for ESTE ESTE ESTE xD
                int v=grafo[u][i].first, h=grafo[u][i].second;
                if(d[v]==-1 || d[v]>d[u]+h){
                    d[v]=d[u]+h;
                    if(!marcas[v])cola.push(mp(-d[v],v));
                }
            }
        }
    }
    return(d);
}

int dijkstra(int raiz,int y){
    vector<int> d(n+1,inf);
    vector<bool> marcas(n+1,false);
    priority_queue <pair<int, int> > cola;
    d[raiz]=0;
    pair<int,int> p=make_pair(0,raiz);
    cola.push(p);
    while(true){  //ESTE WHILE ITERA N VECES
        int u = cola.top().second; cola.pop();
        if(u==y)return(d[y]);
        if(!marcas[u]){
            marcas[u] = true;
            for(int i=0; i<grafo[u].size(); i++){  // este for ESTE ESTE ESTE xD
                int v=grafo[u][i];
                if(d[v]>d[u]+valor[u][v]){
                    d[v]=d[u]+valor[u][v];
                    if(!marcas[v])cola.push(make_pair(-d[v],v));
                }
            }
        }
    }
    return(d[y]);
}

//MODIFICAR PERO ESTE ES SIN ARREGLO VALOR SI NO CON PARES
int dijk2(int raiz){
    vector<int> d(p+2,-1);
    vector<bool> marcas(p+2,false);
    ll suma=0;
    priority_queue <pair<int, int> > cola;
    d[raiz]=0;
    pair<int,int> par=make_pair(0,raiz);
    cola.push(par);
    while(!cola.empty()){
        int u = cola.top().second, t=cola.top().first; cola.pop();
        if(!marcas[u]){
            marcas[u] = true;
            t=-t; suma+=t;
            for(int i=0; i<grafo2[u].size(); i++){
                int v=grafo2[u][i].first, v2=grafo2[u][i].second;
                if(d[v]==-1 ||d[v]>d[u]+v2){
                    d[v]=d[u]+v2;
                    if(!marcas[v])cola.push(make_pair(-d[v],v));
                }
            }
        }
    }
    return(suma);
}
