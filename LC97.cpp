#include "headers.h"

using namespace std;

class Solution
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        if(s1.length() + s2.length() != s3.length())
            return false;
        return dfs(0, 0, s1, s2, s3);
    }
private:
    bool dfs (int index1, int index2, string& s1, string& s2, string& s3)
    {
        if(index1 + index2 == s3.length())
            return true;
        else if(index1 + index2 > s3.length())
            return false;
        
        if(s1[index1] == s3[index1 + index2])
        {
            if(dfs(index1 + 1, index2, s1, s2, s3))
               return true; 
        }
        if(s2[index2] == s3[index1 + index2])
        {
            if(dfs(index1, index2 + 1, s1, s2, s3))
                return true;
        }
        return false;
    }
};

int main()
{
    Solution solution;
    string s1 = "aabcc";
    string s2 = "dbbca";
    string s3 = "aadbbcbcac";
    bool result = solution.isInterleave(s1, s2, s3);
    cout << "Is interleaving: " << (result ? "true" : "false") << endl; // Output: true
    s1 = "aabc";
    s2 = "abad";
    s3 = "aabadabc";
    result = solution.isInterleave(s1, s2, s3);
    cout << "Is interleaving: " << (result ? "true" : "false") << endl; // Output: true
    return 0;
}