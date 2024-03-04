#include <bits/stdc++.h>
using namespace std;

void subsetSum(vector<int>& arr, int target, vector<int>& currentSubset, int index) {
    if (target == 0) {
        cout << "Subset: ";
        for (int num : currentSubset) {
            cout << num << " ";
        }
        cout << endl;
        return;
    }
    for (int i = index; i < arr.size(); i++) {
        if (arr[i] <= target) { 
            currentSubset.push_back(arr[i]);
            subsetSum(arr, target - arr[i], currentSubset, i + 1);
            currentSubset.pop_back();
        }
    }
}

int main() {
    int n, target;
    cin >> n >> target;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    vector<int> currentSubset;
    subsetSum(arr, target, currentSubset, 0);

    return 0;
}
