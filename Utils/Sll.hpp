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
            tail = nullptr;
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

        // A5: Push/Pop ends

        // SLL with head
        
        void popFront(){
            if(head == nullptr){
                cout<<"Empty! Nothing to delete"<<endl;
                return;
            }
            SNode* temp = head;
            head = head->next;
            delete temp;
            n--;
        }

       
        void pushBack(int val){
            SNode* newNode = new SNode{val, nullptr};
            if(head == nullptr){
                head = newNode;
                return;
            }
            cur = head;
            while(cur->next != nullptr){
                cur = cur->next;
            }
            cur->next = newNode;
            tail = newNode; // just use tail to stand at the end of the node
            n++;
        }
        void popBack(){
            if(head == nullptr){
                cout<<"Nothing to deleted\n";
                return;
            }

            // if it is only one Node
            if(head->next == nullptr){
                delete head;
                head = nullptr;
                return;
            }

            cur = head;
            while(cur->next->next){
                cur = cur->next;
            }
            delete cur->next;
            cur->next = nullptr;
            tail = cur;// just use tail to easy implement in some function
            n--;
        }

       
        // push and pop head + tail
        void pushBackTail(int val){
            SNode* newNode = new SNode{val, nullptr};

            // if list is empty
            if (head == nullptr) {
                head = tail = newNode;
            } else {
                tail->next = newNode; // link the last node to new node
                tail = newNode;       // update tail pointer
            }
        }

        // --- Member function to get the predecessor ---
        SNode* getPredecessor(int position){
            if(head == nullptr || position <= 0 || position > n) return nullptr;
            cur = head;
            for(int i = 0; i < position - 2; i++){
                cur = cur->next;
            }
            return cur;
        }
        void deleteWithPred(int pos, SNode* predecessor){
            if(head == nullptr || n==0 || pos<0){
                cout<<"Can't delete"<<endl;
                return;
            }
            
            
            // Case delete heade 
            if(pos == 1  ||predecessor == nullptr) {
                popFront();
                return;
            }

            if(pos == n || predecessor->next == tail){
                popBack();
                return;
            }
            // Delete the node
            SNode* nodeDelete = predecessor->next;
            predecessor->next = nodeDelete->next;
            delete nodeDelete;
            n--;

            // If list become empty, update tai;
            if(n == 0){
                head = tail = nullptr;
            }

        }

        void popAt(int pos ){
            if(n==0 || !head){
                cout<<"List is empty!\n";
                return; 
            }
            if(pos<0 || pos>n){
                cout<<"Can't delete!\n";
                return;
            }
            if(pos == n){
                popBack();
                return;
            }
            if(pos == 0 ){
                popFront();
                return;
            }
            cur = head;
            for (int i=0; i<pos-1; i++ ){
                cur = cur->next;
            }
            SNode* tmp = cur->next;
            cur->next = cur->next->next;
            delete tmp;
            n--;
        }

        SNode getHead(){
            return *head;
        }
        SNode getTail(){
            return *tail;
        }
};