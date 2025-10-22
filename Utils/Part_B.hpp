#include<iostream>
#include<string>
#include<chrono>

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

class ReTray_S{
    private:
        SNode* head;
    public:
        ReTray_S(): head(nullptr){}
        void addFront(const string item){
            SNode* newNode = new SNode{item, head};
            head= newNode;
        }

        void RemoveFront(){
            if(!head)return;
            SNode* temp = head;
            head = head-> next;
            delete temp;
        
        }

        void print_by_pointer(){
            SNode*  newNode = head;
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

    

        ~ReTray_S(){
            while (head) RemoveFront();
        }

        void sll_observe(ReTray_S* obj, void (ReTray_S::*method)(), string msg){
        auto t0 = clk::now();

        (obj->*method)(); // perform operation

        auto t1 = clk::now();

        auto duration = chrono::duration_cast<chrono::nanoseconds>(t1 - t0);
        cout<<msg <<": "<<duration.count() <<" nanosecond(s)" <<endl;
    }
};

class ReTray_D{
    private:
        DNode* head;
    public:
        ReTray_D(): head(nullptr){}
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

    

        ReTray_D(){
            while (head) RemoveFront();
        }

        void hll_observe(ReTray_D* obj, void (ReTray_D::*method)(), string msg){
        auto t0 = clk::now();

        (obj->*method)(); // perform operation

        auto t1 = clk::now();

        auto duration = chrono::duration_cast<chrono::nanoseconds>(t1 - t0);
        cout<<msg <<": "<<duration.count() <<" nanosecond(s)" <<endl;
    }
};




