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
            // Check for empty list and invalid positions
            if(head == nullptr || position < 0 || position >= n){
                cout << "No node to delete\n";
                return;
            }
            if(position == 0){
                deleteFront();
                return;
            }
            
            if(position == n-1){
                deleteEnd();
                return;
            }
            // Find the predecessor node
            cur = head;
            for (int i = 0; i < position - 1; i++) {
                cur = cur->next;
            }
            // Delete the node
            SNode *temp = cur->next;
            cur->next = temp->next;
            delete temp;
            n--;
            // If list becomes empty, update tail
            if(n == 0){
                head = tail = nullptr;
            }
        }
        // Circular Singly Linked List Deletion with predecessor
        void deleteWithPred(int position){
            if(head == nullptr || position < 0 || position >= n) return;
        
            if(position == 0) {
                SNode* temp = head;
                if(head == tail) {
                    head = tail = nullptr;
                } else {
                    head = head->next;
                    tail->next = head;
                }
                delete temp;
                n--;
                return;
            }

            SNode* prev = nullptr;
            SNode* current = head;
            for(int i = 0; i < position; i++) {
                prev = current;
                current = current->next;
            }

            prev->next = current->next;
            if(current == tail) {
                tail = prev;
                tail->next = head;
            }
            delete current;
            n--;
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