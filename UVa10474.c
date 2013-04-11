#include <stdio.h>

int cmp(const void *a, const void *b){
	return *(int *)a-*(int *)b;
}

int main(){
	int n,q,t=0,f,i,j;
	int m[10000];
	while(scanf("%d%d",&n,&q)!=EOF){
		if(!n&&!q)break;
		t++;
		for(i=0;i<n;i++)
			scanf("%d",&m[i]);
		qsort(m, n, sizeof(int), cmp);
		printf("CASE# %d:\n",t);
		for(i=0;i<q;i++){
			scanf("%d",&f);
			for(j=0;j<n;j++)
				if(m[j]==f){
					printf("%d found at %d\n",f,j+1);
					break;
				}
			if(j==n)
				printf("%d not found\n",f);
		}
	}
	return 0;
}
