#include "headers.h"

using namespace std;

class Solution
{
public:
    int findMinArrowShots(vector<vector<int>>& points)
    {
        std::sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b){ return a[1] < b[1];});
        int count = 1;
        int curr = points[0][1];
        for(int i = 1; i < points.size();i++)
        {
            if(points[i][0] <= curr)
                continue;
            else
            {
                count++;
                curr = points[i][1];
            }
        }
        return count;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> points = {{10,16},{2,8},{1,6},{7,12}};
    int result = s.findMinArrowShots(points);
    cout << result << endl; // Output: 2
    return 0;
}