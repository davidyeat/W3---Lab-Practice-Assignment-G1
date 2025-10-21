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
};