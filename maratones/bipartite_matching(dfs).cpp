//------------------------------------BIPARTITE MATCHING------------------------------------


int A, B;
vi AB[MAXA];
bool vis[MAXA];
int matchA[MAXA], matchB[MAXB];

bool match(int a){
	if(vis[a]) return false;
	vis[a]=true;
	FOR(i,0,AB[a].size()){
		int b=AB[a][i];
		if(b==matchA[a]) continue;
		if(matchB[b]==-1 || match(matchB[b])){
			matchB[b]=a;
			matchA[a]=b;
			return true;
		}
	}
	return false;
}

int maxMatch(){
	int MBM=0;
	ms(matchA,-1);
	ms(matchB,-1);
	FOR(a,0,A){
		ms(vis,false);
		if(match(a)) MBM++;
	}
	return MBM;
}
