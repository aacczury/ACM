#include <stdio.h>
#include <math.h>

int main(){
	double l,n,c,b,e,m,ll;
	while(scanf("%lf%lf%lf",&l,&n,&c)!=EOF){
		if(l==-1&&n==-1&&c==-1)break;
		if(l==0||n==0||c==0){
			printf("0.000\n");
			continue;
		}
		ll=(1+n*c)*l;
		b=0;
		e=acos(-1.0)/2.0;
		while(1){
			m=(b+e)/2.0;
			if(fabs(m*l-ll*sin(m))<0.00001*sin(m))break;
			if(m*l>ll*sin(m))e=m;
			else b=m;
		}
		printf("%.3lf\n",ll*(1-cos(m))/(2*m));
	}
	return 0;
}
