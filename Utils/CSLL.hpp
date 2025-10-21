#include <iostream>
#include "node.hpp"
#include <chrono>
using namespace std;
using clk = chrono::high_resolution_clock;
volatile int sink_int = 0;

class CSll{
    private:
        SNode *head, *cur, *tail;
        int n;
    public:
        CSll(){
            head = nullptr;
            cur = nullptr;
            tail = nullptr;
            n = 0;
        }

        // Circular Linked List operation insert at the Front
        void pushFront(int val){
            SNode* newNode = new SNode{val, nullptr};
            if(head == nullptr){
                head = tail = newNode;
                newNode->next = newNode;
            }
            else{
                newNode->next = head;
                tail->next = newNode;
                head = newNode;
            }
            n++;
        }

        // Generate Circular Singly Linked List
        void genList(int n){
            for(int i = n; i > 0; i--){
               pushFront(i);
            }
        }
        
        // Print Circular Singly Linked List by single loop of n steps
        void print_by_n(){
            cur = head;
            if(cur == nullptr){
                cout << "List is empty!" << endl;
                return;
            }

            for(int i = 0; i < n; i++){
                cout << cur->data << "->";
                cur = cur->next;
            }
            cout << endl;
        }

        // Counting time of print Circular Singly Linked List
        void csll_observe(CSll* obj, void (CSll::*method)(), string msg){
            auto t0 = clk::now();

            (obj->*method)(); // perform operation

            auto t1 = clk::now();

            auto duration = chrono::duration_cast<chrono::nanoseconds>(t1 - t0);
            cout<<msg <<": "<<duration.count() <<" nanosecond(s)" <<endl;
        }
        
        //A3.rotate-K
        void rotateHead(int k){
            if(n==0){
                cout<<"(Empty!)\n";
                return;
            }
            if (!head || !tail) {
                cout << "(Invalid list!)\n";
                return;
            }

            k = k>=n? k%n: k;
            for(int i=0; i<k; i++) {
                head = head->next;
                tail = tail->next;
            }

        }

        SNode getHead(){
            return *head;
        }
        SNode getTail(){
            return *tail;
        }

};