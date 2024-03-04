#include <bits/stdc++.h>
using namespace std;
const int infinity = 30000;

void bellman(int n, vector<int> g[], vector<int> cost[], int source) {
    vector<int> distance(n + 1, infinity);
    distance[source] = 0;
    bool neg_cycle = false;
    bool updated = false;
    for (int i = 1; i <= n - 1; i++) {
        bool updated = false;  
        for (int u = 1; u <= n; u++) { 
            for (int j = 0; j < g[u].size(); j++) {
                int v = g[u][j];
                int w = cost[u][j];

                if (distance[u] + w < distance[v]) {
                     updated = true;
                    distance[v] = distance[u] + w;
                }
            }
        }
        if(i==n and updated==true)
        {
            neg_cycle = true;
        }
    }
    
    

    for (int i = 1; i <= n; i++) {  
        if (distance[i] == infinity) {
            cout << 30000 << " ";
        } else {
            cout << distance[i] << " ";
        }
    }
}

int main() {
    vector<int> g[101], cost[101];
    int numNodes, numEdges;
    cin >> numNodes >> numEdges;

    for (int i = 0; i < numEdges; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back(v);
        cost[u].push_back(w);
    }

    int source=1;
    //cin>>source;
    bellman(numNodes, g, cost, source);

    return 0;
}
