#include "headers.h"

using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {
        if(numRows == 1)
        return s; // If there's only one row, return the string as is.
        
        int n = s.length();
        int col = 0;
        int rem = n;
        while(rem > 0)
        {
            rem -= numRows;
            col++;
            for(int i = 0; i < numRows - 2; i++)
            {
                if(rem == 0)
                    break;
                col++;
                rem--;
            }
        }
        std::vector<std::vector<char>> pattern{static_cast<size_t>(numRows), std::vector<char>(col, '\0')};
        
        int r = 0;
        int c = 0;
        bool goingDown = true;
        for(char ch : s)
        {
            pattern[r][c] = ch;
            if(goingDown)
            {
                r++;
                if(r == numRows - 1)
                    goingDown = false;
            }
            else
            {
                r--;
                c++;
                if(r == 0)
                    goingDown = true;
            }
        }
        string result;
        for(int i = 0; i < numRows; i++)
        {
            for(int j = 0; j < col; j++)
            {
                if(pattern[i][j] != '\0')
                    result += pattern[i][j];
            }
        }
        return result;
    }
};


int main()
{
    Solution solution;
    string s = "PAYPALISHIRING";
    int numRows = 3;
    string result = solution.convert(s, numRows);
    cout << "Converted string: " << result << endl; // Output: "PAHNAPLSIIGYIR"

    // Additional test case
    s = "A";
    numRows = 1;
    result = solution.convert(s, numRows);
    cout << "Converted string for single character: " << result << endl; // Output: "A"

    // Another test case
    s = "PAYPALISHIRING";
    numRows = 4;
    result = solution.convert(s, numRows);
    cout << "Converted string with 4 rows: " << result << endl; // Output: "PINALSIGYAHRPI"

    // Edge case 
    s = "AB";
    numRows = 1;
    result = solution.convert(s, numRows);
    cout << "Converted string with more rows than characters: " << result << endl; // Output: "AB"
    return 0;
}