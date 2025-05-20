#include "headers.h"

using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        // convert to lowercase and remove non-alphanumeric characters
        string filtered;
        for (char c : s)
        {
            if (isalnum(c))
            {
                filtered += tolower(c);
            }
        }
        // check if the filtered string is a palindrome
        int left = 0;
        int right = filtered.length() - 1;
        while (left < right)
        {
            if (filtered[left] != filtered[right])
            {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};

int main()
{
    std::boolalpha(cout);
    Solution s;
    string w = " ";
    bool k = s.isPalindrome(w);
    cout << k << endl;
}