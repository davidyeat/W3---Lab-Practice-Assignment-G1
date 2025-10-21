#include <iostream>
#include "Utils/CSLL.hpp"
#include "Utils/Sll.hpp"
using namespace std;

int main(){
    CSll cs_list;
    SLL s_list;

    cs_list.genList(100);
    s_list.genList(100);

    cs_list.csll_observe(&cs_list, CSll::print_by_n, "CSLL Time ");
    s_list.sll_observe(&s_list, SLL::print_by_pointer, "SLL Time");
    return 0;
}