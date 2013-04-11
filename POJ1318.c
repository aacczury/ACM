#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct dic{
	char word[100];
	struct dic *next;
}dic;

int cmp(const void *a, const void *b){
	return *(char *)a-*(char *)b;
}


int main(){
	char tw[100],ttw[100];
	int turn=0,md=0,i,j;
	dic mydic[100];
	dic *node,*flag;
	while(gets(tw)){
		if(!strcmp(tw,"XXXXXX")){
			turn++;
			continue;
		}
		if(turn==2)
			break;
		if(!turn){
			strcpy(ttw,tw);
			qsort(ttw, strlen(ttw), sizeof(char), cmp);
			for(i=0;i<md;i++)
				if(!strcmp(ttw,mydic[i].word))
					break;
			if(i==md){
				strcpy(mydic[i].word,ttw);
				mydic[i].next=NULL;
				md++;
			}
			flag=&mydic[i];
			while(flag->next!=NULL&&strcmp(tw,flag->next->word)!=-1)
				flag=flag->next;
			node=malloc(sizeof(dic));
			strcpy(node->word,tw);
			node->next=flag->next;
			flag->next=node;
		}
		if(turn==1){
			strcpy(ttw,tw);
			qsort(ttw, strlen(ttw), sizeof(char), cmp);
			for(i=0;i<md;i++)
				if(!strcmp(ttw,mydic[i].word))
					break;
			if(i==md)
				printf("NOT A VALID WORD\n");
			else{
				flag=&mydic[i];
				while(flag->next!=NULL){
					printf("%s\n",flag->next->word);
					flag=flag->next;
				}
			}
			printf("******\n");
		}
	}
	return 0;
}
