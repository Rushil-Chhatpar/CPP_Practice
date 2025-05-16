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
    void rotate(vector<int>& nums, int k)
    {
        int n = nums.size();
        if(k == 0 || n == 0 || n == 1 || k == n)
            return;

        k = k % n; // Handle cases where k is greater than n
        
        // below is one way to do it. super simple and easy
        // reverse(nums.begin(), nums.end());
        // reverse(nums.begin(), nums.begin() + k);
        // reverse(nums.begin() + k, nums.end());

        // my way to do it
        int j = n - k;
        for(int i = 0; i < n; i++)
        {
            if(j >= n)
            {
                if(i >= (n - k))
                    break;
                j = n - k;
            }
            if (i < j)
            {
                swap(nums[i], nums[j]);
                j++;
            }
            else
            {
                j = i + 1;
                if (j >= n)
                {
                    j = i;
                }
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27};
    int k = 38;
    s.rotate(nums, k);
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}

// 1,2,3 | k = 4