//COMBINATIONS
//time complexity: o(2^n)
#include <iostream>
#include <vector>
using namespace std;

// Recursive function to generate combinations of a specified length
void combine(vector<int>& nums, vector<vector<int>>& ans, vector<int>& current, int start, int size) {
    // Add the current combination to the result only if it matches the desired size
    if (current.size() == size) {
        ans.push_back(current);
        return;  // Return to stop further processing once the combination size is met
    }

    // Generate combinations by picking each element starting from `start` index
    for (int i = start; i < nums.size(); i++) {
        current.push_back(nums[i]);           // Include nums[i] in the current combination
        combine(nums, ans, current, i + 1, size);   // Recursive call with the next index
        current.pop_back();                   // Backtrack to explore other combinations
    }
}

// Wrapper function to initiate combination generation with a specified size
vector<vector<int>> generateCombinationsOfSize(vector<int>& nums, int size) {
    vector<vector<int>> ans;
    vector<int> current;
    combine(nums, ans, current, 0, size);
    return ans;
}

int main() {
    int n, k;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter the size of combinations to generate: ";
    cin >> k;

    vector<vector<int>> result = generateCombinationsOfSize(nums, k);

    cout << "Combinations of size " << k << ":\n";
    for (const auto& comb : result) {
        for (int num : comb) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
