#ifndef NODE;
#define NODE;


struct SNode{
    int value;
    SNode* next;
};

struct DNode{
    int value;
    DNode* next;
    DNode* prev;
};

#endif

