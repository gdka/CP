// Todos los intervalos son semi abiertos [a,b), la raiz representa [0,N)

//INPUT:
int N, A[MAXN];

struct STN{
	void merge(STN& L, STN& R){	}
	void operator =(int x){		}
};

STN ST[4*MAXN];
void STB(int id = 1,int l = 0,int r = N){
	if(r - l < 2){
		ST[id] = A[l];
		return;
	}
	int M = (l+r)>>1, L=id<<1, R=L|1;
	STB(L, l, M);
	STB(R, M, r);
	ST[id].merge(ST[L],ST[R]);
}

STN STQ(int x,int y,int id = 1,int l = 0,int r = N){
	if(x == l && y == r)	return ST[id];
	int M = (l+r)>>1, L=id<<1, R=L|1;
	if(x>=M)	return STQ(x,y,R,M,r);
	if(y<=M)	return STQ(x,y,L,l,M);

	STN res,ln=STQ(x, M, L, l, M),rn=STQ(M, y, R, M, r);
	return res.merge(ln, rn), res;
}

void STU(int p,int x,int id = 1,int l = 0,int r = N){
	if(r - l < 2){
		//A[p]=x;
		ST[id]=x;
		return;
	}
	int M = (l+r)>>1, L=id<<1, R=L|1;
	if(p < M) STU(p, x, L, l, M);
	else STU(p, x, R, M, r);

	ST[id].merge(ST[L],ST[R]);
}