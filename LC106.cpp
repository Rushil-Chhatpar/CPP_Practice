// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/?envType=study-plan-v2&envId=top-interview-150
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        size_t n = postorder.size();
        // inorder number, inorder index
        unordered_map<int, int> mp;
        for(size_t i = 0; i < n; i++)
        {
            mp[inorder[i]] = i;
        }

        int postIndex = n-1;
        TreeNode* head = treeBuild(postorder, 0, n - 1, mp, postIndex);
        return head;
    }
private:
    TreeNode* treeBuild(vector<int>& postorder, int start, int end, unordered_map<int, int>& mp, int& postIndex)
    {
        if( start > end)
            return nullptr;
        
        TreeNode* node = new TreeNode(postorder[postIndex]);
        postIndex--;

        int inorIndex = mp[node->val];

        node->right = treeBuild(postorder, inorIndex + 1, end, mp, postIndex);
        node->left = treeBuild(postorder, start, inorIndex - 1, mp, postIndex);
        return node;
    }
};

int main()
{
    Solution s;
    vector<int> inorder = { 9,3,15,20,7 };
    vector<int> postorder = { 9,15,7,20,3 };
    s.buildTree(inorder, postorder);
    return 0;
}