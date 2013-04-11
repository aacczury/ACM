#include <stdio.h>
int prime[1000000];

int main(){
	int i,j,n;
	for(i=0;i<1000000;i++)
		prime[i]=1;
	for(i=2;i<=1000;i++){
		for(j=2;i*j<1000000;j++)
			prime[i*j]=0;
	}
	while(scanf("%d",&n)!=EOF){
		if(n==0)
			break;
		for(i=2;i<=500000;i++)
			if(prime[i]&&prime[n-i])
				break;
		printf("%d = %d + %d\n",n,i,n-i);
	}
}
