#include <stdio.h>

int cmp(const void *a, const void *b){
	return *(int *)b-*(int *)a;
}


int main(){
	int t,m,n,k,tmp,mw,i,j,time,total;
	int w[2500][3];
	scanf("%d",&t);
	while(t--){
		mw=0;
		time=0;
		total=0;
		scanf("%d%d%d",&m,&n,&k);
		for(i=0;i<m;i++)
			for(j=0;j<n;j++){
				scanf("%d",&tmp);
				if(tmp){
					w[mw][0]=tmp;
					w[mw][1]=j;
					w[mw][2]=i;
					mw++;
				}
			}
		qsort(w, mw, sizeof(int)*3, cmp);
		for(i=0;i<mw;i++){
			if(!i){
				if((w[i][2]+1)*2+1>k)
					break;
				time+=w[i][2]+2;
			}
			else {
				if((time+abs(w[i][1]-w[i-1][1])+abs(w[i][2]-w[i-1][2])+w[i][2]+2)<=k)
					time+=abs(w[i][1]-w[i-1][1])+abs(w[i][2]-w[i-1][2])+1;
				else
					break;
			}
			total+=w[i][0];
		}
		printf("%d\n",total);
	}
	return 0;
}
