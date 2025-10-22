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
        void pushFront(int val){
            DNode* newNode = new DNode{val,head, nullptr};
            if(head != nullptr){
                head->prev = newNode;
            }else{
                tail = newNode;
            }
            head = newNode;
            n++;
        }

        void pushBack(int val){
            DNode* newNode = new DNode{val, nullptr, tail};
            if(tail != nullptr){
                tail->next = newNode;
            }else{
                head = newNode;
            }
            tail = newNode;
            n++;

        }

        void popFront(){
            if(head == nullptr){
                cout<<"Empty! Nothing to delete\n";
                return;
            };
            DNode* temp = head;
            head = head->next;
            delete temp;
            n--;
        }
        void popBack(){
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
            n--;
        }

        void genList(int n){
            if (n <= 0) return;
            for(int i=n; i>=1; i--){
                pushFront(i);
            }
        }

        void printList(){
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
            if(pos == 1 ){
                popFront();
                return;
            }
            cur = head;
            for(int i=0; i<pos-1; i++){
                cur = cur->next;
            }
            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;
            delete cur;
        }
};