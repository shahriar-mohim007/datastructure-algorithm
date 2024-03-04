#include <bits/stdc++.h>

using namespace std;

class Heap {
private:
    int a[101], size;

public:
    Heap() {
        size = 0;
    }

public:
    bool insert(int val) {
        if (size >= 100) {
            cout << "Heap is full. Cannot insert more elements." << endl;
            return false;
        }

        size++;
        a[size] = val;
        bottomTopAdjust(size);
        return true;
    }

    int showMax() {
        if (size == 0) {
            cout << "Heap is empty." << endl;
            return -1; // Return a sentinel value to indicate an empty heap
        }
        return a[1];
    }

    int showSize() {
        return size;
    }

    bool deleteRoot() {
        if (size == 0) {
            cout << "Heap is empty. Cannot delete." << endl;
            return false;
        }

        // Replace the root with the last element
        a[1] = a[size];
        size--;
        // Adjust the heap to maintain the max heap property
        topBottomAdjust(1);
        return true;
    }

    void buildHeap() {
        for (int i = size / 2; i >= 1; i--) {
            topBottomAdjust(i);
        }
    }

    void sort() {
        if (size == 0) {
            cout << "Heap is empty. Nothing to sort." << endl;
            return;
        }

        int n = size;

        // Perform heap sort
        for (int i = n; i >= 1; i--) {
            swap(a[1], a[i]);
            size--;
            topBottomAdjust(1);
        }

        // Print the sorted array
        cout << "Sorted Array: ";
        for (int i = n; i >= 1; i--) {
            cout << a[i] << " ";
        }
        cout << endl;
    }

    void bfs() {
        if (size == 0) {
            cout << "Heap is empty." << endl;
            return;
        }

        int level = 1;
        queue<int> q;
        q.push(1);

        while (!q.empty()) {
            int nodeCount = q.size();
            cout << "Level " << level << ": ";
            for (int i = 0; i < nodeCount; i++) {
                int parent = q.front();
                q.pop();
                cout << a[parent] << " ";
                if (2 * parent <= size) q.push(2 * parent);
                if (2 * parent + 1 <= size) q.push(2 * parent + 1);
            }
            cout << endl;
            level++;
        }
    }

private:
    void bottomTopAdjust(int i) {
        int parent, temp;
        temp = a[i];
        parent = i / 2;

        while (i > 1 && temp > a[parent]) {
            a[i] = a[parent];
            i = parent;
            parent = i / 2;
        }

        a[i] = temp;
    }

    void topBottomAdjust(int i) {
        int largest = i;
        while (true) {
            int leftChild = 2 * i;
            int rightChild = 2 * i + 1;

            if (leftChild <= size && a[leftChild] > a[largest])
                largest = leftChild;

            if (rightChild <= size && a[rightChild] > a[largest])
                largest = rightChild;

            if (largest != i) {
                swap(a[i], a[largest]);
                i = largest;
            } else {
                break;
            }
        }
    }
};

int main() {
    Heap heap;

    while (1) {
        cout << "1. Insert    2. Show Max    3. Delete Max    4. Sort    5. Level    6. Build Heap    7. End" << endl
             << endl;
        int choice;
        cin >> choice;

        if (choice == 1) {
            cout << "Insert Value: ";
            int y;
            cin >> y;
            bool b = heap.insert(y);

            if (b) cout << y << " is inserted in the heap" << endl;
        } else if (choice == 2) {
            int maxVal = heap.showMax();
            if (maxVal != -1) cout << "Max Element: " << maxVal << endl;
        } else if (choice == 3) {
            bool b = heap.deleteRoot();
            if (b) cout << "Root deleted from heap" << endl;
        } else if (choice == 4) {
            heap.sort();
        } else if (choice == 5) {
            cout << "Level Wise Traversal of the heap:" << endl;
            heap.bfs();
            cout << endl;
        } else if (choice == 6) {
            heap.buildHeap();
            cout << "Heap is built." << endl;
        } else if (choice == 7) {
            break;
        } else {
            cout << "Invalid Choice" << endl;
        }
        cout << endl;
    }
}