// https://leetcode.com/problems/summary-ranges/description/?envType=study-plan-v2&envId=top-interview-150
#include "headers.h"

using namespace std;

class Solution
{
public:
    vector<string> summaryRanges(vector<int>& nums)
    {
        vector<string> result;
        if(nums.size() == 1)
        {
            result.push_back(to_string(nums[0]));
            return result;
        }
        int s = 0;
        int e = 0;
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] - 1 == nums[i-1])
            {
                e = i;
                if(i == nums.size() - 1)
                {
                    if(e == s)
                        result.push_back(to_string(nums[s]));
                    else
                        result.push_back(to_string(nums[s]) + "->" + to_string(nums[e]));
                }
            }
            else
            {
                if(e == s)
                    result.push_back(to_string(nums[s]));
                else
                    result.push_back(to_string(nums[s]) + "->" + to_string(nums[e]));
                s = i;
                e = i;
                if(i == nums.size() - 1)
                {
                    result.push_back(to_string(nums[i]));
                    break;
                }
            }
        }
        return result;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {0,2,3,4,6,8,9};
    s.summaryRanges(nums);
    return 0;
}