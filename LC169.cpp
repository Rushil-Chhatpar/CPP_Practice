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
    int majorityElement(vector<int>& nums)
    {
        int halfSize = nums.size() / 2;
        std::sort(nums.begin(), nums.end());
        int count = 1;
        for(int i = 0;i<nums.size();i++)
        {
            if(i < nums.size() - 1 && nums[i] == nums[i+1])
            {
                count++;
            }
            else
            {
                if(count > halfSize)
                {
                    return nums[i];
                }
                count = 1;
            }
        }
        return -1;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {2,2,1,1,1,2,2};
    int k = s.majorityElement(nums);
    cout << k << endl;

    return 0;
}