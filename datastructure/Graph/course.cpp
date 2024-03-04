#include<bits/stdc++.h>
using namespace std;

int main()
{
    int edge,vertices;
    cin>>edge>>vertices;
    vector<int>indegree(vertices,0);
    vector<vector<int>>adj(vertices);
    for(int i=0;i<edge;i++)
    {
        int u,v;
        cin>> u>> v;
        adj[u].push_back(v);

    }
    for(int u=0;u<vertices;u++)
    {
        for(int v:adj[u])
        {
          indegree[v]++;
        }
    }
    queue<int>q;
    for(int i=0;i<vertices;i++)
    {
        if(indegree[i]==0)
        {
            q.push(i);
        }
    }
    vector<int> result;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        result.push_back(u);
        for(int v: adj[u])
        {
            if (--indegree[v] == 0) {
                q.push(v);
            }
        }
       
    }


     if (result.size() != vertices) {
        cout << "Graph has a cycle!" << endl;
        exit(0);
     }
    cout << "Topological order: ";
    for (int vertex : result) {
        cout << vertex << " ";
    }
    cout << endl;

}