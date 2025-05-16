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
    int removeDuplicates(vector<int>& nums)
    {
        int k = nums[0];
        int count = 0;
        auto it = nums.begin();
        while(it != nums.end())
        {
            if(*it == k)
            {
                count++;
                if(count > 2)
                {
                    it = nums.erase(it);
                    count--;
                }
                else
                {
                    ++it;
                }
            }
            else
            {
                k = *it;
                ++it;
                count = 1;
            }
        }
        return nums.size();
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1,1,1,2,2,3};
    int k = s.removeDuplicates(nums);
    cout << k << endl;
    for(auto i : nums)
        cout << i << " ";
    cout << endl;
    return 0;
}