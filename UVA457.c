#include <stdio.h>

int main(){
	int DNA[10];
	int dish[40];
	int temp[40];
	int i,j,b,k;
	while(scanf("%d",&b)!=EOF){
		for(k=0;k<b;k++){
			if(k)
				printf("\n");
			for(i=0;i<40;i++)
				dish[i]=0;
			dish[19]=1;
			for(i=0;i<10;i++)
				scanf("%d",&DNA[i]);
			for(i=0;i<50;i++){
				for(j=0;j<40;j++)
					if(j==0)
						temp[j]=DNA[dish[j]+dish[j+1]];
					else if(j==39)
						temp[j]=DNA[dish[j-1]+dish[j]];
					else
						temp[j]=DNA[dish[j-1]+dish[j]+dish[j+1]];
				for(j=0;j<40;j++){
					switch(dish[j]){
						case 0:printf(" ");break;
						case 1:printf(".");break;
						case 2:printf("x");break;
						case 3:printf("W");break;
					}
					dish[j]=temp[j];
				}
				printf("\n");
			}
		}
	}
	return 0;
}
