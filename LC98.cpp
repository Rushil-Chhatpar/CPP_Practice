// https://leetcode.com/problems/validate-binary-search-tree/description/?envType=study-plan-v2&envId=top-interview-150
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
    bool isValidBST(TreeNode* root)
    {
        // do inorder traversal
        TreeNode* prev = nullptr;
        return traverse(root, prev);
    }
private:
    bool traverse(TreeNode* node, TreeNode*& prev)
    {
        if(!node)
            return true;
        if(!traverse(node->left, prev))
            return false;
        if(prev)
        {
            if(prev->val >= node->val)
                return false;
        }
        prev = node;
        if(!traverse(node->right, prev))
            return false;
        return true;
    }
};

int main()
{
    Solution s;
    // [5,4,6,null,null,3,7]
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(6);
    root->right->left = new TreeNode(3); // This will make it invalid
    root->right->right = new TreeNode(7);
    bool result = s.isValidBST(root);
    cout << "Is Valid BST: " << (result ? "true" : "false") << endl; // Expected output: false
}