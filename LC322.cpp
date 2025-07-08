#include "headers.h"

using namespace std;

class Solution
{
public:
    int coinChange(vector<int>& coins, int amount)
    {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;

        for(int i = 1; i < (amount + 1); i++)
        {
            for(int j = 0; j < coins.size(); j++)
            {
                if(coins[j] > i)
                    continue;
                int rem = i - coins[j];
                dp[i] = min(1 + dp[rem], dp[i]);
            }
        }
        if(dp[amount] == amount + 1)
            return -1;
        return dp[amount];
    }
};

int main()
{
    Solution solution;
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    int result = solution.coinChange(coins, amount);
    cout << "Minimum coins needed: " << result << endl; // Output: 3

    // 1, 6, 7, 9, 11
    coins = {1, 6, 7, 9, 11};
    amount = 13;
    result = solution.coinChange(coins, amount);
    cout << "Minimum coins needed: " << result << endl; // Output: 2
    return 0;
}