#include <iostream>
#include "node.hpp"

using namespace std;

class DLL{
    private:
        DNode *head, *cur, *tail;
        int n;
    public:
        DLL(){
            head=nullptr;
            cur=nullptr;
            tail = nullptr;
            n=0;
        }
        // push/pop with DLL
        void push_front(int val){
            DNode* newNode = new DNode{val,head, nullptr};
            if(head != nullptr){
                head->prev = newNode;
            }else{
                tail = newNode;
            }
            head = newNode;
        }

        void push_back(int val){
            DNode* newNode = new DNode{val, nullptr, tail};
            if(tail != nullptr){
                tail->next = newNode;
            }else{
                head = newNode;
            }
            tail = newNode;
        }

        void pop_front(){
            if(head == nullptr){
                cout<<"Empty! Nothing to delete\n";
                return;
            };
            DNode* temp = head;
            head = head->next;
            delete temp;
        }
        void pop_back(){
            if(tail == nullptr){
                cout<<"Empty! Nothing to delete\n";
                return;
            }
            DNode* temp = tail;
            tail = tail->prev;
            if(tail != nullptr){
                tail->next = nullptr;
            }else{
                head = nullptr;
            }
            delete temp;
        }
};