#include<iostream>
#include<string>
#include "Utils/node.hpp"

using namespace std;

class SLL{
    private:
        SNode *head, *cur, *tail;
        int n;
    public:
        SLL(){
            head = nullptr;
            cur = nullptr;
            n = 0;
        }

        // Traversal by pointer
        void print_by_pointer(){
            cur = head;
            if(cur == nullptr){
                cout << "List is empty!" << endl;
                return;
            }
            while(cur != nullptr){
                cout << cur->data << "->";
                cur = cur->next;
            }
            cout << endl;
        }
};