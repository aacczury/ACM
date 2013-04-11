#include <stdio.h>
#include <math.h>

int cmp(const void *a, const void *b){
	return *(int *)a-*(int *)b;
}

int main(){
	int i,j,k,n,m,s[1000],q,c,t=0,min;
	while(scanf("%d",&n)!=EOF&&n){
		for(i=0;i<n;++i)
			scanf("%d",&s[i]);
		scanf("%d",&m);
		qsort(s, n, sizeof(int), cmp);
		printf("Case %d:\n",++t);
		for(i=0;i<m;++i){
			scanf("%d",&q);
			min=16777215;
			for(j=0;j<n;++j)
				for(k=j+1;k<n;++k){
					if(abs(s[j]+s[k]-q)<=min){
						min=abs(s[j]+s[k]-q);
						c=s[j]+s[k];
					}
					if(s[j]+s[k]-q>=min)
						break;
				}
			printf("Closest sum to %d is %d.\n",q,c);
		}
	}
	return 0;
}
