//search in rotated sorted array
#include <iostream>
#include <vector>
using namespace std;

int search(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        // If the target is found at the middle
        if (nums[mid] == target) {
            return mid;
        }

        // Left half is sorted
        if (nums[left] <= nums[mid]) {
            // Check if the target lies within the sorted left half
            if (nums[left] <= target && target < nums[mid]) {
                right = mid - 1;  // Search in the left half
            } else {
                left = mid + 1;   // Search in the right half
            }
        }
        // Right half is sorted
        else {
            // Check if the target lies within the sorted right half
            if (nums[mid] < target && target <= nums[right]) {
                left = mid + 1;   // Search in the right half
            } else {
                right = mid - 1;  // Search in the left half
            }
        }
    }
    
    // Target not found
    return -1;
}

int main() {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};  // Rotated sorted array
    int target = 0;
    
    int result = search(nums, target);
    
    if (result != -1) {
        cout << "Target found at index: " << result << endl;
    } else {
        cout << "Target not found" << endl;
    }

    return 0;
}


