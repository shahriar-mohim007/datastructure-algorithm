#include <iostream>
#include <vector>

using namespace std;

int knapsack(int capacity, const vector<int>& weights, const vector<int>& values, int n) {
    if (n == 0 || capacity == 0) {
        return 0;
    }

   
    if (weights[n - 1] > capacity) {
        return knapsack(capacity, weights, values, n - 1);
    }

   
    return max(values[n - 1] + knapsack(capacity - weights[n - 1], weights, values, n - 1),
               knapsack(capacity, weights, values, n - 1));
}

int main() {
    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    vector<int> weights(n);
    vector<int> values(n);

    cout << "Enter the weights of the items: ";
    for (int i = 0; i < n; ++i) {
        cin >> weights[i];
    }

    cout << "Enter the values of the items: ";
    for (int i = 0; i < n; ++i) {
        cin >> values[i];
    }

    int capacity;
    cout << "Enter the knapsack capacity: ";
    cin >> capacity;

    int maxVal = knapsack(capacity, weights, values, n);

    cout << "Maximum value that can be obtained: " << maxVal << endl;

    return 0;
}
