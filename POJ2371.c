#include <stdio.h>

int cmp(const void *a, const void *b){
	return *(int *)a-*(int *)b;
}


int main(){
	int k,i;
	int value[100000];
	int tmp;
	while(scanf("%d",&k)!=EOF){
		for(i=0;i<k;i++)
			scanf("%d",&value[i]);
		qsort(value, k, sizeof(int), cmp);
		getchar();getchar();getchar();getchar();
		scanf("%d",&k);
		for(i=0;i<k;i++){
			scanf("%d",&tmp);
			printf("%d\n",value[tmp-1]);
		}
	}
	return 0;
}
