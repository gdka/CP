#include <bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long ll;
#define MAXN ;

//OJO NO LO HE PROBADO XD
//EL DE ARRE MOV ESTA EN BITMAP2

vector <int> bfs(int raiz, int n){
    queue<int> cola;
    vector <int> d(n,-1);
    cola.push(raiz);
    d[raiz]=0;
    while(!cola.empty()){
        int t=cola.front(); cola.pop();
        for(int i=0; i<G[t].size(); i++){
            if(d[G[t][i]==-1){
                d[G[t][i]]=d[t]+1;
                cola.push(G[t][i]);
            }
        }

    }
    return(d);
}


int main(){

    vector <int> dm=bfs(raiz,maxn);
}
