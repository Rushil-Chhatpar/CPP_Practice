// https://leetcode.com/problems/climbing-stairs/description/?envType=study-plan-v2&envId=top-interview-150
#include "headers.h"

using namespace std;

class Solution
{
public:
    // int climbStairs(int n)
    // {
    //     if(n == 1)
    //         return 1;
    //     if(n == 2)
    //         return 2;
    //     return climbStairs(n - 1) + climbStairs(n - 2);
    // }
    int climbStairs(int n)
    {
        if(n <= 3)
            return n;
        int x1 = 3;
        int x2 = 2;
        int num = 0;
        for(int i = 3; i < n; i ++)
        {
            num = x1 + x2;
            x2 = x1;
            x1 = num; 
        }
        return num;
    }
};