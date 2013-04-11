#include <stdio.h>

int cmp(const void *a, const void *b){
	if(*((int *)a+1)==*((int *)b+1))return *(int *)a-*(int *)b;
	return *((int *)b+1)-*((int *)a+1);
}


int main(){
	int n,m,player[10000][2],tmp,i,j,mp,second;
	while(scanf("%d%d",&n,&m)!=EOF){
		if(!n&&!m)
			break;
		mp=0;
		player[0][0]=-1;
		for(i=0;i<n*m;i++){
			scanf("%d",&tmp);
			for(j=0;j<mp;j++)
				if(player[j][0]==tmp)
					break;
			if(j!=mp)
				player[j][1]++;
			else{
				player[j][1]=0;
				player[j][0]=tmp;
				mp++;
			}
		}
		qsort(player, mp, sizeof(int)*2, cmp);
		for(i=1;i<mp&&player[i][1]==player[1][1];i++)
			printf("%d ",player[i][0]);
		printf("\n");
	}
	return 0;
}
