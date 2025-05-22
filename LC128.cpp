// https://leetcode.com/problems/longest-consecutive-sequence/?envType=study-plan-v2&envId=top-interview-150
#include "headers.h"

using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int>& nums)
    {
        unordered_set<int> set(nums.begin(), nums.end());
        int max = 0;
        for(int num : set)
        {
            if(set.find(num - 1) == set.end())
            {
                int len = 1;
                while(set.find(num + len) != set.end())
                {
                    len++;
                }
                max = std::max(max, len);
            }
        }


        return max;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {0,3,7,2,5,8,4,6,0,1};
    cout << s.longestConsecutive(nums) << endl;
    return 0;
}