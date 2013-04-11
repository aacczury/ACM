#include <stdio.h>

int main(){
	long long a=0,b,i,count,n;
	while(scanf("%lld%lld",&n,&b)!=EOF){
		if(n==-1&&b==-1)
			break;
		a++;
		i=n;
		count=1;
		while(n!=1){
			if(n%2==1)
				n=3*n+1;
			else
				n=n/2;
			if(n>b)
				break;
			count++;
		}
		printf("Case %lld: A = %lld, limit = %lld, number of terms = %lld\n",a,i,b,count);
	}
	return 0;
}
