#include <stdio.h>

int cmp(const void *a, const void *b){
	return *(long long *)a-*(long long *)b;
}


int main(){
	int n,i;
	long long num[250000];
	while(scanf("%d",&n)!=EOF){
		for(i=0;i<n;i++)
			scanf("%d",&num[i]);
		qsort(num, n, sizeof(long long), cmp);
		if(n%2)
			printf("%d.0\n",num[n/2]);
		else
			printf("%.1f\n",(num[n/2-1]+num[n/2])/2.0);
	}
	return 0;
}
