//---------------------------------------LCA----------------------------------------------

int H[MAXN];
int anc[MAXN][MAXLOG]; // LLENALO MALDITA IMBECIL init -1 maxlog == logn +1 o masXD 
// int mini[MAXN][MAXLOG];
void dfs_pre_LCA(int v, int p = -1){
	anc[v][0] = p;
	if(p != -1) H[v] = H[p] + 1;
	else H[v]=0;

	FOR(i,1,MAXLOG) if(anc[v][i-1] != -1)
		anc[v][i] = anc[anc[v][i-1]][i-1];

	FOR(i,0,G[v].size()){
		int u=G[v][i];
		if(p != u){
			dfs_pre_LCA(u,v);
			// mini[v][i] = min(mini[v][i-1],mini[anc[v][i-1]][i-1]); // CALCULO DEL MIN DE V hasta el ancestro I (lo q permite hallar todos)
		}
	}
}

//Query:
int LCA(int u,int v){
	if(H[v] < H[u]) swap(v,u);

	FORR(i,MAXLOG-1,-1)
		if(anc[v][i] != -1 && H[anc[v][i]] >= H[u])
			v = anc[v][i];

	if(v == u) return v;
	
	FORR(i,MAXLOG-1,-1)
		if(anc[v][i] != anc[u][i])
			v = anc[v][i], u = anc[u][i];
		
	return anc[v][0];
}

/* QUERY CON EL MIN

int LCA(int u,int v){
	if(H[v] < H[u]) swap(v,u);
	int val = 1e9;
	FORR(i,MAXLOG-1,-1)
		if(anc[v][i] != -1 && H[anc[v][i]] >= H[u]){
			val = min(val,mini[v][i]);
			v = anc[v][i];
		}

	if(v == u) return val;
	
	FORR(i,MAXLOG-1,-1)
		if(anc[v][i] != anc[u][i]){
			val = min(mini[v][i],val);
			val = min(mini[u][i],val);
			v = anc[v][i], u = anc[u][i];
		}
	return min(val,min(mini[v][0],mini[u][0]));
} */
