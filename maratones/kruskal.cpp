#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define inf 2248012
#define mp make_pair

typedef long long ll;
vector<pair<int,pair<int,int> > > grafo;

int find(int x){
	if(x==rep[x]) return(x);
	else return rep[x]=find(rep[x]);
}

int main(){
	
	for(int i=0; i<n; i++) rep[i]=i;
	sort(grafo.begin(),grafo.end);
	ll suma=0;
	for(int i=0; i<grafo.size(); i++){
		int u=grafo[i].second.first, v=grafo[i].second.second;
		if(find(u)!=find(v)){ suma+=grafo[i].first; rep[find(u)]=find(v);}
	}
}