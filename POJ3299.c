#include <stdio.h>
#include <math.h>
int main(){
	float e,h,H,T,D;
	char c,d;
	float a,b;
	while(scanf("%c%f %c%f\n",&c,&a,&d,&b)!=EOF){
		if(c=='E')
			break;
		H=0;
		T=0;
		D=0;
		switch(c){
			case 'H':H=a;break;
			case 'T':T=a;break;
			case 'D':D=a;break;
		}
		switch(d){
			case 'H':H=b;break;
			case 'T':T=b;break;
			case 'D':D=b;break;
		}
		if(H==0){
			e=6.11*exp(5417.7530*((1/273.16)-(1/(D+273.16))));
			h=(0.5555)*(e-10.0);
			H=T+h;
		}
		else if(T==0){
			e=6.11*exp(5417.7530*((1/273.16)-(1/(D+273.16))));
			h=(0.5555)*(e-10.0);
			T=H-h;
		}
		else{
			h=H-T;
			e=h/0.5555+10.0;
			D=1/(1/273.16-log(e/6.11)/5417.7530)-273.16;
		}
		printf("T %.1f D %.1f H %.1f\n",T,D,H);
	}
}
