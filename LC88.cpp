#include "headers.h"

using namespace std;

class Solution
{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        int i = 0;
        int j = 0;
        while(i < m && j < n)
        {
            if(nums1[i] <= nums2[j])
            {
                i++;
            }
            else
            {
                nums1.insert(nums1.begin() + i, nums2[j]);
                nums1.pop_back();
                j++;
                m++;
                i++;
            }
        }
        while(j < n)
        {
            nums1[i] = nums2[j];
            i++;
            j++;
        }
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};
    s.merge(nums1, 3, nums2, 3);
    for(int i=0;i<nums1.size();i++)
    {
        cout << nums1[i] << " ";
    }
    cout << endl;

    nums1 = {0};
    nums2 = {1};
    s.merge(nums1, 0, nums2, 1);
    for(int i=0;i<nums1.size();i++)
    {
        cout << nums1[i] << " ";
    }
    cout << endl;

    return 0;
}