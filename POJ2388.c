#include <stdio.h>

int cmp(const void *a, const void *b){
	return *(int *)a-*(int *)b;
}


int main(){
	int n,i;
	int cow[10000];
	while(scanf("%d",&n)!=EOF){
		for(i=0;i<n;i++)
			scanf("%d",&cow[i]);
		qsort(cow, n, sizeof(int), cmp);
		printf("%d\n",cow[n/2]);
	}
	return 0;
}
