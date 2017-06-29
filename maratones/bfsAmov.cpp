typedef long long ll;
int mat[183][183];
int d[183][183];
int mf[4]={1,-1,0,0}, mc[4]={0,0,1,-1};
bool valido(int f, int c){ return( f>-1 && c>-1 && f<F && c<C); }

int bfs(pair<int,int> p){
    queue <pair<int,int> > cola;
    cola.push(p);
    memset(d,-1); //Arreglar
    d[p.first][p.second]=0;
    while(!cola.empty()){
        int f=cola.front().first,c=cola.front().second; cola.pop();
        for(int k=0; k<4; k++){
            int nf=f+mf[k],nc=c+mc[k];
            if(valido(nf,nc) && d[nf][nc]==-1){
                d[nf][nc]=d[f][c]+1;
                cola.push(make_pair(nf,nc));
            }
        }
    }
}
