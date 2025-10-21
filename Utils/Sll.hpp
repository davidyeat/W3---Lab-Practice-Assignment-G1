#include<iostream>
#include<string>
#include "node.hpp"
#include <chrono>
using namespace std;

using clk = chrono::high_resolution_clock;
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

        // Linked List operation insert at the Front
        void pushFront(int val){
            SNode* newNode = new SNode{val, nullptr};
            newNode->next = head;
            head = newNode;
            if (n == 0) {
                tail = newNode;
            }
            n++;
        }

        // Generate Singly Linked List
        void genList(int n){
            if (n <= 0) return;
            for(int i=n; i>=1; i--){
                pushFront(i);
            }
        }

        // Counting time of print Singly Linked List
        void sll_observe(SLL* obj, void (SLL::*method)(), string msg){
            auto t0 = clk::now();

            (obj->*method)(); // perform operation

            auto t1 = clk::now();

            auto duration = chrono::duration_cast<chrono::nanoseconds>(t1 - t0);
            cout<<msg <<": "<<duration.count() <<" nanosecond(s)" <<endl;
        }
        //A3.rotate-K
        void rotateHead(int k){
            if(n==0 || !head){
                cout<<"(Empty!)\n";
                return;
            }
            k = k>=n? k%n: k;
            for(int i=0; i<k; i++) {
                tail->next = head;
                tail = head;
                head = head->next;
                tail->next= nullptr;
            }
        }
        SNode getHead(){
            return *head;
        }
        SNode getTail(){
            return *tail;
        }
};