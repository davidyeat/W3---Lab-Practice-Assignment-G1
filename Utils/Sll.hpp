#include<iostream>
#include<string>
#include "Utils/node.hpp"

using namespace std;

class SLL{
    private:
        SNode *head, *cur, *tail;
        int n;
    public:
        SLL(){
            head=nullptr;
            cur=nullptr;
            n=0;
        }
};