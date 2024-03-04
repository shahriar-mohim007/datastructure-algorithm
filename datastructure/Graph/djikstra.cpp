#include <bits/stdc++.h>
using namespace std;
const int infinity = 1e9;  // Use a large value for infinity

class Node {
public:
    int u;
    int cost;
    Node(int _u, int _cost) {
        u = _u;
        cost = _cost;
    }
    bool operator<(const Node& p) const {
        return cost > p.cost;
    }
};

void dijkstra(int n, vector<int> g[], vector<int> cost[], int source) {
    vector<int> distance(n, infinity);  // Initialize distances with infinity
    priority_queue<Node> q;
    q.push(Node(source, 0));
    distance[source] = 0;

    while (!q.empty()) 
    {
        Node top = q.top();
        q.pop();
        int u = top.u;
        for (int i = 0; i < g[u].size(); i++) {
            int v = g[u][i];
            if (distance[u] + cost[u][i] < distance[v]) {
                distance[v] = distance[u] + cost[u][i];
                q.push(Node(v, distance[v]));
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (i != source) {  // Exclude source node
            cout << source << " --> " << i << " = " << distance[i] << endl;
        }
    }
}

int main() {
    int nodes, edge;
    cin >> nodes >> edge;
    vector<int> g[nodes];
    vector<int> cost[nodes];

    for (int i = 0; i < edge; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back(v);
        g[v].push_back(u);
        cost[u].push_back(w);
        cost[v].push_back(w);
    }

    int source;
    cin >> source;
    dijkstra(nodes, g, cost, source);

    return 0;
}
