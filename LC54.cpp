// https://leetcode.com/problems/spiral-matrix/description/?envType=study-plan-v2&envId=top-interview-150
#include "headers.h"

using namespace std;

class Solution
{
    struct ivec2
    {
        int x;
        int y;
        ivec2(int x, int y)
            : x(x)
            , y(y)
        {}
    };
    enum Direction : int
    {
        right = 0,
        down = 1,
        left = 2,
        up = 3,
        numOfDir = 4,
    };
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        vector<int> result;
        int dir = right;
        array<ivec2, 4> dirs{ivec2(0, 1), ivec2(1, 0), ivec2(0, -1), ivec2(-1, 0)};
        int m = matrix.size();
        int n = matrix[0].size();
        int i = 0;
        int j = 0;
        int total = m * n;

        while(result.size() < total)
        {
            result.push_back(matrix[i][j]);
            matrix[i][j] = _invalid;
            if(!isNextValid(matrix, i + dirs[dir].x, j + dirs[dir].y, m, n))
            {
                dir = (dir + 1) % Direction::numOfDir;
            }
            i += dirs[dir].x;
            j += dirs[dir].y;
        }

        return result;
    }
private:
    static constexpr int _invalid = 101;
    bool isNextValid(vector<vector<int>>& matrix, int i, int j, const int& m, const int& n)
    {
        if(i >= m || i < 0 || j >= n || j < 0 || matrix[i][j] == _invalid)
            return false;
        return true;
    }
};

int main()
{
    return 0;
}