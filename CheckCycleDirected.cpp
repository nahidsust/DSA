#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>v(10);
vector<int>vis(10),completed(10,0);
bool dfs(int node){
	      
	  vis[node]=1;
	  for(auto child:v[node]){
		if(vis[child]==0){
		
		if(dfs(child))return true;
		}  else{
		    if(completed[child]==0) return true;
		}
	  }
	  completed[node]=1;
	  return false;
}
int main(){
   int n,e,x,y;
   cin>>n>>e;
   while(e--){
	cin>>x>>y;
	v[x].push_back(y);
   }
 if(dfs(1))cout<<"Cycle";
 else cout<<"No Cycle";

}