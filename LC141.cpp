// https://leetcode.com/problems/linked-list-cycle/?envType=study-plan-v2&envId=top-interview-150
#include "headers.h"

using namespace std;


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        ListNode* p1 = head;
        ListNode* p2 = head;
        while(p2!= nullptr && p2->next!=nullptr)
        {
            p1 = p1->next;
            p2 = p2->next->next;

            if(p1 == p2)
                return true;
        }
        return false;
    }
};