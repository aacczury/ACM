#include <stdio.h>

int main(){
	int i,j,l,max,result;
	int al[15];
	char c[26];
	while(scanf("%d\n",&l)!=EOF){
		if(!l)
			break;
		max=0;
		result=0;
		for(i=0;i<15;i++)
			al[i]=0;
		for(i=0;i<l;i++){
			gets(c);
			for(j=0;j<25;j++)
				if(c[j]=='X')
					al[i]++;
		}
		for(i=0;i<l;i++)
			if(al[i]>max)
				max=al[i];
		for(i=0;i<l;i++)
			result+=(max-al[i]);
		printf("%d\n",result);
	}
	return 0;
}
