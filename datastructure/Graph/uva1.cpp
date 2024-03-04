#include<bits/stdc++.h>
using namespace std;
vector<int>indegree;
vector<vector<int>> adj;
void topsort(int n)
{
    queue<int>q;
    for(int i= 1;i<= n;i++)
    {
     if (indegree[i] == 0) {
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
    if (result.size() != n) {
        cout << "Tasks have a cycle!" << endl;
        return;
    }
    cout <<endl;

    for (int task : result) {
        cout << task << " ";
    }
    cout << endl;
}
int main()
{
    while (true)   {
        int n, m;
        cin >> n >> m;

    if (n == 0 && m == 0) {
            break;
    }
    indegree.resize(n+1,0);
    adj.resize(n+1);

    for(int i=0;i<m;i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
       
    }
    for (int u = 1; u <= n; ++u) {
            for (int v : adj[u]) {
                indegree[v]++;
            }
        }
        topsort(n);
  
}

    return 0;
}