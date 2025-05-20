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
    int lengthOfLastWord(string s)
    {
        int size = s.length();
        int i = size - 1;
        while (i >= 0 && s[i] == ' ')
        {
            i--;
        }
        if (i < 0)
        {
            return 0;
        }
        int count = 0;
        while (i >= 0 && s[i] != ' ')
        {
            count++;
            i--;
        }
        return count;
    }
};

int main()
{
    Solution s;
    string str = "Hello World";
    int k = s.lengthOfLastWord(str);
    cout << k << endl;

    str = "   fly me   to   the moon  ";
    cout << s.lengthOfLastWord(str) << endl;

    str = "luffy is still joyboy";
    cout << s.lengthOfLastWord(str) << endl;

    return 0;
}