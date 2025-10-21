#include <iostream>
#include "Utils/CSLL.hpp"
#include "Utils/Sll.hpp"
#include "Utils/Dll.hpp"
using namespace std;

int main(){
    CSll cs_list;
    SLL s_list;
    DLL d_list;
    
    cs_list.genList(100);
    s_list.genList(100);

    s_list.push_front(20);
    s_list.pop_front();
    s_list.push_front(35);
    s_list.pop_back();
    s_list.push_back(46);
    

    d_list.push_front(48);
    d_list.push_back(98);
    d_list.push_front(26);
    d_list.pop_front();
    d_list.pop_back();

   cs_list.csll_observe(&cs_list, CSll::print_by_n, "CSLL Time ");
   s_list.sll_observe(&s_list, SLL::print_by_pointer, "SLL Time");
    return 0;
}