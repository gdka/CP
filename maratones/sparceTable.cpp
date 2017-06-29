int query(int x,int y){
	len=y-x+1;
	k=log2(len);
	return min(M[x][k],M[y+1-(1<<k)][k]);
}

int N = Array.size();
FOR(i,0,N) M[i][0]=array[ i ];
for(int j=1; j<=log2(N); j++)
	for(int i=0;i+(1<<(j-1))<N;i++) 
		M[i][j]=min(M[i][j-1],M[i+(1<<(j-1))][j-1]); //MOSCA CON LA PRECEDENCIA >> + - revisar toodo
