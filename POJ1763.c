#include <stdio.h>
#include <stdlib.h> 

int cmpx(const void *a, const void *b){
	if(*(int *)a==*(int *)b)return *((int *)a+1)-*((int *)b+1);
	return *(int *)a-*(int *)b;
}

int cmpy(const void *a, const void *b){
	if(*((int *)a+1)==*((int *)b+1))return *(int *)a-*(int *)b;
	return *((int *)a+1)-*((int *)b+1);
}

int point[250001][3];
int main(){
	int n,i,min,beg,end,tb,te,tm;
	char dir,ad;
	while(scanf("%d",&n)!=EOF){
		min=300000;
		point[0][0]=0;
		point[0][1]=0;
		point[0][2]=0;
		scanf("%c",&dir);
		for(i=0;i<n;i++){
			scanf("%c",&dir);
			switch(dir){
				case 'N':point[i+1][1]=point[i][1]+1;point[i+1][0]=point[i][0];point[i+1][2]=i+1;break;
				case 'E':point[i+1][0]=point[i][0]+1;point[i+1][1]=point[i][1];point[i+1][2]=i+1;break;
				case 'S':point[i+1][1]=point[i][1]-1;point[i+1][0]=point[i][0];point[i+1][2]=i+1;break;
				case 'W':point[i+1][0]=point[i][0]-1;point[i+1][1]=point[i][1];point[i+1][2]=i+1;break;
			}
		}
		qsort(point, n+1, sizeof(int)*3, cmpx);
		for(i=0;i<n;i++){
			if(point[i][0]==point[i+1][0]){
				if(abs(point[i][2]-point[i+1][2])>1){
					if(point[i][2]>point[i+1][2]){
						tb=point[i+1][2];
						te=point[i][2];
					}
					else{
						tb=point[i][2];
						te=point[i+1][2];
					}
					tm=abs(point[i][1]-point[i+1][1]);
					if( min>tm || min==tm&&beg>tb || min==tm&&beg==tb&&end<te ){
						min=tm;
						beg=tb;
						end=te;
						if(point[i+1][2]<point[i][2]&&point[i+1][1]>point[i][1]||point[i+1][2]>point[i][2]&&point[i+1][1]<point[i][1])
							ad='S';
						else
							ad='N';
					}
				}
			}
		}
		qsort(point, n+1, sizeof(int)*3, cmpy);
		for(i=0;i<n;i++){
			if(point[i][1]==point[i+1][1]){
				if(abs(point[i][2]-point[i+1][2])>1){
					if(point[i][2]>point[i+1][2]){
						tb=point[i+1][2];
						te=point[i][2];
					}
					else{
						tb=point[i][2];
						te=point[i+1][2];
					}
					tm=abs(point[i][0]-point[i+1][0]);
					if( min>tm || min==tm&&beg>tb || min==tm&&beg==tb&&end<te ){
						min=tm;
						beg=tb;
						end=te;
						if(point[i+1][2]<point[i][2]&&point[i+1][0]>point[i][0]||point[i+1][2]>point[i][2]&&point[i+1][0]<point[i][0])
							ad='W';
						else
							ad='E';
					}
				}
			}
		}
		printf("%d %d %d %c\n",min,beg,end,ad);
	}
	return 0;
}
