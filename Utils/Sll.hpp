#include<iostream>
#include<string>
#include "Utils/node.hpp"

using namespace std;

class LinkedList{
    private:
        Sll *head, *cur;
        int n;
    public:
        LinkedList(){
            head=nullptr;
            cur=nullptr;
            n=0;
        }
        ~LinkedList() {
            cur = head;
            Sll* nextNode = nullptr;

            while (cur != nullptr) {
                nextNode = cur->next; // Save the next node
                delete cur;           // Delete the current node
                cur = nextNode;       // Move to the next node
            }
        }
};