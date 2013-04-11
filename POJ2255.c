#include <stdio.h>
#include <string.h>

typedef struct{
	int root;
	int left;
	int right;
	int order;
}node;

node tree[26];
char a[27],b[27];

int preorder(int L, int R, int p, int root){
	int i;
	if(R-L<1)return p-1;
	for(i=L;i<R;i++)
		if(b[i]==a[p])
			break;
	tree[b[i]-65].root=root;
	tree[b[i]-65].order=i;
	if(root>=0)
		if(i<tree[root].order)
			tree[root].left=b[i]-65;
		else
			tree[root].right=b[i]-65;
	p=preorder(L,i,p+1,b[i]-65);
	p=preorder(i+1,R,p+1,b[i]-65);
	return p;
}

void postorder(root){
	if(tree[root].left>=0)
		postorder(tree[root].left);
	if(tree[root].right>=0)
		postorder(tree[root].right);
	printf("%c",root+65);
	return ;
}

int main(){
	while(scanf("%s%s",a,b)!=EOF){
		memset(tree,-1,sizeof(node)*26);
		preorder(0,strlen(b),0,-1);
		postorder(a[0]-65);
		printf("\n");
	}
}
