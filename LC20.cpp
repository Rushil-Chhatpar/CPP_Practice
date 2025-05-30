// https://leetcode.com/problems/valid-parentheses/description/?envType=study-plan-v2&envId=top-interview-150
#include "headers.h"

using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        std::stack<char> st;
        for(char c : s)
        {
            if(c == '(' || c == '[' || c == '{')
                st.push(c);
            else
            {
                if(st.size() == 0)
                    return false;
                char front = st.top();
                st.pop();
                if(abs(c - front) > 2)
                    return false;
            }
        }
        if(st.size() > 0)
            return false;
        return true;
    }
};

int main()
{
    std::boolalpha(cout);
    Solution s;
    cout << s.isValid("({{{{}}}))") << endl;
    return 0;
}