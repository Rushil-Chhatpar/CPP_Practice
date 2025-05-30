// https://leetcode.com/problems/course-schedule-ii/description/?envType=study-plan-v2&envId=top-interview-150
#include "headers.h"

using namespace std;

class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
    {
        vector<int> result;
        unordered_set<int> setResult;
        unordered_map<int, vector<int>> map;
        unordered_set<int> closedList;
        for(auto& p : prerequisites)
        {
            map[p[0]].push_back(p[1]);
        }
        for(int i = 0; i < numCourses; i++)
        {
            if(!dfs(map, closedList, i, result, setResult))
            {
                result.clear();
                return result;
            }
        }
        return result;
    }
private:
    bool dfs(unordered_map<int, vector<int>>& map, unordered_set<int>& closedList, int course, vector<int>& result, unordered_set<int>& setResult)
    {
        if(map.find(course) == map.end())
        {
            if(setResult.find(course) == setResult.end())
            {
                setResult.insert(course);
                result.push_back(course);
            }
            return true;
        }

        if(closedList.count(course))
            return false;

        closedList.insert(course);

        for(int& num : map[course])
        {
            if(!dfs(map, closedList, num, result, setResult))
                return false;
        }
        map.erase(course);
        if(setResult.find(course) == setResult.end())
        {
            setResult.insert(course);
            result.push_back(course);
        }
        return true;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> p = {
        {1, 4}, {2, 4}, {3, 1}, {3, 2}
    };
    s.findOrder(5, p);
    return 0;
}