// https://leetcode.com/problems/invert-binary-tree/description/?envType=study-plan-v2&envId=top-interview-150
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
    TreeNode* invertTree(TreeNode* root)
    {
        // if(!root)
        //     return nullptr;
        // swapAndPass(root->left, root->right);
        // return root;
        if(!root)
            return nullptr;
        
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
private:
    void swapAndPass(TreeNode* left, TreeNode* right)
    {
        if(!left && right)
        {
            left = new TreeNode(right->val);
            swapAndPass(left->left, right->right);
            swapAndPass(left->right, right->left);
            delete right;
            right = nullptr;
        }
        else if(left && !right)
        {
            right = new TreeNode(left->val);
            swapAndPass(left->left, right->right);
            swapAndPass(left->right, right->left);
            delete left;
            left = nullptr;
        }
        else if(!left && !right)
        {
            return;
        }
        else
        {
            int temp = left->val;
            left->val = right->val;
            right->val = temp;
            swapAndPass(left->left, right->right);
            swapAndPass(left->right, right->left);
        }
    }
};