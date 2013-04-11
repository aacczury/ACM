#include <stdio.h>

int main(){
	char c[8][8];
	char a[65];
	int i,j;
	while(scanf("%s",a)!=EOF){
		for(i=0;i<8;i++)
			for(j=0;j<8;j++)
				c[i][j]=0;
		scanf("%s",&a);
		for(i=0;a[i]!='\0';){
			if(i)
				i++;
			if(a[i]<91){
				c[8-a[i+2]+48][a[i+1]-97]=a[i];
				i+=3;
			}
			else{
				c[8-a[i+1]+48][a[i]-97]='P';
				i+=2;
			}
		}
		scanf("%s",a);
		scanf("%s",a);
		for(i=0;a[i]!='\0';){
			if(i)
				i++;
			if(a[i]<91){
				c[8-a[i+2]+48][a[i+1]-97]=a[i]+32;
				i+=3;
			}
			else{
				c[8-a[i+1]+48][a[i]-97]='p';
				i+=2;
			}
		}
		printf("+---+---+---+---+---+---+---+---+\n");
		for(i=0;i<8;i++){
			for(j=0;j<8;j++){
				if((i+j)%2==0)
					if(c[i][j]!=0)
						printf("|.%c.",c[i][j]);
					else
						printf("|...");
				else
					if(c[i][j]!=0)
						printf("|:%c:",c[i][j]);
					else
						printf("|:::");
			}
			printf("|\n+---+---+---+---+---+---+---+---+\n");
		}
	}
}
