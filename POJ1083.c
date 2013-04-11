#include <stdio.h>

int main(){
	int m,n,t[200],i,j,l,x,y,max;
	while(scanf("%d",&l)!=EOF){
		for(m=0;m<l;m++){
			max=0;
			scanf("%d",&n);
			for(i=0;i<200;i++)
				t[i]=0;
			for(i=0;i<n;i++){
				scanf("%d%d",&x,&y);
				if(y<x){
					x=x^y;y=x^y;x=x^y; //exchange x,y or (x=x+y; y=x-y; x=x-y;)
				}
				x=(x-1)/2;
				y=(y-1)/2;
				for(j=x;j<=y;j++)
					t[j]++;
			}
			for(i=0;i<200;i++)
				if(t[i]>max)
					max=t[i];
			printf("%d\n",max*10);
		}
	}
}
