	fac[0]=1;
	fac[1]=1;
	FOR(i,2,MAXN) fac[i]=(fac[i-1]*i)%mod;
	invfac[0]=1;
	
	FOR(i,1,MAXN) invfac[i]=powfast(fac[i],mod-2);
