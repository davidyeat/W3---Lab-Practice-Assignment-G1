#ifndef NODE
#define NODE
    struct SNode
    {
        int data;
        SNode* next;
    };
    struct DNode
    {
        int data;
        DNode* next;
        DNode* prev;
    };
    
#endif