#include<bits/stdc++.h>
using namespace std;
vector<int> graph[100];
int color[100];
bool issafe(int node,int c, int n)
{
for(int i=0;i<graph[node].size();i++)
{
    if (color[graph[node][i]] == c) {
            return false;
        }
}
    return true;
}

void graphcoloring(int m,int n,int node=0)
{
if (node == n) {
        cout << "Node colors:" << endl;
        for (int i = 0; i < n; ++i) {
            cout << "Node " << i << ": Color " << color[i] << endl;
        }
     
        return;
    }
for(int c=1;c<=m;c++)
{
if (issafe(node,c,m))
{
 color[node] = c;
 graphcoloring(m, n, node + 1);
 color[node] = 0;
}
}

}
int main()
{
    int edge, node, m;
    cin>> edge>> node>> m;
    for (int i = 0; i < edge; ++i) {
        int x, y;
        cin >> x >> y;

        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    graphcoloring(m,node);

}