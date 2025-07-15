#include "headers.h"

using namespace std;

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        if(needle.empty())
            return 0;
        if(haystack.empty())
            return needle.empty() ? 0 : -1;
        int nl = needle.length();
        int hl = haystack.length();
        if(nl > hl)
            return -1;
        
        for(int i = 0; i < haystack.length(); i++)
        {
            if(needle[0] == haystack[i])
            {
                string str = haystack.substr(i, nl);
                if(str == needle)
                    return i;
            }
        }
        return -1;
    }
};

int main()
{
    Solution s;
    cout << s.strStr("hello", "ll") << endl; // Output: 2
    cout << s.strStr("aaaaa", "bba") << endl; // Output: -1
    cout << s.strStr("", "") << endl; // Output: 0
    cout << s.strStr("abc", "c") << endl; // Output: 2
    return 0;
}