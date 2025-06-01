// https://leetcode.com/problems/search-a-2d-matrix/description/?envType=study-plan-v2&envId=top-interview-150
#include "headers.h"

using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        int width = matrix[0].size();
        int height = matrix.size();
        int n = width * height;
        int s = 0;
        int e = n - 1;
        while(s <= e)
        {
            int mid = s + (e - s)/2;
            int x = mid % width;
            int y = mid / width;
            if(matrix[y][x] == target)
                return true;
            if(target < matrix[y][x])
                e = mid - 1;
            else
                s = mid + 1;
        }
        return false;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> matrix = {{1}, {3}};
    boolalpha(cout);
    cout << s.searchMatrix(matrix, 2) << endl;
    return 0;
}