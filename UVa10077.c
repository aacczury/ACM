#include <stdio.h>

int main(){
	int m,n,la,lb,ra,rb;
	while(scanf("%d%d",&m,&n)){
		if(m==1&&n==1)break;
		la=0;
		lb=1;
		ra=1;
		rb=0;
		while(m!=(la+ra)||n!=(lb+rb)){
			if(m*(lb+rb)<n*(la+ra)){
				printf("L");
				ra=la+ra;
				rb=lb+rb;
			}
			else{
				printf("R");
				la=la+ra;
				lb=lb+rb;
			}
		}
		printf("\n");
	}
	return 0;
}
