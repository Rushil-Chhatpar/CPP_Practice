#include "headers.h"

using namespace std;

int solution(string &S) {
    // Implement your solution here
    int n = S.length();
    if(n < 3)
        return 0;
    
    // holding a frequency hash table
    std::vector<int> frequency(26, 0);
    for(char c: S)
        frequency[c - 'a']++;
    
    // calculating number of pairs and singles
    // so if in example "aaaabc", there are 2 pairs of "a", and 2 singles of "b" and "c"
    int pairs = 0, singles = 0;
    for(int i = 0;i < 26; i++)
    {
        // we divide by 2 for pairs and mod by 2 for singles.
        pairs += frequency[i] / 2;
        // turns out we dont need singles
        //singles = frequency[i] % 2;
    }

    int max = n / 3;
    int maxPal = std::min(pairs, max);
    return maxPal;
}

int main()
{
    string S = "aaaabc";
    int result = solution(S);
    cout << "Maximum number of palindromes: " << result << endl; // Output: 2
    return 0;
}