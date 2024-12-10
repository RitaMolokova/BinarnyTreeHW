#include <iostream>
#include "list.h"
using namespace std;

int main() {
    list<int> list1;

    list1.push_back(1);
    list1.push_back(2);
    list1.push_back(3);

    list<int> list2;
    list2.push_back(2);

    list<int> list3 = list1 + list2;
    list<int> list4 = list1 * list2;

    list1.show();
    list2.show();
    list3.show();
    list4.show();

    return 0;
}