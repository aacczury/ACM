#include <stdio.h>

int fd(int m,int n){
	if(m<=1||n<=1)
		return 1;
	if(n>m)
		n=m;
	return fd(m,n-1)+fd(m-n,n);
	
}


int main(){
	int t,m,n,a;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&m,&n);
		a=fd(m,n);
		printf("%d\n",a);
	}
}
