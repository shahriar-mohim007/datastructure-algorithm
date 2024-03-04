#include<bits/stdc++.h>
using namespace std;
vector<int>indegree;
vector<vector<int>> adj;
vector<bool> visited;
void printAllTopSort(vector<int>& result)
{
    bool flag = false;
    for (int i = 0; i < indegree.size(); i++) {
        if (!visited[i] && indegree[i] == 0) {
            visited[i] = true;
            result.push_back(i);
            for (int v : adj[i]) {
                indegree[v]--;
            }

            printAllTopSort(result);

            visited[i] = false;
            result.pop_back();
            for (int v : adj[i]) {
                indegree[v]++;
            }

            flag = true;
        }
    }

    if (!flag) {
        for (int vertex : result) {
            cout << vertex << " ";
        }
        cout << endl;
    }
}
int main()
{
    int vertices,edges;
    cin>>edges>>vertices;
    indegree.resize(vertices,0);
    adj.resize(vertices);
    visited.resize(vertices, false);
    for(int i=0;i<edges;i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
       
    }
    for (int u = 0; u < vertices; ++u) {
            for (int v : adj[u]) {
                indegree[v]++;
            }
        }
    vector<int> result;
    printAllTopSort(result);
}