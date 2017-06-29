#include <bits/stdc++.h>
using namespace std;

#define FOR(i,f,t) for(int i=(int)f; i<(int)t; i++)
#define FORR(i,f,t) for(int i=(int)f; i>(int)t; i--)
#define ms(obj, val) memset(obj, val, sizeof(obj))
#define pb push_back
#define SYNC ios_base::sync_with_stdio(false)
#define inf 2248012
#define mp make_pair
#define F first
#define S second
#define ri(x) scanf("%d",&x)
#define rii(x,y) scanf("%d %d",&x,&y)
#define riii(x,y,z) scanf("%d %d %d",&x,&y,&z)
#define lri(x) scanf("%lld",&x)
#define lrii(x,y) scanf("%lld %lld",&x,&y)
#define lriii(x,y,z) scanf("%lld %lld %lld",&x,&y,&z)

typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> ii;

const int MAXN = 1e5+3;

int N;
double A[MAXN];
double pi=  4*atan(1);

double ST[4*MAXN];

void STB(int id = 1,int l = 0,int r = N){
	if(r - l < 2){
		ST[id] = A[l];
		return;
	}
	int M = (l+r)>>1, L=id<<1, R=L|1;
	STB(L, l, M);
	STB(R, M, r);
	ST[id]=max(ST[L],ST[R]);
}

double STQ(int x,int y,int id = 1,int l = 0,int r = N){
	if(x == l && y == r)	return ST[id];
	int M = (l+r)>>1, L=id<<1, R=L|1;
	if(x>=M)	return STQ(x,y,R,M,r);
	if(y<=M)	return STQ(x,y,L,l,M);

	double res,ln=STQ(x, M, L, l, M),rn=STQ(M, y, R, M, r);
	return res=max(ln, rn);
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

	ST[id]=max(ST[L],ST[R]);
}

int pos[MAXN];
double v2[MAXN];
pair<double,int> v[MAXN];

int main(){
	ri(N);
	FOR(i,0,N){
		double r,h;
		scanf("%lf%lf",&r,&h);
		double c=r*r*h;
		v[i]={c,-i};
		v2[i]=c;
	}
	sort(v,v+N);
	FOR(i,0,N) pos[-v[i].S]=i+1;

	A[pos[0]]=v2[0];
	STB();
	double ans=v2[0];
	FOR(i,1,N){
		int j=pos[i];
		double s=(STQ(0,j));
		if(j==1 && v2[i]==v2[0]) s=0;
		A[pos[i]]=v2[i]+s;
		STU(pos[i],A[pos[i]]);
		ans=max(A[pos[i]],ans);
	}
	printf("%.12lf\n",ans*pi);
	
}
