#include <stdio.h>

int cmp(const void *a, const void *b){
	return *(int *)a-*(int *)b;
}

int main(){
	int pos[100000],n,c,i,left,right,mid,sum,count,j;
	while(scanf("%d%d",&n,&c)!=EOF){
		for(i=0;i<n;i++)
			scanf("%d",&pos[i]);
		qsort(pos, n, sizeof(int), cmp);
		left=0;
		right=pos[n-1]-pos[0];
		while(left!=right){
			mid=(left+right+1)/2;
			j=0;
			count=1;
			for(i=1;i<n;i++)
				if(pos[i]-pos[j]>=mid){
					j=i;
					count++;
				}
			if(count>=c)
				left=mid;
			else
				right=mid-1;
		}
		printf("%d\n",right);
	}
	return 0;
}
