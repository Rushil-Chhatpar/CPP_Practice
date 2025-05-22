#include "headers.h"

using namespace std;

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        unordered_map<char, char> mps;
        unordered_map<char, char> mpt;
        for(size_t i=0;i<t.length();i++)
        {
            if(mps.find(s[i]) == mps.end() && mpt.find(t[i]) == mpt.end())
            {
                mps[s[i]] = t[i];
                mpt[t[i]] = s[i];
            }
            else if(mps.find(s[i]) != mps.end() && mpt.find(t[i]) != mpt.end())
            {
                if(mps[s[i]] != t[i] || mpt[t[i]] != s[i])
                    return false;
            }
            else if(mps.find(s[i]) == mps.end() || mpt.find(t[i]) == mpt.end())
            {
                return false;
            }
            else
            {
                if(mps[s[i]] != t[i] || mpt[t[i]] != s[i])
                    return false;
            }
        }
        return true;
    }
};

int main()
{
    std::boolalpha(cout);
    Solution s;
    string s1 = "paper";
    string t1 = "title";
    cout << s.isIsomorphic(s1, t1) << endl; // Output: true

    return 0;
}
    