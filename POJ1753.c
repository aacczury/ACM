#include <stdio.h>

int turn(int a,int i,int j){
	a^=1<<(i*4+j);
	if(i>0)
		a^=1<<((i-1)*4+j);
	if(j>0)
		a^=1<<(i*4+j-1);
	if(i<3)
		a^=1<<((i+1)*4+j);
	if(j<3)
		a^=1<<(i*4+j+1);
	return a;
}

int findmin(int a,int n,int count){
	int min=100000,temp=100000;
	
	if(!a||a==65535)return count;
	if(n<15)temp=findmin(a,n+1,count);
	if(temp<min)min=temp;
	
	if(count+1>=min)return min;
	
	a=turn(a,n/4,n%4);
	
	if(!a||a==65535)return count+1;
	if(n<15)temp=findmin(a,n+1,count+1);
	if(temp<min)min=temp;
	
	return min;
}

int main(){
	int a;
	char c[4][5];
	int i,j,min;
	while(scanf("%s%s%s%s",c[0],c[1],c[2],c[3])!=EOF){
		a=0;
		for(i=0;i<4;i++)
			for(j=0;j<4;j++)
				if(c[i][j]=='b')
					a^=1<<(i*4+j);
		min=findmin(a,0,0);
		if(min!=100000)
			printf("%d\n",min);
		else
			printf("Impossible\n");
	}
}
