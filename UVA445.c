#include <stdio.h>

int main(){
	char c[150];
	int i,j,n;
	while(gets(c)){
		n=0;
		for(i=0;c[i]!='\0';i++){
			if(c[i]<60&&c[i]>47)
				n+=c[i]-48;
			else if(c[i]=='b')
				while(n){
					n--;
					printf(" ");
				}
			else if(c[i]=='!')
				printf("\n");
			else
				while(n){
					n--;
					printf("%c",c[i]);
				}
		}
		printf("\n");
	}
	return 0;
}
