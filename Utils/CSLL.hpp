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

        //----------------------------------------------------------------------

        // A1 - CSL: tail-to-head wrap vs manual reset
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

        //----------------------------------------------------------------------

        void deleteFront(){
            if(head == nullptr){
                cout << "Cannot delete from front: the list is already empty!" << endl;
                return;
            }
            SNode* tmp = head;
            tail->next = head->next;
            head = head->next;
            delete tmp;
            n--;
            return;
        }

        void deleteEnd(){
            if(head == nullptr){
                cout << "Cannot delete from front: the list is already empty!" << endl;
                return;
            }
            if(head == tail){
                delete head;
                head = nullptr;
                tail = nullptr;
                return;
            }
            cur = head;
            while(cur->next != tail){
                cur =  cur->next;
            }
            SNode* tmp = tail;
            cur->next = head;
            tail = cur;
            delete tmp;
            n--;
        }

        //----------------------------------------------------------------------

        // A2 - CSLL deletion with/ without predecessor

        // Circular Singly Linked List Deletion without predecessor
        void deleteWithoutPred(int position){
            // Case position outside the valid range
            if(position <= 0 || position > n){
                cout << "Cannot delete: Position outside the valid range!" << endl;
                return;
            }
            // Case delete from the front
            if(position == 1){
                deleteFront();
                n--;
                return;
            }
            // Case delete from the end
            if(position == n){
                deleteEnd();
                n--;
                return;
            }
            cur = head;
            for(int i = 0; i < position - 1; i++){
                cur = cur->next;
            }
            cur = head;
            for(int i = 0; i < position - 1; i++){
                cur = cur->next;
            }
        }
        // Circular Singly Linked List Deletion with predecessor
        void deleteWithPred(){
            // ... 
        }
        

        // Counting time of print Circular Singly Linked List
        void csll_observe(CSll* obj, void (CSll::*method)(), string msg){
            auto t0 = clk::now();

            (obj->*method)(); // perform operation

            auto t1 = clk::now();

            auto duration = chrono::duration_cast<chrono::nanoseconds>(t1 - t0);
            cout<<msg <<": "<<duration.count() <<" nanosecond(s)" <<endl;
        }
};