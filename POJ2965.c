#include <stdio.h>

int turn(int a,int i,int j){
	int k;
	a^=1<<(i*4+j);
	for(k=0;k<4;k++){
		a^=1<<(i*4+k);
		a^=1<<(k*4+j);
	}
	return a;
}

int min;

int findmin(int a,int b,int n,int count){
	int temp;
	
	if(!a){
		if(count<min){
			min=count;
			return b;
		}
		else
			return 100000;
	}

	if(n<15){
		temp=findmin(a,b,n+1,count);
		if(temp!=100000)
			return temp;
	}
	
	if(count+1>=min)return 100000;
	
	a=turn(a,n/4,n%4);
	b^=1<<(n/4*4+n%4);
	
	if(!a){
		if(count+1<min){
			min=count+1;
			return b;
		}
		else
			return 100000;
	}

	if(n<15){
		temp=findmin(a,b,n+1,count+1);
		if(temp!=100000)
			return temp;
	}
	
	return 100000;
}

int main(){
	int a,b;
	char c[4][5];
	int i,j;
	while(scanf("%s%s%s%s",c[0],c[1],c[2],c[3])!=EOF){
		a=0;b=0;min=100000;
		for(i=0;i<4;i++)
			for(j=0;j<4;j++)
				if(c[i][j]=='+')
					a^=1<<(i*4+j);
		b=findmin(a,b,0,0);
		printf("%d\n",min);
		for(i=0;i<16;i++){
			if(b>>i&1==1)
				printf("%d %d\n",i/4+1,i%4+1);
		}
	}
}
