// https://leetcode.com/problems/contains-duplicate-ii/description/?envType=study-plan-v2&envId=top-interview-150
#include "headers.h"

using namespace std;

class Solution
{
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k)
    {
        // num, index
        unordered_map<int, int> mp;
        for(size_t i = 0; i < nums.size(); i++)
        {
            if(mp.find(nums[i]) != mp.end())
            {
                if(abs((int)i - mp[nums[i]]) <= k)
                    return true;
            }
            mp[nums[i]] = i;
        }
        return false;
    }
};

int main()
{
    std::boolalpha(cout);
    Solution s;
    vector<int> nums = {1,2,3,1,2,3};
    cout << s.containsNearbyDuplicate(nums, 2) << endl;
    return 0;
}