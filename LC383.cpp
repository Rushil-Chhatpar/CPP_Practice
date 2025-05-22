#include "headers.h"

using namespace std;


class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        unordered_map<char, int> letters;
        for (char c : magazine)
        {
            letters[c]++;
        }
        for (char c : ransomNote)
        {
            if (letters[c] == 0)
            {
                return false;
            }
            letters[c]--;
        }
        return true;
    }
};

int main()
{
    std::boolalpha(cout);
    Solution s;
    string ransomNote = "aa";
    string magazine = "aab";
    cout << s.canConstruct(ransomNote, magazine) << endl; // Output: false
    return 0;
}