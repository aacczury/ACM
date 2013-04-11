#include <stdio.h>

int main(){
	int a,b,n[50],i,j;
	while(scanf("%d%d",&a,&b)!=EOF){
		i=0;
		while(a%b){
			n[i++]=a/b;
			a^=b;
			b=a^b;
			b%=a^=b;
		}
		n[i++]=a/b;
		printf("[");
		for(j=0;j<i;j++)
			if(!j)
				printf("%d;",n[j]);
			else if(j==1)
				printf("%d",n[j]);
			else
				printf(",%d",n[j]);
		printf("]\n");
	}
	return 0;
}
