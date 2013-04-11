#include <stdio.h>

int n,max;
int visit[500],w[500][500];

int prim(){
	int next=0,min,visited[500];
	int i,j,k;
	for(i=0;i<n-1;++i){
		min=100000;
		visited[i]=next;
		visit[next]=1;
		for(j=0;j<=i;++j){
			for(k=0;k<n;++k){
				if(w[visited[j]][k]<min&&!visit[k]){
					min=w[visited[j]][k];
					next=k;
				}
			}
		}
		if(min>max)
			max=min;
	}
}

int main(){
	int i,j,c;
	scanf("%d",&c);
	while(c--){
		scanf("%d",&n);
		max=0;
		for(i=0;i<n;++i)
			visit[i]=0;
		for(i=0;i<n;++i)
			for(j=0;j<n;++j)
				scanf("%d",&w[i][j]);
		prim();
		printf("%d\n%",max);
	}
	return 0;
}
