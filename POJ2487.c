#include <stdio.h>

int cmp(const void *a, const void *b){
	return *(int *)b-*(int *)a;
}


int main(){
	int i,j,stamp,n,cc,total;
	int fd[1000];
	scanf("%d",&cc);
	for(i=0;i<cc;i++){
		total=0;
		scanf("%d%d",&stamp,&n);
		for(j=0;j<n;j++)
			scanf("%d",&fd[j]);
		qsort(fd, n, sizeof(int), cmp);
		for(j=0;j<n;j++){
			total+=fd[j];
			if(total>=stamp)
				break;
		}
		printf("Scenario #%d:\n",i+1);
		if(j==n)
			printf("impossible\n\n");
		else
			printf("%d\n\n",j+1);
	}
	return 0;
}
