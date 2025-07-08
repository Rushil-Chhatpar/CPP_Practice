#include "headers.h"

using namespace std;

class Solution
{
public:
    bool wordBreak(string s, vector<string>& wordDict)
    {
        unordered_map<string, int> dict;
        for(string& word : wordDict)
        {
            dict[word] = 1;
        }
        int n = s.length();
        vector<bool> dp (n + 1, false);
        dp[0] = true;

        for(int i = 1; i < (n + 1); i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(dp[j] && dict.count(s.substr(j, i - j)))
                    dp[i] = true;
            }
        }
        return dp[n];
    }
};

int main()
{
    Solution solution;
    string s = "leetcode";
    vector<string> wordDict = {"leet", "code"};
    bool result = solution.wordBreak(s, wordDict);
    cout << "Can the string be segmented: " << (result ? "Yes" : "No") << endl; // Output: Yes

    s = "applepenapple";
    wordDict = {"apple", "pen"};
    result = solution.wordBreak(s, wordDict);
    cout << "Can the string be segmented: " << (result ? "Yes" : "No") << endl; // Output: Yes

    return 0;
}