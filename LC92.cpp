#include "headers.h"

using namespace std;


//Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode* reverseBetween(ListNode* head, int left, int right)
    {
        int jump = right - left;
        int start = left - 1;
        ListNode* dummy = new ListNode(0, head);
        ListNode* current = head;
        ListNode* prev = dummy;
        for(int i = 0; i< start; i++)
        {
            prev = current;
            current = current->next;
        }

        for(int i = 0; i < jump; i++)
        {
            ListNode* temp = current->next;
            current->next = temp->next;
            temp->next = prev->next;
            prev->next = temp;
        }
        return dummy->next;
        
        while(jump > 0)
        {
            if(jump == 1)
            {
                // swap the nodes and if the current is the head, update the head
                if(current == head)
                {
                    head = current->next;
                    current->next = head->next;
                    head->next = current;
                    return head;
                }
                else
                {
                    ListNode* nextNode = current->next;
                    current->next = nextNode->next;
                    nextNode->next = current;
                    prev->next = nextNode;
                    return head;
                }
            }

            ListNode* farPrev;
            ListNode* far = retrieve(jump, farPrev, current);
            farPrev->next = current;

            if(prev)
                prev->next = far;
            ListNode* temp = current->next;
            current->next = far->next;
            far->next = temp;
            if(current == head)
                head = far;
            jump -= 2;
        }
        return head;
    }
private:
    ListNode* retrieve(int deep, ListNode*& prev, ListNode* curr)
    {
        for(int i = 0; i < deep; i ++)
        {
            prev = curr;
            curr = curr->next;
        }
        return curr;
    }
};

int main()
{
    Solution s;
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    int left = 2;
    int right = 4;
    ListNode* result = s.reverseBetween(head, left, right);
    
    // Print the reversed list
    while (result)
    {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl; // Output: 1 4 3 2 5

    // [5]
    ListNode* singleNode = new ListNode(5);
    left = 1;
    right = 1;
    result = s.reverseBetween(singleNode, left, right);
    cout << result->val << endl; // Output: 5

    // [3,5]
    ListNode* twoNodes = new ListNode(3, new ListNode(5));
    left = 1;
    right = 2;
    result = s.reverseBetween(twoNodes, left, right);
    while (result)
    {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl; // Output: 5 3

    // [1,2,3]
    ListNode* threeNodes = new ListNode(1, new ListNode(2, new ListNode(3)));
    left = 1;
    right = 3;
    result = s.reverseBetween(threeNodes, left, right);
    while (result)
    {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl; // Output: 3 2 1
    return 0;
}