// BIT (tambien se llaman fenwick tree)


//	Empieza con puros 0, suponiendo que tienen un arreglo A[] inicial, tienen
//que meterlo en el BIT a lo brutico, iterando sobre A y haciendo puros updates

int BIT[MAXN];

//suma val a la posicion p, tengan en cuenta que esto no modifica A, a veces se quiere
//modificar, entonces lo tienen que hacer tambien a parte.
void BIT_upd(int p, int val){ //O(log(n))
	p++;
	for(; p <= N; p += p & -p)
		BIT[p] += val;
}

//devuelve la suma de [0,p]
int BIT_sum(int p){ //O(log(n))
	int ret = 0;
	p++;
	for(; p; p -= p & -p)
		ret += BIT[p];
	return ret;
}



/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////



// Los BITS se pueden extender a varias dimensiones :O (los segment tree tambien
// pero mucho mas fastidioso (no lo he hecho nunca))
int BIT[MAXN][MAXN];
//Suma val a la pos x,y
void UPDATE(int x , int y , int val){ // O(log^2(N))
	for(; x <= N; x += (x & -x)){
		for(int y1 = y; y1 <= N; y1 += (y1 & -y1)){
			BIT[x][y1] += val;
		}
	}
}

// Devuelve la suma de todo el rectangulo desde 1,1 hasta x,y
int SUM(int x,int y){ //O(log^2(N))
	int sum= 0;
	for(; x; x -= x & -x){
		for(int y1 = y;y1; y1 -= y1 & -y1){
			sum += BIT[x][y1];
		}
	}
	return sum;
}
