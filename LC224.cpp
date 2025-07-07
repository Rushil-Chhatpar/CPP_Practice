#include "headers.h"

using namespace std;

class Solution
{
public:
    int calculate(string s)
    {
        int index = 0;
        return result(s, index);
    }

private:
    int result(string& s, int& index)
    {
        int num = 0;
        char op = ' ';
        while(index < s.length())
        {
            char c = s[index];
            if(c == ' ')
            {
                index++;
                continue;
            }
            else if(c == '+')
            {
                op = '+';
            }
            else if(c == '-')
            {
                op = '-';
            }
            else if(c == ')')
            {
                return num;
            }
            else if(c == '(')
            {
                int curNum = result(s, ++index);
                if(op == '-' && num == 0)
                {
                    num = -curNum;
                    op = ' ';
                }
                else if(op == '+')
                {
                    num += curNum;
                    op = ' ';
                }
                else if(op == '-')
                {
                    num -= curNum;
                    op = ' ';
                }
                else
                {
                    num = curNum;
                }
            }
            else
            {
                int curNum = ((int)c - 48);
                // if prev char is also a digit, we need to combine them
                if(index > 0 && isdigit(s[index - 1]))
                {
                    num *= 10;
                    num += curNum;
                    if(index + 1 < s.length())
                    {
                        if(isdigit(s[index + 1]))
                        {
                            index++;
                            continue;
                        }
                    }
                    else
                    {
                        return num;
                    }
                }

                bool Op = true;
                // if next char is also a digit, we need to not perform any operation yet
                if(index + 1 < s.length() && isdigit(s[index + 1]))
                {
                    Op = false;
                }

                if(op == '-' && num == 0 && Op)
                {
                    num = -curNum;
                    op = ' ';
                }
                else if(op == '+' && Op)
                {
                    num += curNum;
                    op = ' ';
                }
                else if(op == '-' && Op)
                {
                    num -= curNum;
                    op = ' ';
                }
                else if(num == 0)
                {
                    num = curNum;
                }
            }
            index++;
        }
        return num;
    }
};

int main()
{
    Solution s;
    string input = "1 + 1";
    cout << s.calculate(input) << endl; // Output: 2
    input = " 2-1 + 2 ";
    cout << s.calculate(input) << endl; // Output: 3
    input = "(1+(4+5+2)-3)+(6+8)";
    cout << s.calculate(input) << endl; // Output: 23
    input = "1-(4-5)";
    cout << s.calculate(input) << endl; // Output: 2
    input = "1-11";
    cout << s.calculate(input) << endl; // Output: 2147483647
    return 0;
}