#include <stdio.h>

int main(){
	int i,k,p,q,x,y,r;
	int l,n,m,a,b;
	int robot[100][3];
	int ma[100][100];
	int oo;
	char f;
	while(scanf("%d",&l)!=EOF){
		for(k=0;k<l;k++){
			for(a=0;a<100;a++)
				for(b=0;b<100;b++)
					ma[a][b]=0;
			oo=0;
			scanf("%d%d",&a,&b);
			scanf("%d%d",&n,&m);
			for(p=0;p<n;p++){
				scanf("%d%d %c",&x,&y,&f);
				robot[p][0]=x;
				robot[p][1]=y;
				ma[robot[p][0]-1][robot[p][1]-1]=p+1;
				switch(f){
					case 'N':robot[p][2]=0;break;
					case 'E':robot[p][2]=1;break;
					case 'S':robot[p][2]=2;break;
					case 'W':robot[p][2]=3;break;
				}
			}
			for(p=0;p<m;p++){
				scanf("%d %c%d",&q,&f,&r);
				if(oo)
					continue;
				if(f=='F')
					while(r--){
						ma[robot[q-1][0]-1][robot[q-1][1]-1]=0;
						switch(robot[q-1][2]){
							case 0:robot[q-1][1]++;break;
							case 1:robot[q-1][0]++;break;
							case 2:robot[q-1][1]--;break;
							case 3:robot[q-1][0]--;break;
						}
						if(robot[q-1][0]<1||robot[q-1][0]>a||robot[q-1][1]<1||robot[q-1][1]>b){
							printf("Robot %d crashes into the wall\n",q);
							oo=1;
							break;
						}
						else if(ma[robot[q-1][0]-1][robot[q-1][1]-1]!=0){
							printf("Robot %d crashes into robot %d\n",q,ma[robot[q-1][0]-1][robot[q-1][1]-1]);
							oo=1;
							break;
						}
						ma[robot[q-1][0]-1][robot[q-1][1]-1]=q;
					}
				else if(f=='L')
					while(r--)
						robot[q-1][2]=(robot[q-1][2]+3)%4;
				else
					while(r--)
						robot[q-1][2]=(robot[q-1][2]+1)%4;
			}
			if(!oo)
				printf("OK\n");
		}
	}
}
