#include <stdio.h>
#include <string.h>

int main(){
	char c[150];
	int a[150];
	int i,len;
	memset(a,0,sizeof(a));
	while(scanf("%s",&c)){
		len=strlen(c);
		if(c[0]==48&&len==1)break;
		for(i=1;i<=len;i++)
			a[150-i]+=c[len-i]-48;
	}
	for(i=149;i>=0;i--){
		a[i-1]+=a[i]/10;
		a[i]%=10;
	}
	i=0;
	while(a[i]==0)i++;
	for(;i<150;i++)
		printf("%d",a[i]);
	printf("\n");
}
