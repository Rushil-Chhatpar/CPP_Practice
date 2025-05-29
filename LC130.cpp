// https://leetcode.com/problems/surrounded-regions/description/?envType=study-plan-v2&envId=top-interview-150
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
    void solve(vector<vector<char>>& board)
    {
        int height = board.size();
        int width = board[0].size();
        unordered_set<int> closedList;
        queue<int> q;
        array<ivec2, 4> dirs{ivec2(0, 1), ivec2(1, 0), ivec2(0, -1), ivec2(-1, 0)};
        
        for(int y = 0; y < height; y++)
        {
            for(int x = 0;x < width; x++)
            {
                // y * width + x
                int index = y * width + x;
                if(board[y][x] == 'X' || closedList.count(index) == 1)
                    continue;
                q.emplace(index);
                closedList.insert(index);
                bool surrounded = true;
                if(x == 0 || x == width - 1 || y == 0 || y == height -1)
                    surrounded = false;
                vector<int> indices;
                while(!q.empty())
                {
                    int ind = q.front();
                    q.pop();

                    indices.push_back(ind);

                    int currentX = ind % width;
                    int currentY = ind / width;
                    for(ivec2& dir : dirs)
                    {
                        int nx = currentX + dir.x;
                        int ny = currentY + dir.y;
                        int nIndex = ny * width + nx;
                        if(nx >= 0 && nx < width && ny >= 0 && ny < height && board[ny][nx] == 'O' && closedList.count(nIndex) == 0)
                        {
                            q.emplace(nIndex);
                            closedList.insert(nIndex);
                            
                            if(nx == 0 || nx == width - 1 || ny == 0 || ny == height -1)
                                surrounded = false;
                        }
                    }
                }
                if(surrounded)
                {
                    for(int& ind : indices)
                    {
                        int X = ind % width;
                        int Y = ind / width;
                        board[Y][X] = 'X';
                    }
                }
            }
        }
    }
};

int main()
{
    Solution s;
    // [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
    vector<vector<char>> board = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}
    };
    s.solve(board);
    for(const auto& row : board)
    {
        for(const auto& cell : row)
        {
            cout << cell << " ";
        }
        cout << endl;
    }
    return 0;
}