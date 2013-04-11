#include <stdio.h>

int main(){
	char c[1000];
	int i;
	while(gets(c)){
		for(i=0;c[i]!='\0';i++)c[i]-=7;
		printf("%s\n",c);
	}
	return 0;
}
