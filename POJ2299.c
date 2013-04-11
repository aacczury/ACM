#include <stdio.h>
int n,a[500000],t[500000];
long long total;

void merge(int l,int m,int r){
	int p=0,i,j;
	i=l;
	j=m;
	while(i<m&&j<r){
		if(a[i]>a[j]){
			t[p++]=a[j++];
			total+=m-i;
		}
		else
			t[p++]=a[i++];
	}
	while(i<m)t[p++]=a[i++];
	while(j<r)t[p++]=a[j++];
	for(i=0;i<p;i++)
		a[l+i]=t[i];
}

void mergesort(int l,int r){
	int m;
	if(l+1<r){
		m=(l+r)/2;
		mergesort(l,m);
		mergesort(m,r);
		merge(l,m,r);
	}
}

int main(){
	int i;
	while(scanf("%d",&n)!=EOF){
		if(!n)break;
		total=0;
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		mergesort(0,n);
		printf("%lld\n",total);
	}
}
