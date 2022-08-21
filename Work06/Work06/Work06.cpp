#include <iostream>
#include "SkipList.h"
#include <windows.h>

double stopwatch()
{
    unsigned long long ticks;
    unsigned long long ticks_per_sec;
    QueryPerformanceFrequency((LARGE_INTEGER*)&ticks_per_sec);
    QueryPerformanceCounter((LARGE_INTEGER*)&ticks);
    return ((float)ticks) / (float)ticks_per_sec;
}

int randomLevel() {
    int Level = 1;
    while (rand() % 100 < 49 && Level < 32) {
        Level++;
    }
    return Level;
}

int main()
{
    SkipList* skipList = new SkipList(randomLevel);
    SkipList* List = new SkipList([](){return 1; }); //跳表层级为1时退化为普通链表

    double start = stopwatch();

    for (int i = 0; i < 1000 * 50; i++) {
        skipList->Add(i);
    }

    skipList->Search(99999);

    double T = stopwatch() - start;
    std::cout << "SkipList Cost Time: " << T << std::endl;

    start = stopwatch();

    for (int i = 0; i < 1000 * 50; i++) {
        List->Add(i);
    }

    List->Search(99999);

    T = stopwatch() - start;
    std::cout << "Nomal Cost Time: " << T << std::endl;

    delete skipList;
    delete List;
}
