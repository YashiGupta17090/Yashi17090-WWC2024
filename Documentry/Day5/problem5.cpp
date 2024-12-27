//Find target indices after sorting
#include <iostream>
#include <vector>
#include <algorithm>  // For sort function
using namespace std;

vector<int> targetIndicesAfterSorting(vector<int>& nums, int target) {
    vector<int> result;
    
    // Step 1: Sort the array
    vector<int> sortedNums = nums;
    sort(sortedNums.begin(), sortedNums.end());

    // Step 2: Find all indices where the target is present in the sorted array
    for (int i = 0; i < sortedNums.size(); ++i) {
        if (sortedNums[i] == target) {
            result.push_back(i);  // Store the index
        }
    }

    return result;
}

int main() {
    vector<int> nums = {4, 2, 7, 1, 3, 2, 4};  // Example unsorted array
    int target = 2;  // Target element to search

    vector<int> result = targetIndicesAfterSorting(nums, target);

    // Output the result
    if (result.empty()) {
        cout << "Target " << target << " not found in the array." << endl;
    } else {
        cout << "Indices of target " << target << " after sorting: ";
        for (int index : result) {
            cout << index << " ";
        }
        cout << endl;
    }

    return 0;
}

