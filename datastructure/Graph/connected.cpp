#include <iostream>
#include <vector>

using namespace std;

vector<int> graph[100];
bool visited[6] = {false};

void dfs(int s) {
    visited[s] = true;
    for (int i : graph[s]) {
        if (!visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    int edge, node;
    
    cout << "Enter the number of edges in the graph: ";
    cin >> edge;
    cout << "Enter the number of nodes in the graph: ";
    cin >> node;

    for (int i = 0; i < edge; ++i) {
        int x, y;
        cin >> x >> y;
        
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    int connectedComponents = 0;
    for (int i = 1; i <= node; ++i) {
        if (!visited[i]) {
            dfs(i);
            connectedComponents++;
        }
    }

    cout << "Number of connected components: " << connectedComponents << endl;

    return 0;
}
