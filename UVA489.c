#include <stdio.h>


int main(){
	int key[26],n,wrong[26],i,allwrong,allright;
	char a[1000],b[1000];
	while(scanf("%d",&n)!=EOF){
		if(n==-1)
			break;
		for(i=0;i<26;i++){
			key[i]=0;
			wrong[i]=0;
		}
		allwrong=0;
		allright=0;
		scanf("%s",a);
		scanf("%s",b);
		for(i=0;a[i]!='\0';i++){
			if(!key[a[i]-97]){
				key[a[i]-97]=1;
				allright++;
			}
		}
		for(i=0;b[i]!='\0';i++)
			if(key[b[i]-97]){
				key[b[i]-97]=0;
				allright--;
				if(!allright)
					break;
			}
			else if(!wrong[b[i]-97]){
				wrong[b[i]-97]=1;
				allwrong++;
				if(allwrong>6)
					break;
			}
		if(allwrong>6)
			printf("Round %d\nYou lose.\n",n);
		else if(!allright)
			printf("Round %d\nYou win.\n",n);
		else
			printf("Round %d\nYou chickened out.\n",n);
	}
	return 0;
}
