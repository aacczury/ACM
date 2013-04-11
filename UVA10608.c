#include <stdio.h>

int parent[30001],height[30001];

int findSet(int x){
	if(parent[x]==x)
		return x;
	return parent[x]=findSet(parent[x]);
}

void unionSet(int a,int b){
	if (a==b)
		return;
	if (height[a]>height[b])
		parent[b]=a;
	else {
		parent[a]=b;
		if (height[a]==height[b])
			++height[b];
	}
}

int main(){
	int root[30001];
	int max,n,m,i,j,p,q,cc=0,count,cs;
	scanf("%d",&cs);
	while(cs--){
		scanf("%d%d",&n,&m);
		if(!n&&!m)
			break;
		count=0;
		max=0;
		cc++;
		for(i=0;i<=n;i++){
			parent[i]=i;
			height[i]=1;
			root[i]=0;
		}
		for(i=0;i<m;i++){
			scanf("%d%d",&p,&q);
			unionSet(findSet(p),findSet(q));
		}
		for(i=1;i<=n;i++)
			root[findSet(i)]++;
		for(i=1;i<=n;i++)
			if(max<root[i])
				max=root[i];
		printf("%d\n",max);
	}
	return 0;
}
