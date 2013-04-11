#include <stdio.h>

int cmp(const void *a, const void *b){
	return *(long long *)a-*(long long *)b;
}

int main(){
	int n,i;
	long long total,cow[10000];
	while(scanf("%d",&n)!=EOF){
		total=0;
		for(i=0;i<n;i++)
			scanf("%lld",&cow[i]);
		qsort(cow, n, sizeof(long long), cmp);
		for(i=1;i<n;i++)
			total+=i*(n-i)*(cow[i]-cow[i-1])*2;
		printf("%lld\n",total);
	}
	return 0;
}
