//Q2: Valid Sudoku
//Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
//Each row must contain the digits 1-9 without repetition. Each column must contain the digits 1-9 without repetition.Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
//Note:A Sudoku board (partially filled) could be valid but is not necessarily solvable.
//Only the filled cells need to be validated according to the mentioned rules.
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            unordered_set<char> rowSet;
            unordered_set<char> colSet;
            unordered_set<char> subBoxSet;
            for (int j = 0; j < 9; j++) {
                // Check row
                if (board[i][j] != '.' && rowSet.count(board[i][j])) return false;
                if (board[i][j] != '.') rowSet.insert(board[i][j]);
                
                // Check column
                if (board[j][i] != '.' && colSet.count(board[j][i])) return false;
                if (board[j][i] != '.') colSet.insert(board[j][i]);
                
                // Check sub-box
                int rowIndex = 3 * (i / 3), colIndex = 3 * (i % 3);
                if (board[rowIndex + j / 3][colIndex + j % 3] != '.' &&
                    subBoxSet.count(board[rowIndex + j / 3][colIndex + j % 3])) return false;
                if (board[rowIndex + j / 3][colIndex + j % 3] != '.') 
                    subBoxSet.insert(board[rowIndex + j / 3][colIndex + j % 3]);
            }
        }
        return true;
    }
};

int main() {
    Solution solution;
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    
    if (solution.isValidSudoku(board)) {
        cout << "Valid Sudoku" << endl;
    } else {
        cout << "Invalid Sudoku" << endl;
    }

    return 0;
}

