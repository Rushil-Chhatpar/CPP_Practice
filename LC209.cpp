#include "headers.h"

using namespace std;

class Solution
{
public:
    int minSubArrayLen(int target, vector<int>& nums)
    {
        int sum = 0;
        int start = 0;
        int end = -1;
        int len = INT_MAX;
        while(end < (int)nums.size())
        {
            if(sum >= target)
            {
                sum -= nums[start];
                len = min(len, end - start + 1);
                start++;
            }
            else
            {
                end++;
                if(end >= (int)nums.size())
                {
                    break;
                }
                sum += nums[end];
            }
        }
        if(len == INT_MAX)
        {
            return 0;
        }
        return len;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1,1,1,1,1,1,1,1};
    int target = 11;
    cout << s.minSubArrayLen(target, nums) << endl; // Output: 2
    return 0;
}