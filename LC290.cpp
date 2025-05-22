#include "headers.h"
#include <sstream>

using namespace std;

class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        unordered_map<char, string> mppattern;
        unordered_map<string, char> mpwords;
        vector<string> words;
        stringstream ss(s);
        string word;
        while (ss >> word)
        {
            words.push_back(word);
        }
        if (pattern.length() != words.size())
        {
            return false;
        }
                for(size_t i=0;i<words.size();i++)
        {
            if(mppattern.find(pattern[i]) == mppattern.end() && mpwords.find(words[i]) == mpwords.end())
            {
                mppattern[pattern[i]] = words[i];
                mpwords[words[i]] = pattern[i];
            }
            else if(mppattern.find(pattern[i]) != mppattern.end() && mpwords.find(words[i]) != mpwords.end())
            {
                if(mppattern[pattern[i]] != words[i] || mpwords[words[i]] != pattern[i])
                    return false;
            }
            else if(mppattern.find(pattern[i]) == mppattern.end() || mpwords.find(words[i]) == mpwords.end())
            {
                return false;
            }
            else
            {
                if(mppattern[pattern[i]] != words[i] || mpwords[words[i]] != s[i])
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
    string pattern = "aaaa";
    string str = "dog cat cat dog";

    cout << s.wordPattern(pattern, str) << endl;
    return 0;
}