// https://leetcode.com/problems/simplify-path/?envType=study-plan-v2&envId=top-interview-150
#include "headers.h"

using namespace std;

class Solution
{
public:
    string simplifyPath(string path)
    {
        int len = path.length();
        if(len == 1)
            return "/";
        stack<string> dirs;
        int s = 1;
        int e = 1;
        for(int i = 1; i < len; i++)
        {
            char c = path[i];
            if(c == '/' || i == len - 1)
            {
                if(i == len - 1 && c != '/')
                    e = i + 1;
                else
                    e = i;
                if(s == e)
                {
                    s = i + 1;
                    e = i + 1;
                    continue;
                }
                string word = path.substr(s, e - s);
                if(word == "..")
                {
                    // remove from dir
                    if(!dirs.empty())
                        dirs.pop();
                }
                else if(word != ".")
                {
                    dirs.push(word);
                }
                s = i + 1;
                e = i + 1;
            }
        }
        string result = "";
        while(!dirs.empty())
        {
            string word = dirs.top();
            dirs.pop();
            result = "/" + word + result;
        }
        if(result.length() == 0)
            return "/";
        return result;
    }
};

int main()
{
    Solution s;
    string path = "/home/";
    string result = s.simplifyPath(path);
    cout << result << endl;
    return 0;
}