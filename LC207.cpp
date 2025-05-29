// https://leetcode.com/problems/course-schedule/description/?envType=study-plan-v2&envId=top-interview-150
#include "headers.h"

using namespace std;

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        unordered_map<int, vector<int>> map;
        unordered_set<int> closedList;
        for(auto& p : prerequisites)
        {
            map[p[0]].push_back(p[1]);
        }
        for(int i = 0; i < numCourses; i++)
        {
            if(!dfs(map, closedList, i))
                return false;
        }
        return true;
    }
private:
    bool dfs(unordered_map<int, vector<int>>& map, unordered_set<int>& closedList, int course)
    {
        if(map.find(course) == map.end())
            return true;
        
        if(closedList.count(course))
            return false;

        closedList.insert(course);

        for(int& num : map[course])
        {
            if(!dfs(map, closedList, num))
                return false;
        }
        map.erase(course);
        return true;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> p = {
        {1, 4}, {2, 4}, {3, 1}, {3, 2}
    };
    bool result = s.canFinish(5, p);
    return 0;
}