#include <iostream>
#include <node.hpp>

using namespace std;

class CSll{
    private:
        SNode *head, *cur, *tail;
        int n;
    public:
        CSll(){
            head=nullptr;
            cur=nullptr;
            tail = nullptr;
            n=0;
        }
        void deleteWithPrevious(SNode* predecessor, SNode* nodeToDelete){
            if(nodeToDelete == nullptr){
                cout << "Node to be deleted is null." << endl;
                return;
            }
            if(nodeToDelete != head && predecessor == nullptr) {
                cout << "Error: Predecessor cannot be null for non-head node" << endl;
                return;
            }
            
            if(head == tail && head == nodeToDelete){
                delete head;
                head = tail = nullptr;
                n=0;
                return;
            }
            if(nodeToDelete == head){
                head = head->next;
                tail->next = head;
            } else {
                predecessor->next = nodeToDelete->next;
            }
            if(nodeToDelete == tail){
                tail = predecessor;
                tail->next = head;
            }
            delete nodeToDelete;
            n--;
            if(n == 0){
                head = tail = nullptr;
            }
        }
        void deleteWithoutPrevious(SNode* nodeToDelete){
            if(nodeToDelete == nullptr){
                cout << "Node to be deleted is null." << endl;
                return;
            }
            
            if(head == nullptr){
                cout << "List is empty" << endl;
                return;
            }
            
            // Single node case
            if(head == tail && head == nodeToDelete){
                delete head;
                head = tail = nullptr;
                n = 0;
                cout << "Deleted only node" << endl;
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
            
            if(!nodeFound){
                cout << "Node not found in list" << endl;
                return;
            }
            
            if(nodeToDelete == head) {
                predecessor = tail;  // In circular list, tail points to head
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
            
            if(predecessor == nullptr){
                cout << "Error: Could not find predecessor" << endl;
                return;
            }
            
            cout << "Deleting node " << nodeToDelete->data << endl;
            
            if(nodeToDelete == head){
                head = head->next;
                tail->next = head;
            } else {
                predecessor->next = nodeToDelete->next;
            }
            
            if(nodeToDelete == tail){
                tail = predecessor;
            }
            
            delete nodeToDelete;
            n--;
            
            if(n == 0){
                head = tail = nullptr;
            }
        }
};