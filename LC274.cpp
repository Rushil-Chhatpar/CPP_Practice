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
    int hIndex(vector<int>& citations)
    {
        sort(citations.begin(), citations.end());
        int n = citations.size();

        for (int i = 0; i < n; ++i)
        {
            if (citations[i] >= n - i)
            {
                return n - i;
            }
        }
        return 0;
    }
};

int main()
{
    Solution s;
    vector<int> citations = {0, 1, 3, 5, 6};
    int k = s.hIndex(citations);
    cout << k << endl;

    citations = {1,3,1};
    cout << s.hIndex(citations) << endl;

    return 0;
}