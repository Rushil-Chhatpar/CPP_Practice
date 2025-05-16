#include <stdexcept>
#include <iostream>
#include <array>
#include <chrono>
#include <cstdlib>
#include <cstring>
#include <numeric>
#include <memory>
#include <string>
#include <vector>
#include <array>
#include <list>
#include <map>
#include <set>
#include <limits>
#include <stdexcept>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool canJump(vector<int>& nums)
    {
        // use dp
        uint8_t dp[nums.size()];
        memset(dp, 0, sizeof(dp)); 
        int dest = nums.size() - 1;
        dp[nums.size() - 1] = 1; // last index is true
        for(int i = nums.size() - 2; i >=0; i--)
        {
            if(nums[i] >= dest - i && nums[i] != 0)
            {
                dp[i] = 1;
                dest = i;
            }
            else
            {
                dp[i] = 0;
            }
        }
        return dp[0];
    }
};

int main()
{
    Solution s;
    vector<int> nums = {2,3,1,1,4};
    bool k = s.canJump(nums);
    std::boolalpha(cout);
    cout << k << endl;

    nums = {3,2,1,0,4};
    k = s.canJump(nums);
    cout << k << endl;

    nums = {2, 0};
    k = s.canJump(nums);
    cout << k << endl;

    return 0;
}
