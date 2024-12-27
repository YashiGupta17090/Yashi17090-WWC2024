//searching a number
#include <iostream>
#include <vector>
#include <algorithm>  // For std::binary_search
using namespace std;

int main() {
    vector<int> arr = {10, 20, 30, 40, 50};  // Sorted array
    int target = 30;

    // Using std::binary_search
    if (binary_search(arr.begin(), arr.end(), target)) {
        cout << "Element " << target << " is present in the array." << endl;
    } else {
        cout << "Element " << target << " is not present in the array." << endl;
    }

    return 0;
}
