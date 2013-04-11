#include <stdio.h>

int parent[50001],height[50001];

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
	int n,m,i,j,p,q,cc=0,count;
	while(scanf("%d%d",&n,&m)!=EOF){
		if(!n&&!m)
			break;
		count=0;
		cc++;
		for(i=0;i<=n;i++){
			parent[i]=i;
			height[i]=1;
		}
		for(i=0;i<m;i++){
			scanf("%d%d",&p,&q);
			unionSet(findSet(p),findSet(q));
		}
		for(i=1;i<=n;i++)
			if(parent[i]==i)
				count++;
		printf("Case %d: %d\n",cc,count);
	}
	return 0;
}
