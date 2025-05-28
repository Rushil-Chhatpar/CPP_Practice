// https://leetcode.com/problems/rotate-image/description/?envType=study-plan-v2&envId=top-interview-150
#include "headers.h"

using namespace std;

class Solution
{
public:
    void rotate(vector<vector<int>>& matrix)
    {
        // transpose first
        int n = matrix.size();
        for(int j = 0; j < n; j++)
        {
            for(int i = j; i < n; i++)
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        // mirror the matrix horizontally
        int mid = n/2;
        for(int i = 0, j = n-1; i < mid; i++, j--)
        {
            for(int k = 0; k < n; k++)
            {
                int temp = matrix[k][i];
                matrix[k][i] = matrix[k][j];
                matrix[k][j] = temp;
            }   
        }
    }
};

int main()
{
    // [[1,2,3],[4,5,6],[7,8,9]]
    Solution s;
    vector<vector<int>> m = {{1,2,3},{4,5,6},{7,8,9}};
    s.rotate(m);
    for(const auto& row : m)
    {
        for(int num : row)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}