// https://leetcode.com/problems/merge-intervals/description/?envType=study-plan-v2&envId=top-interview-150
#include "headers.h"

using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end());
        for(vector<int>& interval : intervals)
        {
            bool present = false;
            for(vector<int>& prevInt : result)
            {
                if(interval[0] >= prevInt[0] && interval[0] <= prevInt[1] && interval[1] >= prevInt[1])
                {
                    prevInt[1] = interval[1];
                    present = true;
                }
                else if(interval[0] >= prevInt[0] && interval[0] <= prevInt[1] && interval[1] <= prevInt[1])
                {
                    present = true;
                }
                else if(prevInt[0] >= interval[0] && prevInt[0] <= interval[1] && prevInt[1] >= interval[1])
                {
                    prevInt[0] = interval[0];
                    present = true;
                }
                else if(prevInt[0] >= interval[0] && prevInt[0] <= interval[1] && prevInt[1] <= interval[1])
                {
                    prevInt[0] = interval[0];
                    prevInt[1] = interval[1];
                    present = true;
                }
            }
            if(!present)
            result.push_back(interval);
        }
        return result;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> intervals = {
        {2,3},
        {4, 5},
        {6,7},
        {8,9},
        {1,10},
    };
    vector<vector<int>> result = s.merge(intervals);
    for(const auto& interval : result)
    {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;
    return 0;
}