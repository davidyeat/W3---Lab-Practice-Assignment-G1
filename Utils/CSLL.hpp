#include <iostream>
#include "Utils/node.hpp"
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

        // At the Beginning
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
    }
        // Create nodes by Insert at the Front
        void genList(int n){
            for(int i = n; i > 0; i--){
               pushFront(i);
            }
        }
    
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

        void sll_observe(CSll* obj, void (CSll::*method)(), string msg){
            auto t0 = clk::now();

            (obj->*method)(); // perform operation

            auto t1 = clk::now();

            auto duration = chrono::duration_cast<chrono::nanoseconds>(t1 - t0);
            cout<<msg <<": "<<duration.count() <<" nanosecond(s)" <<endl;
        }

};