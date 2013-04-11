#include <stdio.h>

int n;
int img[25][25];
int count;

void gp(int i,int j){
	int dir[8][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
	int k;
	if(img[i][j]==1){
		img[i][j]=count;
		for(k=0;k<8;k++)
			if((i+dir[k][0])>=0&&(j+dir[k][1])>=0&&(i+dir[k][0])<n&&(j+dir[k][1])<n)
				gp(i+dir[k][0],j+dir[k][1]);
	}
}

int main(){
	int i,j,cc=0;
	char c[30];
	while(scanf("%d",&n)!=EOF){
		cc++;
		count=1;
		getchar();
		for(i=0;i<n;i++){
			gets(c);
			for(j=0;j<n;j++)
				img[i][j]=c[j]-48;
		}
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				if(img[i][j]==1){
					count++;
					gp(i,j);
				}
		printf("Image number %d contains %d war eagles.\n",cc,count-1);
	}
	return 0;
}
