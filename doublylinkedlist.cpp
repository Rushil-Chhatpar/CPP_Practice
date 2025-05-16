#include <stdexcept>
#include <iostream>
#include <array>
#include <chrono>
#include <cstdlib>
#include <cstring>
#include <numeric>
#include <memory>
#include <string>
#include <vector>
#include <array>
#include <list>
#include <map>
#include <set>
#include <limits>
#include <stdexcept>
#include <algorithm>


class MyLinkedList
{
    struct Node
    {
        Node* next;
        Node* prev;
        int val;

        Node(int val)
        : next(nullptr)
        , prev(nullptr)
        , val(val)
        {}
    };

public:
    MyLinkedList()
    : head(nullptr)
    , tail(nullptr)
    {
    }
    
    int get(int index)
    {
        Node* current;
        int curr;
        if(size == 0 || index < 0 || index >= size)
            return -1;
        // fist half
        if(size/2 >= index && head)
        {
            current = head;
            curr = 0;
            while (curr < index)
            {
                current = current->next;
                curr++;
            }
        }
        else
        {
            current = tail;
            curr = size - 1;
            while (curr > index)
            {
                current = current->prev;
                curr--;
            }
        }
        return current->val;
    }
    
    void addAtHead(int val)
    {
        Node* current = getNodeAtIndex(0);

        if(!head && !current)
        {
            head = new Node(val);
        }
        else if(!head && current)
        {
            head = new Node(val);
            current->prev = head;
            head->next = current;
        }
        else
        {
            Node* temp = new Node(val);
            head->prev = temp;
            temp->next = head;
            head = temp;
        }
        size++;
        if(!tail && size == 1)
        {
            tail = head;
        }
    }
    
    void addAtTail(int val)
    {
        Node* current = getNodeAtIndex(size - 1);
        if(!tail && !current)
        {
            tail = new Node(val);
        }
        else if(!tail && current)
        {
            tail = new Node(val);
            current->next = tail;
            tail->prev = current;
        }
        else
        {
            Node* temp = new Node(val);
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
        size++;
        if(!head && size == 1)
        {
            head = tail;
        }
    }
    
    void addAtIndex(int index, int val)
    {
        if(index < 0 || index > size)
            return;
        if(index == 0)
            return addAtHead(val);
        
        Node* current = getNodeAtIndex(index);
        if(!current && !head)
            return addAtHead(val);
        else if(!current && head)
            return addAtTail(val);
        
        Node* prevNode = current->prev;
        Node* newNode = new Node(val);
        newNode->prev = prevNode;
        newNode->next = current;
        current->prev = newNode;
        if(prevNode)
            prevNode->next = newNode;
        size++;
    }
    
    void deleteAtIndex(int index)
    {
        if(size == 0 || index < 0 || index >= size)
            return;
        Node* current = getNodeAtIndex(index);
        Node* prevNode = current->prev;
        Node* nextNode = current->next;
        if(prevNode)
        {
            prevNode->next = nextNode;
            if(!nextNode)
                tail = prevNode;
        }
        if(nextNode)
        {
            nextNode->prev = prevNode;
            if(!prevNode)
                head = nextNode;
        }
        current->next = nullptr;
        current->prev = nullptr;
        delete current;
        size--;
    }
private:
    Node* getNodeAtIndex(int index)
    {
        Node* current;
        int curr;
        if(size == 0 || index < 0 || index >= size)
            return nullptr;
        // fist half
        if(size/2 >= index && head)
        {
            current = head;
            curr = 0;
            while (curr < index)
            {
                current = current->next;
                curr++;
            }
        }
        else
        {
            current = tail;
            curr = size - 1;
            while (curr > index)
            {
                current = current->prev;
                curr--;
            }
        }
        return current;
    }
    Node* head;
    Node* tail;
    int size{0};
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

int main()
{
    MyLinkedList* obj = new MyLinkedList();


    obj->addAtIndex(1, 0);
    std::cout << obj->get(0) << std::endl; // 2




    return 0;
}