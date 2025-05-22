// https://leetcode.com/problems/group-anagrams/description/?envType=study-plan-v2&envId=top-interview-150
#include "headers.h"

using namespace std;

// class Solution
// {
// public:
//     vector<vector<string>> groupAnagrams(vector<string>& strs)
//     {
//         vector<vector<string>> result;
//         vector<int> primes = getPrimes(26);
//         // letter, prime
//         unordered_map<char, int> mp;
//         char letter = 'a';
//         for(int& num : primes)
//         {
//             mp[letter] = num;
//             letter++;
//         }

//         int index = 0;
//         // score, index
//         unordered_map<long long, int> scores;
//         for(int i = 0; i < strs.size(); i++)
//         {
//             long long score = 1;
//             for(char c : strs[i])
//             {
//                 score *= mp[c];
//             }
//             if(scores.find(score) == scores.end())
//             {
//                 scores[score] = index;
//                 vector<string> ns = {strs[i]};
//                 result.push_back(ns);
//                 index++;
//             }
//             else
//             {
//                 result[scores[score]].push_back(strs[i]);
//             }
//         }
//         return result;
//     }
// private:
//     std::vector<int> getPrimes(int count)
//     {
//         std::vector<int> primes;
//         int n = 2;
//         while(primes.size() < count)
//         {
//             bool isPrime = true;
//             for(int i = 2; i * i <= n; i++)
//             {
//                 if(n % i == 0)
//                 {
//                     isPrime = false;
//                     break;
//                 }
//             }
//             if(isPrime)
//             {
//                 primes.push_back(n);
//             }
//             n++;
//         }
//         return primes;
//     }
// };

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        // [unique non-alphanumeric key], [collection]
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> result;

        for(string& str : strs)
        {
            array<int, 26> letterCounts = {0};
            for(char c : str)
            {
                letterCounts[c - 'a']++;
            }
            string key = "";
            for(int num : letterCounts)
            {
                key += to_string(num) + "|";
            }
            mp[key].push_back(str);
        }
        for(auto& mpEntry : mp)
        {
            // move the whole vector
            result.push_back(std::move(mpEntry.second));
        }
        return result;
    }
};

int main()
{
    Solution s;
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> result = s.groupAnagrams(strs);
    for(vector<string>& v : result)
    {
        for(string& s : v)
        {
            cout << s << ", ";
        }
        cout << endl;
    }
    return 0;
}