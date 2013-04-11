#include <stdio.h>
#include <math.h>

int main(){
	int i,n,b[100000];
	long long cost;
	while(scanf("%d",&n)!=EOF&&n){
		cost=0;
		for(i=0;i<n;i++)
			scanf("%d",&b[i]);
		for(i=1;i<n;i++){
			b[i]+=b[i-1];
			cost+=abs(b[i-1]);
		}
		printf("%lld\n",cost);
	}
	return 0;
}
