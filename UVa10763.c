#include <stdio.h>

int cmpa(const void *a, const void *b){
	if(*(int *)a==*(int *)b)return *((int *)a+1)-*((int *)b+1);
	return *(int *)a-*(int *)b;
}

int cmpb(const void *a, const void *b){
	if(*((int *)a+1)==*((int *)b+1))return *(int *)a-*(int *)b;
	return *((int *)a+1)-*((int *)b+1);
}

int can[500000][2],temp[500000];

int main(){
	int n,i;
	while(scanf("%d",&n)!=EOF&&n){
		for(i=0;i<n;++i)
			scanf("%d%d",&can[i][0],&can[i][1]);
		qsort(can, n, sizeof(int)*2, cmpa);
		for(i=0;i<n;++i)
			temp[i]=can[i][1];
		qsort(can, n, sizeof(int)*2, cmpb);
		for(i=0;i<n;++i)
			if(temp[i]!=can[i][0])
				break;
		if(i==n)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
