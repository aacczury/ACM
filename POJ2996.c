#include <stdio.h>
#include <stdlib.h>

int cmp(const void *x, const void *y){
	return *(int *)x - *(int *)y;
}

int main(){
	char c[34];
	int i,j,k;
	int a[16],b[16],temp;
	while(scanf("%s",c)!=EOF){
		for(i=0;i<16;i++){
			a[i]=-1;
			b[i]=-1;
		}
		for(i=0;i<16;i++){
			scanf("%s",c);
			if(i%2==0)
				for(j=2;j<31;j+=4)
					if(c[j]!='.'&&c[j]!=':')
						switch(c[j]){
							case 'K':a[0]=(7-i/2)*8+j/4;break;
							case 'Q':a[1]=(7-i/2)*8+j/4;break;
							case 'R':
								if(a[2]==-1)
									a[2]=(7-i/2)*8+j/4;
								else
									a[3]=(7-i/2)*8+j/4;
								break;
							case 'B':
								if(a[4]==-1)
									a[4]=(7-i/2)*8+j/4;
								else
									a[5]=(7-i/2)*8+j/4;
								break;
							case 'N':
								if(a[6]==-1)
									a[6]=(7-i/2)*8+j/4;
								else
									a[7]=(7-i/2)*8+j/4;
								break;
							case 'P':
								for(k=0;k<8;k++)
									if(a[k+8]==-1){
										a[k+8]=(7-i/2)*8+j/4;
										break;
									}
								break;
								
							case 'k':b[0]=(7-i/2)*8+j/4;break;
							case 'q':b[1]=(7-i/2)*8+j/4;break;
							case 'r':
								if(b[2]==-1)
									b[2]=(7-i/2)*8+j/4;
								else
									b[3]=(7-i/2)*8+j/4;
								break;
							case 'b':
								if(b[4]==-1)
									b[4]=(7-i/2)*8+j/4;
								else
									b[5]=(7-i/2)*8+j/4;
								break;
							case 'n':
								if(b[6]==-1)
									b[6]=(7-i/2)*8+j/4;
								else
									b[7]=(7-i/2)*8+j/4;
								break;
							case 'p':
								for(k=0;k<8;k++)
									if(b[k+8]==-1){
										b[k+8]=(7-i/2)*8+j/4;
										break;
									}
								break;
						}
		}
		
		qsort(a+2,2,sizeof(int),cmp);
		qsort(a+4,2,sizeof(int),cmp);
		qsort(a+6,2,sizeof(int),cmp);
		qsort(a+8,8,sizeof(int),cmp);
		temp=0;
		printf("White: ");
		for(i=0;i<16;i++){
			if(a[i]!=-1){
				if(temp)
					printf(",");
				temp=1;
				switch(i){
					case 0:printf("K");break;
					case 1:printf("Q");break;
					case 2:printf("R");break;
					case 3:printf("R");break;
					case 4:printf("B");break;
					case 5:printf("B");break;
					case 6:printf("N");break;
					case 7:printf("N");break;
				}
				printf("%c%d",a[i]%8+97,a[i]/8+1);
			}
		}
		printf("\n");
		temp=0;
		printf("Black: ");
		for(i=0;i<16;i++){
			if(b[i]!=-1){
				if(temp)
					printf(",");
				temp=1;
				switch(i){
					case 0:printf("K");break;
					case 1:printf("Q");break;
					case 2:printf("R");break;
					case 3:printf("R");break;
					case 4:printf("B");break;
					case 5:printf("B");break;
					case 6:printf("N");break;
					case 7:printf("N");break;
				}
				printf("%c%d",b[i]%8+97,b[i]/8+1);
			}
		}
		printf("\n");
	}
}
