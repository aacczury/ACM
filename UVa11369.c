#include <stdio.h>

int cmp(const void *a, const void *b){
	return *(int *)b-*(int *)a;
}

int main(){
	int t,n,item[20000],i,total;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		total=0;
		for(i=0;i<n;i++)
			scanf("%d",&item[i]);
		qsort(item, n, sizeof(int), cmp);
		for(i=2;i<n;i+=3)
			total+=item[i];
		printf("%d\n",total);
	}
	return 0;
}
