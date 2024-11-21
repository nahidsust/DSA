#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int>Pair;
vector<Pair>adj[100000];
int n;
void primMST() {
    priority_queue<Pair, vector<Pair>, greater<Pair>> pq;
    vector<int> key(n, INT_MAX);
    vector<int> parent(n, -1);
    vector<bool> inMST(n, false);

    pq.push(make_pair(0, 0));
    key[0] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        inMST[u] = true;

        for (auto x : adj[u]) {
            int v = x.first;
            int weight = x.second;
            if (!inMST[v] && key[v] > weight) {
                key[v] = weight;
                pq.push(make_pair(key[v], v));
                parent[v] = u;
            }
        }
    }

    cout << "Edge \tWeight\n";
    for (int i = 1; i < n; ++i)
        cout << parent[i] << " - " << i << "\t" << key[i] << "\n";
}

int main() {
       int e,x,y,w;
       cin>>n>>e;


       while(e--){
       cin>>x>>y>>w;
       adj[x].push_back({y,w});
       adj[y].push_back({x,w});
       }
      // primMST();

       for(auto child:adj[0]){
               cout<<child.first<<" "<<child.second<<endl;
       }

    return 0;
}
