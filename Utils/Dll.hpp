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
};