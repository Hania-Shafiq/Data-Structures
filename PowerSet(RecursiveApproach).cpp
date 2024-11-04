//power set (recursive method)
//Time Complexity: 2^n
//space complexity is O(n * 2^n).

#include <iostream>
#include <vector>
using namespace std;
//nums~provided vector
//res~answer vector
//current~the vector in which we change

// Recursive function to generate powerset
void generatePowerset(const vector<int>& nums, vector<vector<int>>& res, vector<int>& current, int index) {
    // Add the current subset to the result
    res.push_back(current);

    // Explore further by including each element starting from the current index
    for (int i = index; i < nums.size(); ++i) {
        current.push_back(nums[i]);              // Include nums[i] in the current subset
        generatePowerset(nums, res, current, i + 1); // Recursive call to generate further subsets
        current.pop_back();                      // Backtrack to explore subsets without nums[i]
    }
}

// Wrapper function to initiate the recursive powerset generation
vector<vector<int>> powerset(const vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> current;
    generatePowerset(nums, res, current, 0);
    return res;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    vector<vector<int>> result = powerset(nums);

    cout << "Powerset:\n";
    for (const auto& subset : result) {
        cout << "{ ";
        for (int val : subset) {
            cout << val << " ";
        }
        cout << "}\n";
    }

    return 0;
}
