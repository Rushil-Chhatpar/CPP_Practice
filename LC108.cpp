// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/?envType=study-plan-v2&envId=top-interview-150
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
    TreeNode* sortedArrayToBST(vector<int>& nums)
    {
        if(nums.size() == 0)
            return nullptr;
        TreeNode* head = binaryTraversal(nums, 0, nums.size() - 1);
        return head;
    }
private:
    TreeNode* binaryTraversal(vector<int>& nums, int start, int end)
    {
        if(start > end)
            return nullptr;
        int mid = start + (end - start) /2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = binaryTraversal(nums, start, mid - 1);
        node->right = binaryTraversal(nums, mid + 1, end);
        return node;
    }

    // TreeNode* sortedArrayToBST(vector<int>& nums)
    // {
    //     if(nums.size() == 0)
    //         return nullptr;
        
    //     int mid = nums.size() / 2;
    //     TreeNode* root = new TreeNode(nums[mid]);
    //     if(mid == 0)
    //         return root;
        
        
    //     // left
    //     TreeNode* current = root;
    //     for(int i = mid - 1;i>=0;i--)
    //     {
    //         current->left = new TreeNode(nums[i]);
    //         current = current->left;
    //     }

    //     // right
    //     if(mid + 1 == nums.size())
    //         return root;
    //     root->right = new TreeNode(nums[nums.size() - 1]);
    //     current = root->right;
    //     for(int i = nums.size() - 2; i > mid; i--)
    //     {
    //         current->left = new TreeNode(nums[i]);
    //         current = current->left;
    //     }

    //     return root;
    // }
};

int main()
{
    return 0;
}