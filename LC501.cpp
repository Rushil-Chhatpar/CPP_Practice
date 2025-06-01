// https://leetcode.com/problems/find-mode-in-binary-search-tree/description/?envType=problem-list-v2&envId=binary-search-tree
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
    vector<int> findMode(TreeNode* root)
    {
        vector<int> result;
        if(!root)
            return result;
        int prev = INT_MIN;
        int count = 0;
        int max = INT_MIN;
        traverse(root, max, count, prev, result);
        return result;
    }
private:
    void traverse(TreeNode* node, int& max, int& count, int& prev, vector<int>& result)
    {
        if(!node)
            return;
        traverse(node->left, max, count, prev, result);
        if(node->val == prev)
        {
            count++;
            if(count > max)
            {
                max = count;
                result.clear();
                result.push_back(node->val);
            }
            else if(count == max)
            {
                result.push_back(node->val);
            }
        }
        else
        {
            count = 1;
            prev = node->val;
            if(count > max)
            {
                max = count;
                result.clear();
                result.push_back(node->val);
            }
            else if(count == max)
            {
                result.push_back(node->val);
            }
        }
        traverse(node->right, max, count, prev, result);
    }
};

int main()
{
    Solution s;

    TreeNode* root = new TreeNode(0);
    vector<int> modes = s.findMode(root);
    for(int mode : modes)
    {
        cout << mode << " ";
    }
    cout << endl;
    return 0;
}