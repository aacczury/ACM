#include <stdio.h>

int cmp(const void *a, const void *b){
	return *(int *)a-*(int *)b;
}

int main(){
	int pos[50002],l,n,m,i,j,left,right,mid,count;
	while(scanf("%d%d%d",&l,&n,&m)!=EOF){
		pos[0]=0;
		pos[n+1]=l;
		for(i=1;i<=n;i++)
			scanf("%d",&pos[i]);
		qsort(pos, n+2, sizeof(int), cmp);
		left=0;
		right=l;
		while(left!=right){
			mid=(left+right+1)/2;
			j=0;
			count=1;
			for(i=1;i<=n+1;i++)
				if(pos[i]-pos[j]>=mid){
					j=i;
					count++;
				}
			if(count>=n-m+2)
				left=mid;
			else
				right=mid-1;
		}
		printf("%d\n",right);
	}
	return 0;
}
