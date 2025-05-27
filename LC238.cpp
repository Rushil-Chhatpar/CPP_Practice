// https://leetcode.com/problems/product-of-array-except-self/description/?envType=study-plan-v2&envId=top-interview-150
#include "headers.h"

using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        const int n = static_cast<int>(nums.size());
        vector<int> result(n, 0);
        
        // create prefix array
        result[0] = nums[0];
        for(int i=1;i<n;i++)
        {
            result[i] = nums[i] * result[i-1];
        }

        int SSF = 1;
        for(int i = n-1;i>0;i--)
        {
            result[i] = result[i-1] * SSF;
            SSF *= nums[i];
        }
        result[0] = SSF;
        return result;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1,2,3,4};
    vector<int> result = s.productExceptSelf(nums);
    for(int& n : result)
    {
        cout << n << ", ";
    }
    cout <<endl;
    return 0;
}