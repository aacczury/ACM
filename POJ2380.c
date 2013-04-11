#include <stdio.h>

int cmp(const void *a, const void *b){
	if(*((long long *)a+1)==*((long long *)b+1))return *(long long *)a-*(long long *)b;
	return *((long long *)a+1)-*((long long *)b+1);
}

int cmpq(const void *a, const void *b){
	return *(long long *)a-*(long long *)b;
}


long long sale[500001][3];
long long q[500001];
int main(){
	long long s,v;
	int n,i,j,qm;
	while(scanf("%d",&n)!=EOF){
		qm=0;
		for(i=0;i<n;i++){
			scanf("%d%d%d",&sale[i][0],&sale[i][1],&sale[i][2]);
			for(j=0;j<qm;j++)
				if(sale[i][0]==q[j])
					break;
			if(j==qm){
				q[j]=sale[i][0];
				qm=j+1;
			}
		}
		
		qsort(q, qm, sizeof(long long), cmpq);
		qsort(sale, n, sizeof(long long)*3, cmp);
		printf("-1");
		for(i=0;i<qm;i++)
			printf(" %lld",q[i]);
		j=qm;
		v=0;
		for(i=0;i<n;i++){
			if(j==qm){
				s=sale[i][1];
				printf("\n%lld",sale[i][1]);
				j=0;
			}
			if(sale[i][0]==q[j]&&sale[i][1]==s)
				v+=sale[i][2];
			else{
				printf("% lld",v);
				v=0;
				j++;
				i--;
			}
		}
		if(j!=qm)
			printf("% lld",v);
		j++;
		for(;j<qm;j++)
			printf(" 0");
	}
	return 0;
}
