#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b){
  return (*(int*)a-*(int*)b);
}

int main(){
	int n,x[10000],y[10000];
	int i,j;
	int count;
	
	while(scanf("%d",&n)!=EOF){
		count=0;
		for(i=0;i<n;i++)
			scanf("%d%d",&x[i],&y[i]);
		qsort(x,n,sizeof(int),cmp);
		qsort(y,n,sizeof(int),cmp);
		for(i=0;i<n;i++)
			x[i]-=i;
		qsort(x,n,sizeof(int),cmp);
		for(i=0;i<n/2;i++)
			count+=x[n-1-i]-x[i]+y[n-1-i]-y[i];
		printf("%d\n",count);
	}
}
