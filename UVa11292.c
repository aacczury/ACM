#include <stdio.h>

int cmp(const void *a, const void *b){
	return *(int *)a-*(int *)b;
}

int main(){
	int n,m,i,j,cost;
	int d[20000],k[20000];
	while(scanf("%d%d",&n,&m)!=EOF){
		if(!n&&!m)break;
		for(i=0;i<n;i++)
			scanf("%d",&d[i]);
		for(i=0;i<m;i++)
			scanf("%d",&k[i]);
		qsort(d, n, sizeof(int), cmp);
		qsort(k, m, sizeof(int), cmp);
		cost=0;
		j=0;
		for(i=0;i<n;i++){
			while(j<m&&d[i]>k[j])j++;
			if(j>=m)break;
			cost+=k[j];
			j++;
		}
		if(i==n)
			printf("%d\n",cost);
		else
		 printf("Loowater is doomed!\n");
	}
	return 0;
}
