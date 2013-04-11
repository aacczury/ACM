#include <stdio.h>

int main(){
	int a[26],b[26],i,j=0;
	char c[150],d[150];
	while(scanf("%s%s",c,d)!=EOF){
		for(i=0;i<26;i++){
			a[i]=0;
			b[i]=0;
		}
		for(i=0;c[i]!='\0';i++){
			a[c[i]-65]++;
			b[d[i]-65]++;
		}
		for(i=0;i<26;i++){
			if(a[i]!=0)
				for(j=0;j<26;j++)
					if(a[i]==b[j]){
						b[j]=0;
						break;
					}
			if(j==26)
				break;
		}
		if(j!=26)
			printf("YES\n");
		else
			printf("NO\n");
	}
}
