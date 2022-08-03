// Work01.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vld.h>
#include "CustomString.h"

int main()
{
    CustomString MyString1 = CustomString("asddasbsdd");
    CustomString MyString2 = CustomString("test");

    MyString1 = CustomString(std::move(MyString2));


    /*CustomString MyString = CustomString(",asddasbsdd,");

    std::cout << MyString.CustomChars << std::endl;

	CustomString MyString1 = MyString.sub(0, 2);

    MyString1.append("b");

	std::cout << MyString1.CustomChars << std::endl << (MyString == MyString1) << std::endl << MyString1.find("asb") << std::endl;

    CustomString* MyString2 = MyString.split(",");

    std::cout << MyString2[0].CustomChars << " " << MyString2[1].CustomChars << " " << MyString2[2].CustomChars << " ";

    delete[] MyString2;*/

    // std::cout << a.CustomChars;
}

