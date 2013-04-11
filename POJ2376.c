#include <stdio.h>

int cmp(const void *a, const void *b){
	if(*(int *)a==*(int *)b)return *((int *)b+1)-*((int *)a+1);
	return *(int *)a-*(int *)b;
}


int cow[25001][2];
int main(){
	int n,t,i,flag,max,count;
	while(scanf("%d%d",&n,&t)!=EOF){
		flag=0;
		max=0;
		count=0;
		for(i=0;i<n;i++)
			scanf("%d%d",&cow[i][0],&cow[i][1]);
		qsort(cow, n, sizeof(int)*2, cmp);
		for(i=0;i<n;i++){
			if(cow[i][0]<=flag+1)
				if(max<cow[i][1])
					max=cow[i][1];
			if(cow[i][0]>flag||i==n-1){
				if(flag==max)
					break;
				flag=max;
				count++;
				i--;
			}
		}
		if(max<t)
			count=-1;
		printf("%d\n",count);
	}
	return 0;
}
