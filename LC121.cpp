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
    int maxProfit(vector<int>& prices)
    {
        int min = prices[0];
        int max = prices[0];
        int profit = 0;
        for(int i=1;i<prices.size();i++)
        {
            if(prices[i] < min)
            {
                min = prices[i];
                max = prices[i];
            }
            else if(prices[i] > max)
            {
                max = prices[i];
                int p = max - min;
                if(p > profit)
                {
                    profit = p;
                }
            }
        }
        return profit;
    }
};

int main()
{
    Solution s;
    vector<int> prices = {7,1,5,3,6,4};
    int k = s.maxProfit(prices);
    cout << k << endl;

    return 0;
}