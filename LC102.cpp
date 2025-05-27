// https://leetcode.com/problems/binary-tree-level-order-traversal/description/?envType=study-plan-v2&envId=top-interview-150
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
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        // level, array
        unordered_map<int, vector<int>> mp;
        traverse(root, mp, 0);
        vector<vector<int>> result;
        int index = 0;
        while(true)
        {
            if(mp.find(index) != mp.end())
            {
                result.push_back(std::move(mp[index]));
                index++;
            }
            else
                break;
        }
        return result;
    }
private:
    void traverse(TreeNode* node, unordered_map<int, vector<int>>& mp, int level)
    {
        if(!node)
            return;
        mp[level].push_back(node->val);
        traverse(node->left, mp, level + 1);
        traverse(node->right, mp, level + 1);
    }
};