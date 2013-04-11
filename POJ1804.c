#include <stdio.h>

int main(){
	int s[1000],count,i,j,k,c,n;
	scanf("%d",&c);
	for(k=0;k<c;k++){
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&s[i]);
		count=0;
		for(i=0;i<n;i++)
			for(j=i+1;j<n;j++)
				if(s[i]>s[j])
					count++;
		printf("Scenario #%d:\n%d\n\n",k+1,count);
	}
}
