#include <stdio.h>

int main(){
	int money[100000],n,m,i,left,right,mid,count,max,sum;
	while(scanf("%d%d",&n,&m)!=EOF){
		max=0;
		sum=0;
		for(i=0;i<n;i++){
			scanf("%d",&money[i]);
			if(money[i]>max)
				max=money[i];
			sum+=money[i];
		}
		left=max;
		right=sum;
		while(left!=right){
			mid=(left+right)/2;
			count=0;
			sum=0;
			for(i=0;i<n;i++){
				sum+=money[i];
				if(sum>mid){
					sum=money[i];
					count++;
				}
			}
			if(sum>0)
				count++;
			if(count<=m)
				right=mid;
			else
				left=mid+1;
		}
		printf("%d\n",right);
	}
	return 0;
}
