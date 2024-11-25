#include<bits/stdc++.h>
using namespace std;
vector<int>v(20,-1);
void make_prefix(string s){
  v[0]=0;
int i=0,j=1,n;
//first i then j
n=s.size();
while(v[n-1]==-1){
	if(s[i]!=s[j] && i==0){
	v[j]=i;
	j++;
	}
	else if(s[i]!=s[j]){
		i=v[i-1];
	}else{
	       v[j]=i+1;
	       i++;
	       j++;
	}
}
}
int main(){
   string text,substring ;
   getline(cin,text);
   cin>>substring;
   make_prefix(substring);
        //j for text and i for substring
        int i=0,j=0;
        while(j!=text.size()){
	 if(text[j]!=substring[i] && i==0)j++;
	 else if(text[j]!=substring[i])i=v[i-1];
	 else{
	       i++;
	       j++;
	   }
        if(i==substring.size()){
	cout<<"String match at index: "<<j-i+1<<endl;
	i=0;
        }
        }
}