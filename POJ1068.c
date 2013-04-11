#include <stdio.h>

int main(){
	int l,n,p[20],t[20],i,j,k,m;
	while(scanf("%d",&l)!=EOF){
		for(m=0;m<l;m++){
			scanf("%d",&n);
			for(i=0;i<n;i++){
				scanf("%d",&p[i]);
				if(i==0||p[i]!=p[i-1]){
					if(i==0)
						printf("%d",1);
					else
						printf(" %d",1);
					t[i]=p[i]-1;
				}
				else
					for(j=1;j<=p[i];j++){
						k=0;
						while(k<i&&(p[i]-j)!=t[k])k++;
						if(k==i){
							printf(" %d",j);
							t[i]=p[i]-j;
							break;
						}
					}
			}
			printf("\n");
		}
	}
}
