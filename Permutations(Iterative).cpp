//PERMUTATIONS
//time complexity: o(n!)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> permuteIterative(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    result.push_back(nums);
//A while loop continuously calls "next_permutation", which rearranges nums into its next lexicographical permutation.
    while (next_permutation(nums.begin(), nums.end())) {
        result.push_back(nums);
    }

    return result;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<vector<int>> result = permuteIterative(nums);

    // Print all permutations
    cout << "All permutations:" << endl;
    for (const auto& perm : result) {
        for (int num : perm) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
