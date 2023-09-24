#include<bits/stdc++.h>
using namespace std;
//How Quick Sort Works?Idea of quick sort is choosing a pivot element for every iteration and place it in its actual position.After every Iteration, the chosen pivot will be placed at where it exactly has to be, the values lesser than the pivot will be placed on the left side of pivot and values greater than the pivot will be placed on the right side of the pivot.
int partition(vector<int>& nums, int low, int high) {
    int pivot = nums[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (nums[j] <= pivot) {
            i++;
            swap(nums[i], nums[j]);
        }
    }
    swap(nums[i + 1], nums[high]);
    return i + 1;
}

void quicksort(vector<int>& nums, int low, int high) {
    if (low < high) {
        int pi = partition(nums, low, high);
        quicksort(nums, low, pi - 1);
        quicksort(nums, pi + 1, high);
    }
}

int main() {
    int elements;
    cin >> elements;
    vector<int> nums(elements);
    for (int i = 0; i < elements; i++) {
        cin >> nums[i];
    }
    quicksort(nums, 0, elements - 1);
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
