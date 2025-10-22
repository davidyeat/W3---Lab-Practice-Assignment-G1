#include <iostream>
#include "Utils/Part_B.hpp"
using namespace std;

int main() {
    
    SLB history;
    history.addFront("one");
    history.addFront("two");
    history.addFront("three");
    history.addFront("four");

    history.print_by_pointer();
    history.RemoveFront();
    history.print_by_pointer();

    VectorUndo history2;
    history2.addAction("one");
    history2.addAction("two");
    history2.addAction("three");
    history2.addAction("four");

    history2.printList();
    history2.undo();
    history2.printList();


    
    return 0;
}