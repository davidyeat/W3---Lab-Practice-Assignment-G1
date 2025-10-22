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
        void deleteWithoutPred(SNode* nodeToDelete) {
            if(nodeToDelete == nullptr) return;
            if(head == nullptr) return;
            
            if(head == tail && head == nodeToDelete) {
                delete head;
                head = tail = nullptr;
                n = 0;
                return;
            }
            
            SNode* predecessor = nullptr;
            bool nodeFound = false;
            
            SNode* temp = head;
            do {
                if(temp == nodeToDelete) {
                    nodeFound = true;
                    break;
                }
                temp = temp->next;
            } while(temp != head);
            
            if(!nodeFound) return;
            
            if(nodeToDelete == head) {
                predecessor = tail;
            } else {
                SNode* current = head;
                do {
                    if(current->next == nodeToDelete) {
                        predecessor = current;
                        break;
                    }
                    current = current->next;
                } while(current != head);
            }
            
            if(predecessor == nullptr) return;
            
            if(nodeToDelete == head) {
                head = head->next;
                tail->next = head;
            } else {
                predecessor->next = nodeToDelete->next;
            }
            
            if(nodeToDelete == tail) {
                tail = predecessor;
                tail->next = head;
            }
            
            delete nodeToDelete;
            n--;
            
            if(n == 0) {
                head = tail = nullptr;
            }
        }
        // Circular Singly Linked List Deletion with predecessor
        void deleteWithPred(SNode* predecessor, SNode* nodeToDelete) {
            if(nodeToDelete == nullptr) return;
            
            if(head == tail && head == nodeToDelete) {
                delete head;
                head = tail = nullptr;
                n = 0;
                return;
            }

            if(nodeToDelete == head) {
                head = head->next;
                tail->next = head;
            } else {
                predecessor->next = nodeToDelete->next;
            }

            if(nodeToDelete == tail) {
                tail = predecessor;
                tail->next = head;
            }

            delete nodeToDelete;
            n--;
            
            if(n == 0) {
                head = tail = nullptr;
            }
        }

        // Helper function to get node at specific position
        SNode* getNodeAtPosition(int position) {
            if(position < 0 || position >= n) return nullptr;
            SNode* temp = head;
            for(int i = 0; i < position; i++) {
                temp = temp->next;
            }
            return temp;
        }

        // Helper function to find node by value
        SNode* findNodeByValue(int value) {
            if(head == nullptr) return nullptr;
            SNode* temp = head;
            do {
                if(temp->data == value) return temp;
                temp = temp->next;
            } while(temp != head);
            return nullptr;
        }

        // Helper function to get predecessor of a given node
        SNode* getPredecessor(SNode* node) {
            if(head == nullptr || node == nullptr) return nullptr;
            if(node == head) return tail;
            SNode* current = head;
            do {
                if(current->next == node) return current;
                current = current->next;
            } while(current != head);
            return nullptr;
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
            if(n==0 || !head){
                cout<<"(Empty!)\n";
                return;
            }
            k = k>=n? k%n: k;
            for(int i=0; i<k; i++) {
                head = head->next;
                tail = tail->next;
            }
        }

         void rotateRight(int k) {
            if (n <= 1 || !head || !tail) {
                return;  
            }
        
            k = k % n;
            if (k == 0) {
                return; 
            }

            // Find new head position
            SNode* newHead = head;
            for(int i = 0; i < (n - k); i++) {
                newHead = newHead->next;
            }

            // Find new tail (node before new head)
            SNode* newTail = newHead;
            while(newTail->next != newHead) {
                newTail = newTail->next;
            }

            // Update head and tail
            head = newHead;
            tail = newTail;
        }

};