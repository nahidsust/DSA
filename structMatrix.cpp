#include<bits/stdc++.h>
using namespace std;
struct pre{
int a[3];
};
int main(){
  struct pre p[3];
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			p[i].a[j]=1;
		}
	}
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cout<<p[i].a[j]<<" ";
		}
		cout<<endl;
	}
	
}
