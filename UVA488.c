#include <stdio.h>

int main(){
	int c,h,f;
	int i,j,k,l;
	while(scanf("%d",&c)!=EOF)
		for(i=0;i<c;i++){
			scanf("%d%d",&h,&f);
			if(i)
				printf("\n");
			for(j=0;j<f;j++){
				if(j)
					printf("\n");
				for(k=1;k<=h;k++){
					for(l=0;l<k;l++)
						printf("%d",k);
					printf("\n");
				}
				for(k=h-1;k>0;k--){
					for(l=0;l<k;l++)
						printf("%d",k);
					printf("\n");
				}
			}
		}
	return 0;
}
