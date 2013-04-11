#include <stdio.h>

int cmp(const void *a, const void *b){
	int ta=*(int *)a,tb=*(int *)b,sa=*((int *)a+1),sb=*((int *)b+1);
	if(ta*sb==tb*sa)return *((int *)a+2)-*((int *)b+2);
	return ta*sb-tb*sa;
}

int main(){
	int i,j,c,n,tf[1000][3];
	scanf("%d",&c);
	for(j=0;j<c;j++){
		scanf("%d",&n);
		if(j)
			printf("\n");
		for(i=0;i<n;i++){
			scanf("%d%d",&tf[i][0],&tf[i][1]);
			tf[i][2]=i;
		}
		qsort(tf, n, sizeof(int)*3, cmp);
		for(i=0;i<n;i++)
			if(!i)
				printf("%d",tf[i][2]+1);
			else
				printf(" %d",tf[i][2]+1);
		printf("\n");
	}
	return 0;
}
