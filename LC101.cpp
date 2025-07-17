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
    bool isSymmetric(TreeNode* root)
    {
        return dualTraversal(root->left, root->right);
    }
private:
    bool dualTraversal(TreeNode* left, TreeNode* right)
    {
        if(!left && !right)
            return true;

        if((!left && right) || (left && !right) || (left->val != right->val))
            return false;

        if(!dualTraversal(left->left, right->right))
            return false;
        if(!dualTraversal(left->right, right->left))
            return false;

        return true;
    }
};

int main()
{
    boolalpha(cout);
    Solution s;
    TreeNode* root1 = new TreeNode(1, new TreeNode(2, new TreeNode(3), new TreeNode(4)), new TreeNode(2, new TreeNode(4), new TreeNode(3)));
    cout << (s.isSymmetric(root1) ? "true" : "false") << endl; // Expected: true

    TreeNode* root2 = new TreeNode(1, new TreeNode(2, nullptr, new TreeNode(3)), new TreeNode(2, nullptr, new TreeNode(3)));
    cout << (s.isSymmetric(root2) ? "true" : "false") << endl; // Expected: false

    return 0;
}