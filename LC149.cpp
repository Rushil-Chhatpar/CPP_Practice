#include "headers.h"

using namespace std;

class Solution
{
public:
    int maxPoints(vector<vector<int>>& points)
    {
        int n = points.size();
        if(n <= 2)
            return n;
        int result = 0;

        for(const vector<int>& point1 : points)
        {
            unordered_map<double, int> dp;
            const vector<double> point1_dbl = {static_cast<double>(point1[0]), static_cast<double>(point1[1])};
            for(const vector<int>& point2 : points)
            {
                const vector<double> point2_dbl = {static_cast<double>(point2[0]), static_cast<double>(point2[1])};
                if(point1_dbl == point2_dbl)
                    continue;
                
                double slp = slope(point1_dbl, point2_dbl);
                dp[slp]++;
                result = max(result, dp[slp]);
            }
        }
        return result + 1; // +1 for the point itself
    }
private:
    double slope(const vector<double>& point1, const vector<double>& point2)
    {
        if(point1[0] - point2[0] == 0)
            return numeric_limits<double>::infinity(); // vertical line
        return (point1[1] - point2 [1]) / (point1[0] - point2[0]);
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> points = {{1,1},{2,2},{3,3}};
    int result = solution.maxPoints(points);
    cout << "Maximum points on a line: " << result << endl; // Output: 3

    points = {{1,1},{3,2},{5,3},{4,1},{2,3},{1,4}};
    result = solution.maxPoints(points);
    cout << "Maximum points on a line: " << result << endl; // Output: 4

    return 0;
}