#include <stdio.h>

int main(){
	char c[256];
	int a,i;
	while(gets(c)){
		if(c[0]=='#')
			break;
		a=0;
		for(i=0;c[i]!='\0';i++)
			if(c[i]!=32)
				a+=(i+1)*(c[i]-64);
		printf("%d\n",a);
	}
}
