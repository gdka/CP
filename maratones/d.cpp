#include <bits/stdc++.h>
using namespace std;

#define FOR(i,f,t) for(int i=f; i<t; i++)
#define ms(obj, val) memset(obj, val, sizeof(obj))
#define pb push_back
#define ri(x) scanf("%d", &x)
#define rii(x,y) scanf("%d %d", &x, &y)
#define SYNC ios_base::sync_with_stdio(false)

typedef long long ll;

#define MAXN 100005

int N, A[MAXN];

int compare(int i, int j){
	if(A[i]>=A[j]) return i;
	return j;
}

int ST[4*MAXN];

void STB(int id = 1,int l = 0,int r = N){
	if(r - l < 2){	//	l + 1 == r
		ST[id] = l;
		return;
	}
	int M = (l+r)>>1, L=id<<1, R=L|1;
	STB(L, l, M);
	STB(R, M, r);
	ST[id] = compare(ST[L], ST[R]);
}

int STQ(int x,int y,int id = 1,int l = 0,int r = N){
	if(x == l && y == r)	return ST[id];
	int M = (l+r)>>1, L=id<<1, R=L|1;
	if(x>=M)	return STQ(x,y,R,M,r);
	if(y<=M)	return STQ(x,y,L,l,M);

	return compare(STQ(x, M, L, l, M), STQ(M, y, R, M, r));
}

void STU(int p,int x,int id = 1,int l = 0,int r = N){
	if(r - l < 2){
		A[p] = x;
		ST[id] = p;
		return ;
	}
	int M = (l+r)>>1, L=id<<1, R=L|1;
	if(p < M) STU(p, x, L, l, M);
	else STU(p, x, R, M, r);
	
	ST[id] = compare(ST[L], ST[R]);
}


int main(){
	ri(N);
	FOR(i,0,N) ri(A[i]);
	STB();
	int Q; ri(Q);
	while(Q--){
		char tmp[2]; scanf("%s",tmp);
		if(tmp[0]=='Q'){
			int x, y; rii(x,y); x--; y;
			int a, b, j, i = STQ(x, y);
			a = A[i];
			STU(i, 0);
			j = STQ(x,y);
			b = A[j];
			STU(i, a);
			printf("%d\n", a+b);
		}else{
			int i, x; rii(i,x); i--;
			STU(i, x);
		}
	}
}