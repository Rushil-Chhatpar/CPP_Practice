// https://leetcode.com/problems/add-binary/?envType=study-plan-v2&envId=top-interview-150
#include "headers.h"

using namespace std;

class Solution
{
public:
    string addBinary(string a, string b)
    {
        int i = a.length() - 1;
        int j = b.length() -1;
        int c = 0;
        string sum = "";
        while(i >= 0 || j >= 0 || c)
        {
            if( i >= 0)
            {
                c += (a[i] - '0');
                i--;
            }
            if(j >= 0)
            {
                c+= (b[j] - '0');
                j--;
            }
            sum += (c % 2) + '0';
            c/= 2;
        }
        reverse(sum.begin(), sum.end());
        return sum;
    }
};

int main()
{
    Solution s;
    string a = "1010";
    string b = "1011";
    cout << s.addBinary(a, b) << endl;
    return 0;
}