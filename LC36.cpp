// https://leetcode.com/problems/valid-sudoku/description/?envType=study-plan-v2&envId=top-interview-150
#include "headers.h"

using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>>& board)
    {
        array<unordered_set<char>, 9> rows;
        array<unordered_set<char>, 9> columns;
        array<unordered_set<char>, 9> boxes;

        for(int r = 0; r < 9; r++)
        {
            for(int c = 0; c < 9; c++)
            {
                char num = board[r][c];
                if(num == '.')
                    continue;
                // use x * width + y formula
                int boxIndex = (c/3) * 3 + (r/3);
                if(rows[r].count(num) || columns[c].count(num) || boxes[boxIndex].count(num))
                    return false;
                rows[r].insert(num);
                columns[c].insert(num);
                boxes[boxIndex].insert(num);
            }
        }
        return true;
    }
};