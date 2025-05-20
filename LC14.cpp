#include <stdexcept>
#include <iostream>
#include <array>
#include <chrono>
#include <cstdlib>
#include <cstring>
#include <numeric>
#include <memory>
#include <string>
#include <vector>
#include <array>
#include <list>
#include <map>
#include <set>
#include <limits>
#include <stdexcept>
#include <algorithm>

using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        size_t i = 0;
        string prefix = "";
        while(true)
        {
            if(i >= strs[0].length())
            {
                break;
            }
            char c = strs[0][i];
            for(size_t j = 1; j < strs.size(); j++)
            {
                if(i >= strs[j].length() || strs[j][i] != c)
                {
                    return prefix;
                }
            }
            prefix += c;
            i++;
        }
        return prefix;
    }
};

int main()
{
    Solution s;
    vector<string> strs = {"flower","flow","flight"};
    string k = s.longestCommonPrefix(strs);
    cout << k << endl;

    strs = {"dog","racecar","car"};
    cout << s.longestCommonPrefix(strs) << endl;

    strs = {""};
    cout << s.longestCommonPrefix(strs) << endl;

    return 0;
}