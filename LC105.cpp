// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/?envType=study-plan-v2&envId=top-interview-150
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        // inorder number, inorder index
        unordered_map<int, int> mp;
        for(int i = 0; i < inorder.size(); i++)
        {
            mp[inorder[i]] = i;
        }
        int preIndex = 0;
        TreeNode* head = treeBuild(preorder, 0, preorder.size() - 1, mp, preIndex);
        return head;
    }
private:
    TreeNode* treeBuild(vector<int>& preorder, int start, int end, unordered_map<int, int>& mp, int& preIndex)
    {
        if(start > end)
            return nullptr;
        
        TreeNode* node = new TreeNode(preorder[preIndex]);
        preIndex++;

        int inorIndex = mp[node->val];

        node->left = treeBuild(preorder, start, inorIndex - 1, mp, preIndex);
        node->right = treeBuild(preorder, inorIndex + 1, end, mp, preIndex);
        return node;
    }
};

int main()
{
    Solution s;
    vector<int> inorder = { 4, 2, 1, 7, 5, 8, 3, 6 };
    vector<int> preorder = { 1, 2, 4, 3, 5, 7, 8, 6 };
    s.buildTree(preorder, inorder);
    return 0;
}