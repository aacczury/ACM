#include <stdio.h>
int m[200][200],color[200],n;

int DFS(int p){
	int i,result=1;
	for(i=p+1;i<n;i++)
		if(m[p][i]){
			if(!color[i])
				color[i]=color[p]%2+1;
			else if(color[i]==color[p])
				return 0;
			result=DFS(i);
		}
	return result;
}

int main(){
	int l,i,j,p,q,not;
	while(scanf("%d",&n)!=EOF&&n){
		scanf("%d",&l);
		for(i=0;i<200;i++)
			for(j=0;j<200;j++)
				m[i][j]=0;
		for(i=0;i<200;i++)
			color[i]=0;
		not=0;
		for(i=0;i<l;i++){
			scanf("%d%d",&p,&q);
			m[p][q]=1;
			m[q][p]=1;
		}
		color[0]=1;
		if(DFS(0))
			printf("BICOLORABLE.\n");
		else
			printf("NOT BICOLORABLE.\n");
	}
	return 0;
}
