#include "headers.h"

using namespace std;

class Solution
{
public:
    int maxArea(vector<int>& height)
    {
        int left = 0;
        int right = height.size() - 1;
        int max = 0;
        while (left < right)
        {
            int water = min(height[right], height[left]) * (right - left);
            max = std::max(max, water);
            if (height[left] < height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return max;
    }
};

int main()
{
    Solution s;
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << s.maxArea(height) << endl; // Output: 49
    return 0;
}