#include <iostream>
#include <string>
using namespace std;


int main(){
	string s;
	char c[300];
	char wrong[300];
	int max=0;
	int i,k,j;
	while(getline(cin,s)){
        max=0;
        if(s[0]==48)
            break;
		for(j=0;j<300;j++){
			c[j]=0;
			wrong[j]=0;
		}
		for(j=0;s[j]!=32;j++)
            max=max*10+s[j]-48;
		i=j+1;
		while(i<s.length()){
            for(j=0;wrong[j]!=0;j++)
                if(wrong[j]==s[i]){
                    j=299;
                    break;
                }
            if(j!=299)
				for(j=0;j<max;j++){
					if(c[j]==s[i]){
						c[j]=0;
						break;
					}
				}
			if(j==max)
				for(j=0;j<max;j++){
					if(c[j]==0){
						c[j]=s[i];
						break;
					}
				}	
			if(j==max){
				for(k=0;wrong[k]!=0;k++)
					if(wrong[k]==s[i])
						break;
					if(wrong[k]==0)
						wrong[k]=s[i];
			}
			i++;
		}
		for(k=0;wrong[k]!=0;k++);
		if(k==0)
		    cout<<"All customers tanned successfully."<<endl;
        else
            cout<<k<<" customer(s) walked away."<<endl;
	}
}
