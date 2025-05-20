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
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
        int n = gas.size();
        int startingIndex = 0;
        int totalGas = 0;
        int totalCost = 0;
        for(int i = 0; i < n; i++)
        {
            totalGas += gas[i];
            totalCost += cost[i];
        }

        if(totalGas < totalCost)
        {
            return -1;
        }

        int gasTank = 0;

        for(int i = 0; i < n; i++)
        {
            gasTank += gas[i] - cost[i];
            if(gasTank < 0)
            {
                startingIndex = i + 1;
                gasTank = 0;
            }
        }
        return startingIndex;
    }
};

int main()
{
    Solution s;
    vector<int> gas = {5,8,2,8};
    vector<int> cost = {6,5,6,6};
    cout << s.canCompleteCircuit(gas, cost) << endl;

    gas = {3,1,1};
    cost = {1,2,2};
    cout << s.canCompleteCircuit(gas, cost) << endl;

    gas = {5,1,2,3,4};
    cost = {4,4,1,5,1};
    cout << s.canCompleteCircuit(gas, cost) << endl;

    return 0;
}