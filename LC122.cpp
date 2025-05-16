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
        int profit = 0;
        int currentCost = prices[0];
        for(int i = 1; i < prices.size(); i++)
        {
            if(prices[i] < currentCost)
            {
                currentCost = prices[i];
            }
            else
            {
                if(i < prices.size() - 1 && prices[i] < prices[i+1])
                {
                    continue;
                }
                else
                {
                    profit += prices[i] - currentCost;
                    currentCost = prices[i];
                }
            }
        }
        return profit;
    }
};

int main()
{
    Solution s;
    vector<int> prices = {7,6,4,3,1};
    int k = s.maxProfit(prices);
    cout << k << endl;

    return 0;
}