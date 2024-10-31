#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPairsWithDiffK(vector<int>& arr, int k) {
        unordered_map<int, int> elementCount;
        int count = 0;

        // Populate the map with frequencies of each element.
        for (int num : arr) {
            elementCount[num]++;
        }

        // Iterate through each unique element in the map.
        for (const auto& element : elementCount) {
            int value = element.first;

            // If `value + k` exists in the map, add to count.
            if (elementCount.find(value + k) != elementCount.end()) {
                count += element.second * elementCount[value + k];
            }
        }
        return count;
    }
};

int main() {
    Solution solution;
    vector<int> arr1 = {1, 5, 3, 4, 2};
    int k1 = 3;
    cout << "Number of pairs with difference " << k1 << ": " 
              << solution.countPairsWithDiffK(arr1, k1) << endl;

    vector<int> arr2 = {8, 12, 16, 4, 0, 20};
    int k2 = 4;
    cout << "Number of pairs with difference " << k2 << ": " 
              << solution.countPairsWithDiffK(arr2, k2) <<endl;

    return 0;
}