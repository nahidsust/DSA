#include<bits/stdc++.h>
using namespace std;
int V=5;
typedef pair<int, int> iPair;
priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
vector<int>key(V, 1e5);
vector<int> parent(V, -1);
vector<bool> inMST(V, false);
vector<iPair> adj[100];
void primMST() {
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
    for (int i = 1; i < V; ++i)
        cout << parent[i] << " - " << i << "\t" << key[i] << "\n";
}

int main() {
    adj[0].push_back({1,2});
    adj[0].push_back(make_pair(3, 6));
    adj[1].push_back(make_pair(0, 2));
    adj[1].push_back(make_pair(2, 3));
    adj[1].push_back(make_pair(3, 8));
    adj[1].push_back(make_pair(4, 5));
    adj[2].push_back(make_pair(1, 3));
    adj[2].push_back(make_pair(4, 7));
    adj[3].push_back(make_pair(0, 6));
    adj[3].push_back(make_pair(1, 8));
    adj[4].push_back(make_pair(1, 5));
    adj[4].push_back(make_pair(2, 7));

    primMST();

    return 0;
}
