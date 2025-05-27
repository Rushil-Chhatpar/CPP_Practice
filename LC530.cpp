// https://leetcode.com/problems/minimum-absolute-difference-in-bst/?envType=study-plan-v2&envId=top-interview-150
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
    int getMinimumDifference(TreeNode* root)
    {
        vector<int> nums;
        int res = INT_MAX;
        traverse(root, nums, res);
        return res;
    }
    void traverse(TreeNode* node, vector<int>& nums, int& res)
    {
        if(!node)
            return;
        traverse(node->left, nums, res);
        nums.push_back(node->val);
        int n = nums.size();
        if(n > 1)
        {
            res = min(res, abs(nums[n-1] - nums[n-2]));
        }
        traverse(node->right, nums, res);
    }
};

int main()
{
    Solution s;
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(7);
    int result = s.getMinimumDifference(root);
    cout << "Minimum Absolute Difference: " << result << endl; // Expected output: 1
    return 0;
}