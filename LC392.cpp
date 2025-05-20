#include "headers.h"

using namespace std;

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int n = s.length();
        int m = t.length();
        if (n == 0)
        {
            return true;
        }
        if (m == 0)
        {
            return false;
        }
        int index = 0;
        for(int i=0;i<m;i++)
        {
            if (t[i] == s[index])
            {
                index++;
                if (index == n)
                {
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    std::boolalpha(cout);
    Solution s;
    string str1 = "abc";
    string str2 = "ahbgdc";
    bool k = s.isSubsequence(str1, str2);
    cout << k << endl;

    str1 = "axc";
    str2 = "ahbgdc";
    cout << s.isSubsequence(str1, str2) << endl;

    return 0;
}