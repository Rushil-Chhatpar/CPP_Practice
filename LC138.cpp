// https://leetcode.com/problems/copy-list-with-random-pointer/description/?envType=study-plan-v2&envId=top-interview-150
#include "headers.h"

using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution
{
public:
    Node* copyRandomList(Node* head)
    {
        if(!head)
            return nullptr;
        Node* current = head;
        while (true)
        {
            Node* tempNext = current->next;
            Node* tempNew = new Node(current->val);
            current->next = tempNew;
            tempNew->next = tempNext;
            current = tempNext;
            if(!tempNext)
                break;
        }

        current = head;
        while(true)
        {
            Node* newNext = current->next;
            newNext->random = current->random? current->random->next : nullptr;
            current = newNext->next;
            if(!current)
                break;
        }

        Node* newHead = head->next;
        current = head;
        while(current)
        {
            Node* newNext = current->next;
            current->next = newNext->next;
            newNext->next = newNext->next? newNext->next->next : nullptr;
            current = current->next;
        }
        return newHead;
    }
};

int main()
{
    Solution s;
    Node* head = new Node(7);
    head->next = new Node(13);
    head->next->next = new Node(11);
    head->next->next->next = new Node(10);
    head->next->next->next->next = new Node(1);
    head->random = nullptr;
    head->next->random = head;
    head->next->next->random = head->next->next->next->next;
    head->next->next->next->random = head->next->next;
    head->next->next->next->next->random = head;

    s.copyRandomList(head);
    return 0;
}