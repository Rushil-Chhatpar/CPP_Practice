// https://leetcode.com/problems/candy/description/
#include "headers.h"

using namespace std;

class Solution
{
public:
    int candy(vector<int>& ratings)
    {
        int n = ratings.size();
        vector<int> candies(n, 1);
        if(n == 1)
            return 1;
        else if(n > 2)
        {
            if(ratings[0] > ratings[1])
                candies[0]++;
            if(ratings[n-1] > ratings[n-2])
                candies[n-1]++;
        }
        for(int i = 1, j = n-2; i < n; i++, j--)
        {
            if(ratings[i] > ratings[i-1])
            {
                candies[i] = max(candies[i-1] + 1, candies[i]);
            }
            if(ratings[j] > ratings[j+1])
            {
                candies[j] = max(candies[j+1] + 1, candies[j]);
            }
        }
        int total = 0;
        for(int& candy : candies)
        {
            total += candy;
        }
        return total;
    }
};

int main()
{
    Solution s;
    vector<int> r = {0,1,2,5,3,2,7};
    cout << s.candy(r) << endl;
    return 0;
}