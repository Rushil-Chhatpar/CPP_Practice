#include "headers.h"

using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int>>& matrix)
    {
        unordered_set<int> rows;
        unordered_set<int> columns;

        int m = matrix.size();
        int n = matrix[0].size();

        for(int j = 0; j < m; j++)
        {
            for(int i = 0; i < n; i++)
            {
                if(matrix[j][i] == 0)
                {
                    rows.insert(j);
                    columns.insert(i);
                }
            }
        }
        for(const int& row : rows)
        {
            for(int i = 0; i < n; i++)
            {
                matrix[row][i] = 0;
            }
        }
        for(const int& column : columns)
        {
            for(int j = 0; j < m; j++)
            {
                matrix[j][column] = 0; 
            }
        }
    }
};