#include <stdio.h>

int m[50][50];
int a[2500][2];
int x,y;
int dir[4][2]={{-1,0},{0,-1},{0,1},{1,0}};
int count;

int cmp(const void *a, const void *b){
	if(*((int *)a+1)==*((int *)b+1))return *(int *)a-*(int *)b;
	return *((int *)b+1)-*((int *)a+1);
}

void gp(int i,int j){
	int k;
	if(m[i][j]>=0){
		if(a[count][0]==-1)
			a[count][0]=m[i][j];
		else if(a[count][0]!=m[i][j])
			return ;
		a[count][1]++;
		m[i][j]=-2;
		for(k=0;k<4;k++)
			if((i+dir[k][0])>=0&&(j+dir[k][1])>=0&&(i+dir[k][0])<x&&(j+dir[k][1])<y)
				gp(i+dir[k][0],j+dir[k][1]);
	}
}

int main(){
	int i,j,t=0;
	char c;
	while(scanf("%d%d",&x,&y)!=EOF){
		if(!x&&!y)
			break;
		for(i=0;i<2500;i++){
			a[i][0]=-1;
			a[i][1]=0;
		}
		for(i=0;i<x;i++){
			scanf("%c",&c);
			for(j=0;j<y;j++){
				scanf("%c",&c);
				m[i][j]=c-65;
			}
		}
		count=0;
		for(i=0;i<x;i++)
			for(j=0;j<y;j++){
				gp(i,j);
				if(a[count][0]!=-1)
					count++;
			}
		qsort(a, count, sizeof(int)*2, cmp);
		printf("Problem %d:\n",++t);
		for(i=0;i<count;i++)
			printf("%c %d\n",a[i][0]+65,a[i][1]);
	}
	return 0;
}
