// https://leetcode.com/problems/maximum-depth-of-binary-tree/description/?envType=study-plan-v2&envId=top-interview-150
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
    int maxDepth(TreeNode* root)
    {
        if(!root)
            return 0;
        int level = 1;
        int max = 1;
        returnDepth(root, level, max);
        return max;
    }
private:

    void returnDepth(TreeNode* node, int& level, int& max)
    {
        max = std::max(level, max);
        if(node->left)
        {
            level++;
            returnDepth(node->left, level, max);
        }
        if(node->right)
        {
            level++;
            returnDepth(node->right, level, max);
        }
        level--;
        return;
    }
};