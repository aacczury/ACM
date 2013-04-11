#include <stdio.h>

int main(){
	char s[100001],t[100001];
	int i,j;
	while(scanf("%s %s",s,t)!=EOF){
		for(i=0,j=0;s[i]!='\0'&&t[j]!='\0';){
			if(s[i]==t[j]){
				i++;
				j++;
			}
			else
				j++;
		}
		if(s[i]=='\0')
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
