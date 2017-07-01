ll sq(ll x){return x*x%mod;}
ll powfast(ll b, ll e){
	if(!e) return 1;
	return sq(powfast(b,e>>1)) * (e&1? b : 1) %mod;
}
