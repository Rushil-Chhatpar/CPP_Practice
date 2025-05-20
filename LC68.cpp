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
    vector<string> fullJustify(vector<string>& words, int maxWidth)
    {
        vector<string> result;
        int n = words.size();
        int start = 0;

        while (start < n)
        {
            int end = start;
            int lineSize = 0;
            while (end < n && lineSize + words[end].size() <= maxWidth)
            {
                lineSize += words[end].size() + 1; // +1 for space
                end++;
            }
            lineSize--; // Remove the last space
            //lineSize -= words[end].size();
            int numWords = end - start;
            int numSpaces = maxWidth - lineSize;
            string line = "";
            if (numWords == 1 || end == n)
            {
                for (int i = start; i < end; i++)
                {
                    line += words[i];
                    if (i < end - 1)
                    {
                        line += " ";
                    }
                }
                line += string(numSpaces, ' ');
            }
            else
            {
                int gaps = numWords - 1;
                int spaceBetweenWords = numSpaces / gaps;
                int extraSpaces = numSpaces % gaps;
                for(int i = start; i < end; i++)
                {
                    line += words[i];
                    if (i < end - 1)
                    {
                        // actual space between words
                        line+= " ";

                        line += string(spaceBetweenWords, ' ');
                        // add extra space starting from the left gaps
                        if (extraSpaces > 0)
                        {
                            line += " ";
                            extraSpaces--;
                        }
                    }
                }
            }
            result.push_back(line);
            start = end;
        }
        return result;
    }
};

int main()
{
    Solution s;
    vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};
    int maxWidth = 16;
    vector<string> result = s.fullJustify(words, maxWidth);
    for (const string& line : result)
    {
        cout << line << endl;
    }

    words = {"What","must","be","acknowledgment","shall","be"};

    result = s.fullJustify(words, 16);
    for (const string& line : result)
    {
        cout << line << endl;
    }

    words = {"Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"};
    result = s.fullJustify(words, 20);
    for (const string& line : result)
    {
        cout << line << endl;
    }

    words = {"a"};
    result = s.fullJustify(words, 1);
    for (const string& line : result)
    {
        cout << line << endl;
    }

    words = {"a", "b", "c"};
    result = s.fullJustify(words, 1);
    for (const string& line : result)
    {
        cout << line << endl;
    }

    return 0;
}