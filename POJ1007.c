#include <stdio.h>

int cmp(const void *a, const void *b){
	return *(int *)a-*(int *)b;
}

typedef struct{
	int w;
	char seq[51];
}dna;

int main(){
	dna alldna[100];
	int n,m,i,j,k;
	while(scanf("%d%d",&n,&m)!=EOF){
		gets(alldna[0].seq);
		for(i=0;i<m;i++){
			gets(alldna[i].seq);
			alldna[i].w=0;
			for(j=0;j<n;j++)
				for(k=j+1;k<n;k++)
					if(alldna[i].seq[j]>alldna[i].seq[k])
						alldna[i].w++;
		}
		qsort(alldna, m, sizeof(dna), cmp);
		for(i=0;i<m;i++)
			printf("%s\n",alldna[i].seq);
	}
	return 0;
}
