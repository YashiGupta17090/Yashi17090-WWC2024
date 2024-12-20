//Q1: Convert Sorted Array to Binary Search Tree
//Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.
#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBSTHelper(nums, 0, nums.size() - 1);
    }

private:
    TreeNode* sortedArrayToBSTHelper(const vector<int>& nums, int left, int right) {
        if (left > right) {
            return nullptr;
        }

        // Get the middle element
        int mid = left + (right - left) / 2;
        TreeNode* node = new TreeNode(nums[mid]);

        // Recursively build the left and right subtrees
        node->left = sortedArrayToBSTHelper(nums, left, mid - 1);
        node->right = sortedArrayToBSTHelper(nums, mid + 1, right);

        return node;
    }
};

// Utility function to print the tree (in-order)
void inorder(TreeNode* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    Solution solution;
    vector<int> nums = {-10, -3, 0, 5, 9};
    
    TreeNode* root = solution.sortedArrayToBST(nums);
    
    // In-order traversal of the tree
    inorder(root);
    return 0;
}


