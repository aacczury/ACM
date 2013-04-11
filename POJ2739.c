#include <stdio.h>
int main(){
	int prime[10010],l[2000];
	int i,j,k,n,sum,count;
	for(i=0;i<10010;i++)
		prime[i]=1;
	for(i=2;i*i<=10010;i++){
		for(j=2;i*j<10010;j++)
			prime[i*j]=0;
	}
	j=0;
	for(i=2;i<10010;i++)
		if(prime[i])
			l[j++]=i;
	while(scanf("%d",&n)!=EOF){
		if(n==0)
			break;
		count=0;
		for(i=0;i<j&&l[i]<=n;i++){
			sum=0;
			for(k=i;k<=n&&sum<n;k++){
				sum+=l[k];
				if(sum==n){
					count++;
					break;
				}
			}
		}
		printf("%d\n",count);
	}
}
