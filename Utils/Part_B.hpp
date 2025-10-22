#include<iostream>
#include<string>
#include<chrono>
#include<vector>
#include<string>

using namespace std;
using clk = chrono::high_resolution_clock;

struct SNode{
    string data;
    SNode* next;
};

struct DNode{
    string data;
    DNode* next;
    DNode* prev;
};

class SLB{
    private:
        SNode* head, *cur;
        int n;
    public:
        SLB(){ 
            head = nullptr;
            n=0;
        }
        void addFront(const string item){
            SNode* newNode = new SNode{item, head};
            head= newNode;
            n++;
        }

        void RemoveFront(){
            if(!head)return;
            SNode* temp = head;
            head = head-> next;
            delete temp;
            n--;
        }

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

    

        ~SLB(){
            while (head) RemoveFront();
        }

        void sll_observe(SLB* obj, void (SLB::*method)(), string msg){
        auto t0 = clk::now();

        (obj->*method)(); // perform operation

        auto t1 = clk::now();

        auto duration = chrono::duration_cast<chrono::nanoseconds>(t1 - t0);
        cout<<msg <<": "<<duration.count() <<" nanosecond(s)" <<endl;
    }
};

class DLB{
    private:
        DNode* head;
    public:
        DLB(): head(nullptr){}
        void addFront(const string item){
            DNode* newNode = new DNode{item, head, nullptr};
            if(head)head->prev = newNode;
            head= newNode;
        }

        void RemoveFront(){
            if(!head)return;
            DNode* temp = head;
            head = head-> next;
            if(head)head->prev = nullptr;
            delete temp;
        
        }

        void print_by_pointer(){
            DNode*  newNode = head;
            if(head == nullptr){
                cout << "List is empty!" << endl;
                return;
            }
            while(head != nullptr){
                cout <<head ->data<< "->";
                head = head->next;
            }
            
            cout << endl;
        }

    

        ~DLB(){
            while (head) RemoveFront();
        }

        void hll_observe(DLB* obj, void (DLB::*method)(), string msg){
        auto t0 = clk::now();

        (obj->*method)(); // perform operation

        auto t1 = clk::now();

        auto duration = chrono::duration_cast<chrono::nanoseconds>(t1 - t0);
        cout<<msg <<": "<<duration.count() <<" nanosecond(s)" <<endl;
    }
};


class VectorUndo {
    vector<string> history;
    
public:
        void addAction(const std::string& action) {
            history.push_back(action); // amortized O(1)
            
        }

        void undo() {
            if (!history.empty())
                history.pop_back(); // O(1)
                
        }
        void printList(){
            if (history.empty()) {
                cout << "[ Empty ]" << endl;
                return;
            }

            // Loop from the last valid index (size - 1) down to 0
            for (int i = history.size() - 1; i >= 0; --i) {
                cout << history[i] << " ";
            }
            cout<<endl;
        }

};



