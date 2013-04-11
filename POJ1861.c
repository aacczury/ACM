#include <stdio.h>

int parent[1001],height[1001];

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

int cmp(const void *a, const void *b){
	if(*(int *)a==*(int *)b){
		if (*((int *)a+1)==*((int *)b+1))
			return *((int *)a+2)-*((int *)b+2);
		return *((int *)a+1)-*((int *)b+1);
	}
	return *(int *)a-*(int *)b;
}

int main(){
	int i,n,m,max,total;
	int w[15000][3];
	int pair[1000][2];
	while(scanf("%d%d",&n,&m)!=EOF){
		total=0;
		max=0;
		for(i=0;i<m;++i)
			scanf("%d%d%d",&w[i][1],&w[i][2],&w[i][0]);
			
		for(i=0;i<=n;i++){
			parent[i]=i;
			height[i]=1;
		}
		
		qsort(w, m, sizeof(int)*3, cmp);
		for(i=0;i<m;++i)
			if(findSet(w[i][1])!=findSet(w[i][2])){
				unionSet(findSet(w[i][1]),findSet(w[i][2]));
				pair[total][0]=w[i][1];
				pair[total][1]=w[i][2];
				total++;
				if(w[i][0]>max)
					max=w[i][0];
			}
		printf("%d\n%d\n",max,total);
		for(i=0;i<total;i++)
			printf("%d %d\n",pair[i][0],pair[i][1]);
	}
	return 0;
}
