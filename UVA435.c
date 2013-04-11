#include <stdio.h>

int main(){
	char c[100000];
	int count,i;
	while(gets(c)){
		count=0;
		for(i=0;c[i]!='\0';i++)
			if(c[i]>64&&c[i]<91||c[i]>96&&c[i]<123){
				while(c[i]>64&&c[i]<91||c[i]>96&&c[i]<123)i++;
				count++;
			}
		printf("%d\n",count);
	}
	return 0;
}
