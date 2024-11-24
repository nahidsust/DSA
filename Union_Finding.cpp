#include<bits/stdc++.h>
using namespace std;
const int MAX_SIZE = 1000; // Define a maximum size for the DSU
int parent[MAX_SIZE];
int Rank[MAX_SIZE];
void initialize(int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i; // Each element is its own parent initially
        Rank[i] = 0;   // Initial rank is 0
    }
}
int Find(int x) {
    if (parent[x] != x) {
        parent[x] = Find(parent[x]); // Path compression
    }
    return parent[x];
}
// Union operation with rank optimization
void union_sets(int x, int y) {
    int rootX = Find(x);
    int rootY = Find(y);

    if (rootX != rootY) {
        if (Rank[rootX] < Rank[rootY]) {
            parent[rootX] = rootY;
        } else if (Rank[rootX] > Rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            Rank[rootX]++;
        }
    }
}

int main() {
       int n,e,x,y;
       vector<pair<int,int>>v;
       cin>>n>>e;
       while(e--){
              cin>>x>>y;
              v.push_back({x,y});
       }
    initialize(n);
             for(auto child:v)union_sets(child.first,child.second);
 if(Find(1)==Find(6))cout<<"They are same set";
 else cout<<"Not";
    return 0;
}
