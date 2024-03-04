#include <iostream>
#include <vector>

using namespace std;

void generatePermutations(vector<int>& nums, vector<vector<int>>& result, int index = 0) {
    if (index == nums.size() - 1) {
        result.push_back(nums);
        return;
    }

    for (int i = index; i < nums.size(); ++i) {
        swap(nums[index], nums[i]);
        generatePermutations(nums, result, index + 1);
        swap(nums[index], nums[i]);
    }
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result;

    generatePermutations(nums, result);

    cout << "Permutations:" << endl;
    for (const auto& perm : result) {
        cout << "[";
        for (int num : perm) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
