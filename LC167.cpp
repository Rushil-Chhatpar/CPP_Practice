#include "headers.h"

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int>& numbers, int target)
    {
        int s = 0;
        int e = numbers.size() - 1;
        while (s < e)
        {
            if(numbers[s] + numbers[e] == target)
                return {s + 1, e + 1};
            else if(numbers[s] + numbers[e] > target)
                e--;
            else
                s++;
        }
        return {};
    }
};

int main()
{
    Solution s;
    vector<int> num = {-10,-8,-2,1,2,5,6};
    vector<int> result = s.twoSum(num, 0);
    for(int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}