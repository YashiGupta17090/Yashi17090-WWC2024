//sorted array search
#include <iostream>
#include <vector>
using namespace std;

// Function to perform binary search
int binarySearch(const vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;  // Calculate the middle index

        // Check if target is present at mid
        if (arr[mid] == target) {
            return mid;  // Return the index where target is found
        }
        // If target is greater, ignore the left half
        else if (arr[mid] < target) {
            left = mid + 1;
        }
        // If target is smaller, ignore the right half
        else {
            right = mid - 1;
        }
    }

    return -1;  // Target is not found in the array
}

int main() {
    vector<int> arr = {10, 20, 30, 40, 50};  // Sorted array
    int target = 30;

    int result = binarySearch(arr, target);
    if (result != -1) {
        cout << "Element " << target << " found at index: " << result << endl;
    } else {
        cout << "Element " << target << " not found." << endl;
    }

    return 0;
}
