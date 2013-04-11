#include <stdio.h>

int cmp(const void *a, const void *b){
	if(*(int *)a==*(int *)b)return *((int *)a+1)-*((int *)b+1);
	return *(int *)a-*(int *)b;
}

int main(){
	int pos[10000][2],n,i,midx,midy,c;
	scanf("%d",&c);
	while(c--){
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d%d",&pos[i][0],&pos[i][1]);
		qsort(pos, n, sizeof(int)*2, cmp);
		if(n%2==0){
			midx=pos[n/2-1][0]+pos[n/2][0];
			midy=pos[n/2-1][1]+pos[n/2][1];
		}
		else{
			midx=pos[n/2][0]*2;
			midy=pos[n/2][1]*2;
		}
		for(i=0;i<n/2;i++)
			if(pos[i][0]+pos[n-i-1][0]!=midx||pos[i][1]+pos[n-i-1][1]!=midy)
				break;
		if(i==n/2)
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}
