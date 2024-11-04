//PERMUTATIONS
//time complexity: n!
//space complexity: n.n!
#include <iostream>
#include <vector>

using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void solve(vector<int>& nums, vector<vector<int>>& ans, int index) {
    // Base case
    if (index >= nums.size()) {
        ans.push_back(nums);
        return;
    }

    for (int j = index; j < nums.size(); j++) {
        swap(nums[index], nums[j]);  // Swap elements to generate a new permutation
        solve(nums, ans, index + 1); // Recursive call to generate permutations for the next index
        swap(nums[index], nums[j]);  // Backtrack to restore original array
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    int index = 0;
    solve(nums, ans, index);
    return ans;
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

    vector<vector<int>> result = permute(nums);

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
