#include "headers.h"

using namespace std;

class Solution 
{
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        std::sort(nums.begin(), nums.end());

        vector<vector<int>> result;
        int n = nums.size();

        for(int i = 0; i < n; i++)
        {
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            
            int j = i + 1;
            int k = n - 1;
            int target = -nums[i];
            while(j < k)
            {
                if(nums[j] + nums[k] == target)
                {
                    result.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    while(nums[j] == nums[j-1] && j < k)
                        j++;
                }
                else if(nums[j] + nums[k] > target)
                    k--;
                else
                    j++;
            }
        }
        return result;
    }
};


int main()
{
    Solution s;
    vector<int> nums1 = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result1 = s.threeSum(nums1);
    for(const auto& triplet : result1)
    {
        cout << "[" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "] ";
    }
    cout << endl;

    vector<int> nums2 = {0, 0, 0};
    vector<vector<int>> result2 = s.threeSum(nums2);
    for(const auto& triplet : result2)
    {
        cout << "[" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "] ";
    }
    cout << endl;

    return 0;
}