#include <stdio.h>
int prime[1000000];

int main(){
	int a,d,n,i,j;
	for(i=0;i<1000000;i++)
		prime[i]=1;
	for(i=2;i<=1000;i++){
		for(j=2;i*j<1000000;j++)
			prime[i*j]=0;
	}
	prime[0]=0;
	prime[1]=0;
	while(scanf("%d%d%d",&a,&d,&n)!=EOF){
		if(a==0&&d==0&&n==0)
			break;
		a-=d;
		while(n){
			a+=d;
			if(prime[a]==1)
				n--;
		}
		printf("%d\n",a);
	}
}
