#include <stdio.h>

int main(){
	int n,f,c,i,count;
	int ri[10000];
	double sum,left,right,mid;
	scanf("%d",&c);
	while(c--){
		scanf("%d%d",&n,&f);
		sum=0;
		for(i=0;i<n;i++){
			scanf("%d",&ri[i]);
			ri[i]*=ri[i];
			sum+=ri[i];
		}
		left=0;
		right=sum/(f+1);
		while(right-left>0.0000001){
			count=0;
			mid=(left+right)/2;
			for(i=0;i<n;i++)
				count+=(ri[i]/mid);
			if(count>=f+1)
				left=mid;
			else
				right=mid;
		}
		printf("%.4lf\n",mid*3.1415926535897);
	}
	return 0;
}
