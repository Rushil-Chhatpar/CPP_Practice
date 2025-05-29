// https://leetcode.com/problems/number-of-islands/description/?envType=study-plan-v2&envId=top-interview-150
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
    int numIslands(vector<vector<char>>& grid)
    {
        int islands = 0;
        // height
        int m = grid.size();
        // width
        int n = grid[0].size();
        unordered_set<int> closedList;
        queue<int> q;
        array<ivec2, 4> dirs{ivec2(0, 1), ivec2(1, 0), ivec2(0, -1), ivec2(-1, 0)};

        for(int j = 0; j < m; j++)
        {
            for(int i = 0;i < n; i++)
            {
                // y * width + x
                int index = j * n + i;
                if(grid[j][i] == '0' || closedList.count(index) == 1)
                    continue;
                q.emplace(index);
                closedList.insert(index);
                while(!q.empty())
                {
                    int ind = q.front();
                    q.pop();
                    int x = ind % n;
                    int y = ind / n;
                    for(ivec2& dir : dirs)
                    {
                        int nx = x + dir.x;
                        int ny = y + dir.y;
                        int nIndex = ny * n + nx;
                        if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[ny][nx] == '1' && closedList.count(nIndex) == 0)
                        {
                            q.emplace(nIndex);
                            closedList.insert(nIndex);
                        }
                    }
                }
                islands++;
            }
        }
        return islands;
    }
};

int main()
{
    Solution solution;
    // "1","0","1","1","0","1","1"
    vector<vector<char>> grid = {
        {'1', '0', '1', '1', '0', '1', '1'}
    };
    int result = solution.numIslands(grid);
    cout << "Number of islands: " << result << endl; // Output: 3
    return 0;
}