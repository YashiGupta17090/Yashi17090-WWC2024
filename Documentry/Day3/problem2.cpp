//Q2 . Elimination Game
//You have a list arr of all integers in the range [1, n] sorted in a strictly increasing order. Apply the following algorithm on arr:
//Starting from left to right, remove the first number and every other number afterward until you reach the end of the list.
//Repeat the previous step again, but this time from right to left, remove the rightmost number and every other number from the remaining numbers.
//Keep repeating the steps again, alternating left to right and right to left, until a single number remains.
#include <iostream>
#include <vector>
using namespace std;

int eliminationGame(int n) {
    vector<int> arr;
    
    // Initialize the array with numbers 1 to n
    for (int i = 1; i <= n; i++) {
        arr.push_back(i);
    }
    
    bool leftToRight = true;  // Flag to alternate between left to right and right to left
    
    // While there is more than one element
    while (arr.size() > 1) {
        vector<int> temp;
        
        if (leftToRight) {
            // Left to Right: Remove every second element starting from the first
            for (int i = 0; i < arr.size(); i++) {
                if (i % 2 != 0) {
                    temp.push_back(arr[i]);
                }
            }
        } else {
            // Right to Left: Remove every second element starting from the last
            for (int i = arr.size() - 1; i >= 0; i--) {
                if (i % 2 != 0) {
                    temp.push_back(arr[i]);
                }
            }
        }

        // Update arr with the new list of elements
        arr = temp;
        
        // Alternate the direction for the next iteration
        leftToRight = !leftToRight;
    }
    
    // Return the last remaining element
    return arr[0];
}

int main() {
    int n;
    cout << "Enter a number n: ";
    cin >> n;
    int result = eliminationGame(n);
    cout << "The last remaining number is: " << result << endl;
    
    return 0;
}
