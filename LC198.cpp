// https://leetcode.com/problems/house-robber/?envType=study-plan-v2&envId=top-interview-150
#include "headers.h"

using namespace std;

class Solution
{
public:
    int rob(vector<int>& nums)
    {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        vector<int> dp(n, 0);
        dp[n-1] = nums[n-1];
        dp[n-2] = nums[n-2];
        for(int i = n-3; i >= 0; i--)
        {
            int maxInd = i + 2;
            if(i + 3 < n)
            {
                if(dp[i + 3] >= dp[i + 2])
                    maxInd = i + 3;
                else
                    maxInd = i + 2;
            }
            dp[i] = nums[i] + dp[maxInd];
        }
        return max(dp[0], dp[1]);
    }
};

int main()
{
    Solution s;
    vector<int> nums = {6,6,4,8,4,3,3,10};
    cout << s.rob(nums) << endl;
    return 0;
}