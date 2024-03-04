#include<bits/stdc++.h>
using namespace std;

void generateSubsets(vector<int>& nums, 
vector<vector<int>>& result, vector<int>& currentSubset, int index = 0) {
    result.push_back(currentSubset);

    for (int i = index; i < nums.size(); ++i) {
        currentSubset.push_back(nums[i]);
        generateSubsets(nums, result, currentSubset, i + 1);
        currentSubset.pop_back();
    }
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result;
    vector<int>subset;
    generateSubsets(nums, result,subset);

    cout << "Subsets:" << endl;
    for (const auto& subset : result) {
        cout << "[";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
