//Q3: Remove Element
//Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once.
//The relative order of the elements should be kept the same. Then return the number of unique elements in nums..
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;

        int uniqueIndex = 1;
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                nums[uniqueIndex] = nums[i];
                uniqueIndex++;
            }
        }

        return uniqueIndex;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 1, 2, 2, 3, 4, 4, 5};

    int length = solution.removeDuplicates(nums);

    cout << "Length of array after removing duplicates: " << length << endl;
    cout << "Array after removal: ";
    for (int i = 0; i < length; i++) {
        cout << nums[i] << " ";
    }
    return 0;
}
