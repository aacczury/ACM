#include <stdio.h>

int main(){
	char c;
	int a=0,b=0;
	while((c=getchar())!=EOF){
		if(c>47)
			b+=c-48;
		else if(c==32){
			a=b;
			b=0;
		}
		else if(c=='\n'){
			printf("%d\n",a*b);
			a=0;
			b=0;
		}
	}
}
