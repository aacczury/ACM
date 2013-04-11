#include <stdio.h>

int main(){
	char p[1000];
	char c[300];
	int n;
	int i,j,k,left,empty;
	while(scanf("%d",&n)){
		if(n==0)break;
		scanf("%s",p);
		for(i=0;i<n;i++)
			c[i]=0;
		left=0;
		for(i=0;p[i]!='\0';i++){
			if(p[i]==0)
				continue;
			empty=-1;
			for(j=0;j<n;j++)
				if(c[j]==0)
					empty=j;
				else if(c[j]==p[i]){
					c[j]=0;
					break;
				}
			if(j==n)
				if(empty!=-1)
					c[empty]=p[i];
				else{
					left++;
					for(k=i+1;p[k]!='\0';k++)
						if(p[k]==p[i]){
							p[k]=0;
							break;
						}
				}
		}
		if(left!=0)
			printf("%d customer(s) walked away.\n",left);
		else
			printf("All customers tanned successfully.\n");
	}
}
