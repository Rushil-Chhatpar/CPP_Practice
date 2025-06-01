// https://leetcode.com/problems/search-insert-position/description/?envType=study-plan-v2&envId=top-interview-150
#include "headers.h"

using namespace std;

class Solution
{
public:
    int searchInsert(vector<int>& nums, int target)
    {
        int n = nums.size();
        if(target > nums[n-1])
            return n;
        else if(target < nums[0])
            return 0;
        
        int s = 0;
        int e = n - 1;
        while(s <= e)
        {
            int mid = s + (e - s)/2;
            if(nums[mid] == target)
                return mid;
                
            if(target < nums[mid])
            {
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
        return s;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1,2,4,6,7};
    cout << s.searchInsert(nums, 3) << endl;
    return 0;
}