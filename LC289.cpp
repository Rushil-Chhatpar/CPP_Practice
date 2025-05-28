// https://leetcode.com/problems/game-of-life/description/?envType=study-plan-v2&envId=top-interview-150
#include "headers.h"

using namespace std;

class Solution
{
public:
    Solution()
    {
        directions.push_back(ivec2(-1, -1));
        directions.push_back(ivec2(-1, 0));
        directions.push_back(ivec2(-1, 1));
        directions.push_back(ivec2(0, -1));
        directions.push_back(ivec2(0, 1));
        directions.push_back(ivec2(1, -1));
        directions.push_back(ivec2(1, 0));
        directions.push_back(ivec2(1, 1));
    }
    enum Type
    {
        ztz = 0,
        oto,
        zto,
        otz,
    };

    void gameOfLife(vector<vector<int>>& board)
    {
        int m = board.size();
        int n = board[0].size();
        for(int i = 0; i < m; i++)
        {
            for(int j = 0;j < n; j++)
            {
                int num = neighbours(board, i, j);
                if(num < 2 && board[i][j] == 1)
                {
                    board[i][j] = otz;
                }
                else if((num == 2 || num == 3) && board[i][j] == 1)
                {
                    board[i][j] = oto;
                }
                else if(num > 3 && board[i][j] == 1)
                {
                    board[i][j] = otz;
                }
                else if(num == 3 && board[i][j] == 0)
                {
                    board[i][j] = zto;
                }
                else
                {
                    board[i][j] = ztz;
                }
            }
        }
        for(int i = 0; i < m; i++)
        {
            for(int j = 0;j < n; j++)
            {
                if(board[i][j] == ztz)
                    board[i][j] = 0;
                else if(board[i][j] == oto)
                    board[i][j] = 1;
                else if(board[i][j] == zto)
                    board[i][j] = 1;
                else if(board[i][j] == otz)
                    board[i][j] = 0;
            }
        }
    }
private:
    struct ivec2
    {
        int x;
        int y;
        ivec2(int x, int y)
            : x(x)
            , y(y)
        {}
    };

    vector<ivec2> directions;

    int neighbours(vector<vector<int>>& board, int r, int c)
    {
        int m = board.size();
        int n = board[0].size();
        int num = 0;
        for(ivec2& direction : directions)
        {
            int nr = r + direction.x;
            int nc = c + direction.y;
            if(nr >= 0 && nr < m && nc >=0 && nc < n)
            {
                if(board[nr][nc] == otz || board[nr][nc] == oto)
                    num++;
            }
        }
        return num;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> board = {
        {0, 1, 0},
        {0, 0, 1},
        {1, 1, 1},
        {0, 0, 0}
    };
    s.gameOfLife(board);
    for(const auto& row : board)
    {
        for(int num : row)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}