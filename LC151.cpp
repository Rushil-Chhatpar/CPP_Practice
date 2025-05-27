// https://leetcode.com/problems/reverse-words-in-a-string/description/?envType=study-plan-v2&envId=top-interview-150
#include "headers.h"

using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        string result = "";
        int len = s.length();
        int start = len - 1;
        int end = len - 1;
        for(int i = len - 1; i >= 0; i--)
        {
            if(s[i] != ' ')
            {
                if(s[end] == ' ')
                    end = i;
                start = i;
            }
            else
            {
                if(s[start] != ' ')
                {
                    result += s.substr(start, end - start + 1) + " ";
                    end = i;
                    start = i;
                }
            }
            if(i == 0 && s[i] != ' ')
            {
                result += s.substr(start, end - start + 1) + " ";
            }
        }
        result = result.substr(0, result.length() - 1);
        return result;
    }
};

int main()
{
    Solution s;
    string st = "a good   example";
    cout << s.reverseWords(st) << endl;
    return 0;
}