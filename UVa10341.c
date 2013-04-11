#include <stdio.h>
#include <math.h>

int p,q,r,s,t,u;

double f(double x){
	return p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u;
}

int main(){
	int i;
	double left,right,mid;
	while(scanf("%d%d%d%d%d%d",&p,&q,&r,&s,&t,&u)!=EOF){
		left=0.0;
		right=1.0;
		for(i=0;i<100;++i){
			mid=(left+right)/2;
			if(f(mid)>0)
				left=mid;
			else
				right=mid;
		}
		if(fabs(f(mid)-0.0)<0.00000001)
			printf("%.4lf\n",mid);
		else
			printf("No solution\n");
	}
	return 0;
}
