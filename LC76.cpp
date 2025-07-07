#include "headers.h"

using namespace std;

class Solution
{
public:
    // This function finds the minimum window substring in s that contains all characters of t, t can have duplicates.
    string minWindow(string s, string t)
    {
        if (s.empty() || t.empty())
            return "";

        unordered_map<char, int> charCount;
        for (char c : t)
            charCount[c]++;

        int left = 0, right = 0, minLength = INT_MAX, start = 0, required = charCount.size();
        int formed = 0;
        unordered_map<char, int> windowCount;

        while (right < s.length())
        {
            char c = s[right];
            windowCount[c]++;

            if (charCount.count(c) && windowCount[c] == charCount[c])
                formed++;

            while (left <= right && formed == required)
            {
                if (right - left + 1 < minLength)
                {
                    minLength = right - left + 1;
                    start = left;
                }

                windowCount[s[left]]--;
                if (charCount.count(s[left]) && windowCount[s[left]] < charCount[s[left]])
                    formed--;

                left++;
            }
            right++;
        }

        return minLength == INT_MAX ? "" : s.substr(start, minLength);
    }
};

int main()
{
    Solution s;
    string input = "ADOBECODEBANC";
    string t = "ABC";
    string result = s.minWindow(input, t);
    cout << "Minimum window substring: " << result << endl; // Expected output: "BANC"
    return 0;
}