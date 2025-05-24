// https://leetcode.com/problems/add-two-numbers/?envType=study-plan-v2&envId=top-interview-150
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* result = new ListNode();
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        ListNode* r = result;
        int carry = 0;
        while(p1 || p2)
        {
            int sum = carry;
            if(p1)
            {
                sum += p1->val;
                p1 = p1->next;
            }
            if(p2)
            {
                sum += p2->val;
                p2 = p2->next;
            }
            carry = sum / 10;
            r->val = sum % 10;
            if(!p1 && !p2)
                break;
            r->next = new ListNode();
            r = r->next;
        }
        if(carry != 0)
        {
            r->next = new ListNode(carry);
        }
        return result;
    }
};

int main()
{
    ListNode* l1 = new ListNode(9);
    l1->next = new ListNode(9);
    l1->next->next = new ListNode(9);
    l1->next->next->next = new ListNode(9);
    l1->next->next->next->next = new ListNode(9);
    l1->next->next->next->next->next = new ListNode(9);
    l1->next->next->next->next->next->next = new ListNode(9);

    ListNode* l2 = new ListNode(9);
    l2->next = new ListNode(9);
    l2->next->next = new ListNode(9);
    l2->next->next->next = new ListNode(9);

    Solution s;
    s.addTwoNumbers(l1, l2);
}