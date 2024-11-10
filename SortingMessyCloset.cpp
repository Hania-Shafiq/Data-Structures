 #include <iostream>
 #include <string>
 #include <vector>
 #include <algorithm>
 using namespace std;
 int main() {
 vector<string> categories = {"Shirt", "Pants", "Dress", "Jacket", "Sweater", "Skirt"};
 vector<int> frequencies(categories.size(), 0);
 string item;
 cout << "Enter wardrobe items (type 'done' to finish):" << endl;
 // Input loop for items
 while (cin >> item && item != "done") {
 auto it = find(categories.begin(), categories.end(), item);
 if (it != categories.end()) {
 frequencies[distance(categories.begin(), it)]++;
 }
 }
 // Combine categories with frequencies for sorting
 vector<pair<string, int>> combined;
 for (size_t i = 0; i < categories.size(); ++i) {
 combined.emplace_back(categories[i], frequencies[i]);
}
 // Sort by frequency in descending order
 sort(combined.begin(), combined.end(), [](const pair<string, int>& a, const pair<string,
 int>& b) {
 return b.second < a.second;
 });
 // Output frequencies
 cout << "\nFrequencies:" << endl;
 for (const auto& entry : combined) {
 cout << entry.first << ": " << entry.second << endl;
 }
 return 0;
 }
