bool v[MAXN];
int len, sp[MAXN];

void Sieve(){
	for (int i = 2; i < MAXN; i += 2)	sp[i] = 2;//even numbers have smallest prime factor 2
	for (ll i = 3; i < MAXN; i += 2){
		if (!v[i]){
			sp[i] = i;
			for (ll j = i; (j*i) < MAXN; j += 2){
				if (!v[j*i])	v[j*i] = true, sp[j*i] = i;
			}
		}
	}
}
