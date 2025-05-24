//  https://leetcode.com/problems/merge-two-sorted-lists/?envType=study-plan-v2&envId=top-interview-150
#include "headers.h"

using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution
{
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        if(!list1)
            return list2;
        else if(!list2)
            return list1;
            
        ListNode* p1 = list1;
        ListNode* p2 = list2;
        while(p1 != nullptr && p2 != nullptr)
        {
            if(p1->val <= p2->val)
            {
                if(p1->next && p1->next->val <= p2->val)
                {
                    p1 = p1->next;
                }
                else
                {
                    ListNode* temp = p1->next;
                    p1->next = p2;
                    p1 = temp;
                }
            }
            else
            {
                if(p2->next && p2->next->val < p1->val)
                {
                    p2 = p2->next;
                }
                else
                {
                    ListNode* temp = p2->next;
                    p2->next = p1;
                    p2 = temp;
                }
            }
        }

        if(list1->val <= list2->val)
            return list1;
        return list2;
    }
};

int main()
{
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);

    ListNode* l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);

    Solution s;
    s.mergeTwoLists(l1, l2);
}