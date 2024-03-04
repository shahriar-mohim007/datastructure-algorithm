#include<bits/stdc++.h>

using namespace std;
const int infinity = 1e9;  

class HeapElement {
public:
    int value;
    int distance; 

   
    HeapElement() : value(0), distance(0) {}

    HeapElement(int val, int dist) : value(val), distance(dist) {}
};

class MinHeap {
private:
    HeapElement a[101];
    int size;

public:
    MinHeap() {
        size = 0;
        for (int i = 0; i < 101; i++) {
            a[i] = HeapElement(0, 0);
        }
    }

    void push(int val, int distance) {
        if (size >= 100) {
            cout << "Heap is full. Cannot insert more elements." << endl;
            return;
        }

        size++;
        a[size] = HeapElement(val, distance);
        bottomTopAdjust(size);
    }

    HeapElement pop() {
        if (size == 0) {
            cout << "Heap is empty." << endl;
            return HeapElement(-1, -1);  
        }

        HeapElement minVal = a[1];

        a[1] = a[size];
        size--;

        topBottomAdjust(1);

        return minVal;
    }

    bool isEmpty() {
        return size == 0;
    }

private:
    void bottomTopAdjust(int i) {
        int parent;
        HeapElement temp = a[i];

        while (i > 1 && temp.distance < a[i / 2].distance) {
            a[i] = a[i / 2];
            i = i / 2;
        }

        a[i] = temp;
    }

    void topBottomAdjust(int i) {
        while (true) {
            int smallest = i;
            int leftChild = 2 * i;
            int rightChild = 2 * i + 1;

            if (leftChild <= size && a[leftChild].distance < a[smallest].distance)
                smallest = leftChild;

            if (rightChild <= size && a[rightChild].distance < a[smallest].distance)
                smallest = rightChild;

            if (smallest != i) {
                swap(a[i], a[smallest]);
                i = smallest;
            } else {
                break;
            }
        }
    }
};
void dijkstra(int n, vector<int> g[], vector<int> cost[], int source) {
    vector<int> distance(n, infinity);
    MinHeap minHeap;
    minHeap.push(source, 0);
    distance[source] = 0;

    while (!minHeap.isEmpty()) {
        HeapElement current = minHeap.pop();
        int u = current.value;
        for (int i = 0; i < g[u].size(); i++) {
            int v = g[u][i];
            if (distance[u] + cost[u][i] < distance[v]) {
                distance[v] = distance[u] + cost[u][i];
                minHeap.push(v, distance[v]);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (i != source) {  
            cout << source << " --> " << i << " = " << distance[i] << endl;
        }
    }
}

int main() 
{
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