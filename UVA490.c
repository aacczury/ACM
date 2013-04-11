#include <stdio.h>

int main(){
	int i,j,n=0,maxl=0;
	char sen[100][100];
	for(i=0;i<100;i++)
		for(j=0;j<100;j++)
			sen[i][j]=32;
	while(gets(sen[n])){
		for(i=0;sen[n][i]!='\0';i++);
		sen[n][i]=32;
		if(i>maxl)
			maxl=i;
		n++;
	}
	for(j=0;j<maxl;j++){
		for(i=n-1;i>=0;i--)
			printf("%c",sen[i][j]);
		printf("\n");
	}
	return 0;
}
