#include "headers.h"

using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if(s.length() != t.length())
            return false;

        unordered_map<char, int> mps;
        unordered_map<char, int> mpt;
        for(size_t i=0;i<t.length();i++)
        {
            mps[s[i]]++;
            mpt[t[i]]++;
        }
        for(size_t i=0;i<t.length();i++)
        {
            if(mps[s[i]] != mpt[s[i]])
                return false;
        }
        return true;
    }
};

int main()
{
    std::boolalpha(cout);
    Solution s;
    string s1 = "rat";
    string s2 = "car";
    cout << s.isAnagram(s1, s2) << endl;
    return 0;
}