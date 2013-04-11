#include <stdio.h>

int num(int n){
	int count=1;
	while(n!=1){
		if(n%2==1)
			n=3*n+1;
		else
			n=n/2;
		count++;
	}
	return count;
}

int main(){
	int a,b,i,max,result;
	while(scanf("%d%d",&a,&b)!=EOF){
		printf("%d %d ",a,b);
		if(b<a){
			a=a^b;b=a^b;a=a^b; //exchange a,b
		}
		max=0;
		for(i=a;i<=b;i++){
			result=num(i);
			if(max<result)
				max=result;
		}
		printf("%d\n",max);
	}
}
