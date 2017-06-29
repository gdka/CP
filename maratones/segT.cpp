#define MAXN 
int tree[MAXN];
int pos[10000];
int a[100000001];
int mini=0;

void ini(int node, int b, int e){
	if(b==e) pos[node]=b;
	else{
	 	int mid = (b+e)/2;
		ini(2*node, b, mid);
	 	ini(2*node+1, mid+1, e);
	 	if(a[pos[2*node]]>= a[pos[2*node+1]]) pos[node]=pos[2*node];
	 	else pos[node]=pos[2*node+1];
 	}
}


int query(int node, int b, int e, int i, int j){
	if(i>e || j<b) return NEUTRO;
	if(b>=i && e<=j) return a[pos[node]];
	int mid = (b+e)/2;
	int left = query(2*node, b, mid, i, j);
	int right = query(2*node+1, mid+1, e, i, j);
	return max(left, right);
}

void update(int node, int b, int e, int i, int val){
	if(i>e || i<b) return;
	if(b>=i && e<=i){
		a[pos[node]] = val;
		return;
	}
	int mid = (b+e)/2;
	update(2*node, b, mid, i, val);
	update(2*node+1, mid+1, e, i, val);
	if(a[pos[2*node]]>=a[pos[2*node+1]]) pos[node]= pos[2*node];
	else  pos[node]= pos[2*node+1];
}


############################################################################################################################################

void ini(int node, int b, int e){
	if(b==e){tree[node] = a[b]; pos[node]=b;}
	else{
	 	int mid = (b+e)/2;
		ini(2*node, b, mid);
	 	ini(2*node+1, mid+1, e);
	 	if(tree[2*node]>= tree[2*node+1]){
	 		tree[node] =tree[2*node];
	 		pos[node]=pos[2*node];
	 	}else{
	 		tree[node] = tree[2*node+1];	
	 		pos[node]=pos[2*node+1];
	 	}
 	}
}


int query(int node, int b, int e, int i, int j){
	if(i>e || j<b) return NEUTRO;
	if(b>=i && e<=j) return tree[node];
	int mid = (b+e)/2;
	int left = query(2*node, b, mid, i, j);
	int right = query(2*node+1, mid+1, e, i, j);
	return oper(left, right);
}

void update(int node, int b, int e, int i, int val){
	if(i>e || i<b) return;
	if(b>=i && e<=i){
		tree[node] = val;
		return;
	}
	int mid = (b+e)/2;
	update(2*node, b, mid, i, val);
	update(2*node+1, mid+1, e, i, val);
	tree[node] = oper(tree[2*node], tree[2*node+1]);
}