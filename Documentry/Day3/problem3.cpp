// Predict The Winner
//You are given an integer array nums. Two players are playing a game with this array: player 1 and player 2.
//Player 1 and player 2 take turns, with player 1 starting first. Both players start the game with a score of 0. At each turn, the player takes one of the numbers from either end of the array (i.e., nums[0] or nums[nums.length - 1]) which reduces the size of the array by 1. The player adds the chosen number to their score. The game ends when there are no more elements in the array.
//Return true if Player 1 can win the game. If the scores of both players are equal, then player 1 is still the winner, and you should also return true. You may assume that both players are playing optimally.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        // Base case: when there is only one element, the score difference is that element itself.
        for (int i = 0; i < n; ++i) {
            dp[i][i] = nums[i];
        }
        
        // Fill the dp table for subarrays of length 2 to n.
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;
                dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
            }
        }
        
        // If the score difference for the entire array is non-negative, Player 1 wins or ties.
        return dp[0][n - 1] >= 0;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 5, 233, 7};
    
    bool result = solution.PredictTheWinner(nums);
    
    if (result) {
        cout << "Player 1 can win the game!" << endl;
    } else {
        cout << "Player 2 can win the game!" << endl;
    }
    
    return 0;
}
