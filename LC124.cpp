// https://leetcode.com/problems/binary-tree-maximum-path-sum/description/?envType=study-plan-v2&envId=top-interview-150
#include "headers.h"

using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int maxPathSum(TreeNode* root)
    {
        int max = INT_MIN;
        int result = sumTraversalDFS(root, max);
        return std::max(max, result);;
    }
private:
    int sumTraversalDFS(TreeNode* node, int& max)
    {
        if(!node)
            return INT_MIN;
        if(!node->left && !node->right)
            return node->val;
        
        int leftTreeSum = sumTraversalDFS(node->left, max);
        int rightTreeSum = sumTraversalDFS(node->right, max);
        if(leftTreeSum != INT_MIN)
            max = std::max(max, leftTreeSum);
        if(rightTreeSum != INT_MIN)
            max = std::max(max, rightTreeSum);
        
        max = std::max(max, node->val);
        max = std::max(max, 
            (leftTreeSum == INT_MIN ? 0 : leftTreeSum) + (rightTreeSum == INT_MIN ? 0 : rightTreeSum) + node->val);
        int maxSoFar = std::max((leftTreeSum == INT_MIN ? 0 : leftTreeSum) + node->val,
            (rightTreeSum == INT_MIN ? 0 : rightTreeSum) + node->val);
        maxSoFar = std::max(maxSoFar, node->val);
        return maxSoFar;
    }
};

int main()
{
    Solution s;
    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    int result = s.maxPathSum(root);
    cout << "Max Path Sum: " << result << endl; // Expected output: 42

    root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    result = s.maxPathSum(root);
    cout << "Max Path Sum: " << result << endl; // Expected output: 6

    root = new TreeNode(0);
    result = s.maxPathSum(root);
    cout << "Max Path Sum: " << result << endl; // Expected output: 0

    root = new TreeNode(-2);
    root->left = new TreeNode(-1);
    result = s.maxPathSum(root);
    cout << "Max Path Sum: " << result << endl; // Expected output: -1


    // [9,6,-3,null,null,-6,2,null,null,2,null,-6,-6,-6]
    root = new TreeNode(9);
    root->left = new TreeNode(6);
    root->right = new TreeNode(-3);
    root->right->left = new TreeNode(-6);
    root->right->right = new TreeNode(2);
    root->right->right->right = new TreeNode(2);
    root->right->right->right->left = new TreeNode(-6);
    root->right->right->right->right = new TreeNode(-6);
    root->right->right->right->left->left = new TreeNode(-6);
    result = s.maxPathSum(root);
    cout << "Max Path Sum: " << result << endl; // Expected output: 16

    return 0;
}