//GENERATING SUBSETS
//Time Complexity: n.2^n
//Auxiliary Space Complexity: 2^n

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> subsets(const vector<int>& nums) { //const in const vector<int>& nums ensures that the function operates on the input vector safely and efficiently, without making any changes to it.
    vector<vector<int>> res = {{}};

    for (int num : nums) {
        int n = res.size();
        for (int j = 0; j < n; ++j) {
            vector<int> temp = res[j];
            temp.push_back(num);           
            res.push_back(temp);
        }
    }
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

    vector<vector<int>> result = subsets(nums);

    cout << "Subsets:\n";
    for (const auto& subset : result) {
        cout << "{ ";
        for (int val : subset) {
            cout << val << " ";
        }
        cout << "}\n";
    }

    return 0;
}
