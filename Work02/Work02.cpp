#include "CustomArray.h"
#include <vld.h>
#include <memory>
#include "CustomList.h"

int main()
{
    CustomArray a;
    a.push(2);
    a.push(2);
    a.insert(2, 10);
    a.push(2);
    a.push(2);

    for (int i = 0; i < a.CurrentLength; i++)
    {
        std::cout << a.get(i) << std::endl;
    }

    std::unique_ptr<CustomList<int>> List = std::make_unique<CustomList<int>>();
    // CustomList<int>* a = new CustomList<int>();
    auto node = List->Push(3);
    auto node2 = List->Push(4);
    List->Insert(node2, 10);
    List->Push(5);

    Node<int>* Temp = List->Find(10);

    List->Remove(node);

    while (Temp) {
        std::cout << Temp->Value << std::endl;
        Temp = Temp->Next;
    }

    List->PopAll();

    Temp = List->GetHead();

    while (Temp)
    {
        std::cout << Temp->Value << std::endl;
        Temp = Temp->Next;
    }
}