#include <iostream>
#include "SkipList.h"

int main()
{
    SkipList* s = new SkipList();
    s->Add(0);
    s->Add(2);
    s->Add(3);
    s->Add(4);
    s->Add(5);

    std::cout << s->Search(3) << std::endl;

    delete s;
}
