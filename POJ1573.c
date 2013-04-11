#include <stdio.h>

int main(){
	char map[10][11];
	int hmap[10][10];
	int i,j,m,n,s,c,l;
	while(scanf("%d%d%d",&m,&n,&s)!=EOF){
		if(m==0&&n==0&&s==0)break;
		for(i=0;i<m;i++){
			scanf("%s",map[i]);
			for(j=0;j<n;j++){
				hmap[i][j]=0;
			}
		}
		i=0;j=s-1;c=0;l=0;
		while(i>=0&&j>=0&&i<m&&j<n){
			if(hmap[i][j]!=0){
				l=c-hmap[i][j]+1;
				c=hmap[i][j]-1;
				break;
			}
			c++;
			hmap[i][j]=c;
			switch(map[i][j]){
				case 'N':i--;break;
				case 'S':i++;break;
				case 'W':j--;break;
				case 'E':j++;break;
			}
		}
		if(l==0)
			printf("%d step(s) to exit\n",c);
		else
			printf("%d step(s) before a loop of %d step(s)\n",c,l);
	}
}
