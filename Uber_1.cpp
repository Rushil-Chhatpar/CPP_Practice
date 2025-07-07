#include "headers.h"

using namespace std;

vector<int> solution(vector<int> numbers)
{
    vector<int> result;
    for(int i = 0; i < numbers.size() - 2; i++)
    {
        if((numbers[i] > numbers[i+1] && numbers[i+1] < numbers [i+2]) || 
        (numbers[i] < numbers[i+1] && numbers[i+1] > numbers [i+2]))
        {
            result.push_back(1);
        }
        else
        {
            result.push_back(0);
        }
    }
    return result;
}

int main()
{

    vector<int> numbers = {1, 2, 1, 3, 4};
    vector<int> result = solution(numbers);
    for(int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    // std::cout << "Hello world" << std::endl;
    // int n = 3;
    // for(int i = 1; i <= n; i++)
    // {
    //     // Print spaces
    //     for(int j = 1; j <= n - i; j++)
    //     {
    //         std::cout << " ";
    //     }
    //     // Print stars
    //     for(int k = 1; k <= (2 * i - 1); k++)
    //     {
    //         std::cout << "*";
    //     }
    //     std::cout << std::endl;
    // }
    return 0;
}

