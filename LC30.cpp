#include "headers.h"

using namespace std;

class Solution
{
public:
    vector<int> findSubstring(string s, vector<string>& words)
    {
        // vector<int> result;
        // if (s.empty() || words.empty())
        // {
        //     return result;
        // }

        // int wordLength = words[0].length();
        // int totalWords = words.size();
        // int totalLength = wordLength * totalWords;

        // unordered_map<string, int> wordsToLook;
        // for (const string& word : words)
        // {
        //     wordsToLook[word] = 1;
        // }
        // string wordToLook = words[0];
        // int index = 0;
        // while(index < s.length())
        // {
        //     string wordToCheck = s.substr(index, wordLength);
        //     if (wordToCheck == wordToLook)
        //     {
        //         wordsToLook[wordToCheck] = 0;
        //         int left = index - wordLength;
        //         int right = index + wordLength;
        //         int* pointer = &right;
        //         bool lookingRight = true;
        //         while (right < (int)s.length() && left >= 0)
        //         {
        //             string subWord = s.substr(*pointer, wordLength);
        //             if (wordsToLook.find(subWord) != wordsToLook.end())
        //             {
        //                 if (wordsToLook[subWord] == 0)
        //                 {
        //                     break;
        //                 }
        //                 wordsToLook[subWord] = 0;
        //                 if(lookingRight)
        //                     right += wordLength;
        //                 else
        //                 {
        //                     left -= wordLength;
        //                 }
        //             }
        //             else
        //             {
        //                 if(lookingRight)
        //                 {
        //                     lookingRight = false;
        //                     pointer = &left;
        //                 }
        //                 else
        //                 {
        //                     break;
        //                 }
        //             }
        //         }
        //         left = max(0, left);
        //         if (right - left == totalLength)
        //         {
        //             result.push_back(left);
        //         }
        //     }
        //     // reset the map
        //     for (auto& it : wordsToLook)
        //     {
        //         it.second = 1;
        //     }
        //     index+= wordLength;
        // }
        // return result;
                vector<int> result;
        if (s.empty() || words.empty())
        {
            return result;
        }

        int wordLength = words[0].length();
        int totalWords = words.size();
        int totalLength = wordLength * totalWords;

        unordered_map<string, int> wordCount;
        for (const string& word : words)
        {
            wordCount[word]++;
        }

        for (int i = 0; i <= (int)s.length() - totalLength; i++)
        {
            unordered_map<string, int> seenWords; 
            int j = 0;
            while (j < totalWords)
            {
                string word = s.substr(i + j * wordLength, wordLength);
                if (wordCount.find(word) == wordCount.end())
                {
                    break;
                }
                seenWords[word]++;
                if (seenWords[word] > wordCount[word])
                {
                    break;
                }
                j++;
            }
            if (j == totalWords)
            {
                result.push_back(i);
            }
        }
        return result;
    } 
};
    // vector<int> findSubstring(string s, vector<string>& words)
    // {
    //     vector<int> result;
    //     if (s.empty() || words.empty())
    //     {
    //         return result;
    //     }

    //     int wordLength = words[0].length();
    //     int totalWords = words.size();
    //     int totalLength = wordLength * totalWords;

    //     unordered_map<string, int> wordCount;
    //     for (const string& word : words)
    //     {
    //         wordCount[word]++;
    //     }

    //     for (int i = 0; i <= (int)s.length() - totalLength; i++)
    //     {
    //         unordered_map<string, int> seenWords;
    //         int j = 0;
    //         while (j < totalWords)
    //         {
    //             string word = s.substr(i + j * wordLength, wordLength);
    //             if (wordCount.find(word) == wordCount.end())
    //             {
    //                 break;
    //             }
    //             seenWords[word]++;
    //             if (seenWords[word] > wordCount[word])
    //             {
    //                 break;
    //             }
    //             j++;
    //         }
    //         if (j == totalWords)
    //         {
    //             result.push_back(i);
    //         }
    //     }
    //     return result;
    // }


int main()
{
    Solution s;
    string s1 = "barfoothefoobarman";
    vector<string> words = {"foo", "bar"};
    vector<int> result = s.findSubstring(s1, words);
    for (int index : result)
    {
        cout << index << " ";
    }
    cout << endl; // Output: 0 9
    return 0;
}