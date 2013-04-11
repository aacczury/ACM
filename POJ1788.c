#include <stdio.h>
#include <stdlib.h> 

int cmpx(const void *a, const void *b){
	if(*(int *)a==*(int *)b)return *((int *)a+1)-*((int *)b+1);
	return *(int *)a-*(int *)b;
}

int cmpy(const void *a, const void *b){
	if(*((int *)a+1)==*((int *)b+1))return *(int *)a-*(int *)b;
	return *((int *)a+1)-*((int *)b+1);
}

int point[100001][2];
int main(){
	int n,i,len;
	while(scanf("%d",&n)!=EOF){
		if(!n)
			break;
		len=0;
		for(i=0;i<n;i++)
			scanf("%d%d",&point[i][0],&point[i][1]);
		qsort(point, n, sizeof(int)*2, cmpx);
		for(i=0;i<n-1;i+=2)
			if(point[i][0]==point[i+1][0])
				len+=point[i+1][1]-point[i][1];
			else
				i--;
		qsort(point, n, sizeof(int)*2, cmpy);
		for(i=0;i<n-1;i+=2)
			if(point[i][1]==point[i+1][1])
				len+=point[i+1][0]-point[i][0];
			else
				i--;
		printf("The length of the fence will be %d units.\n",len);
	}
	return 0;
}
