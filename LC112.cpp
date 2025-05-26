// https://leetcode.com/problems/path-sum/description/?envType=study-plan-v2&envId=top-interview-150
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
    bool hasPathSum(TreeNode* root, int targetSum)
    {
        if(!root)
            return false;
        // if(!root->left || !root->right)
        // {
        //     if(targetSum == root->val)
        //         return true;
        // }
        int target = targetSum;
        return hasSum(root, target, 0);
    }
private:
    bool hasSum(TreeNode* node, int& target, int sum)
    {
        sum += node->val;
        if(target == sum && !node->left && !node->right)
            return true;
        if(!node->left && !node->right)
            return false;
        if(!node->left || !hasSum(node->left, target, sum))
        {
            return node->right && hasSum(node->right, target, sum);
        }
        return true;
    }
};

int main()
{
    Solution s;
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(1);
    
    cout << s.hasPathSum(root, 22) << endl; // Output: 1 (true)

    root = new TreeNode(-2);
    root->right = new TreeNode(-3);

    cout << s.hasPathSum(root, -2) << endl; // Output: 0 (false)
    
    return 0;
}