// CMyList.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "CMyList.h"

int main()
{
    CMyList<int> intList;
    intList.push_back(1);
    intList.push_back(2);
    intList.push_front(0);
    auto it = intList.begin();
    ++it;
    intList.insert(it, 3);

    std::cout << "Integer list elements: ";
    for (auto it = intList.begin(); it != intList.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    CMyList<std::string> strList;
    strList.push_back("world");
    strList.push_front("Hello");

    std::cout << "String list elements: ";
    for (auto it = strList.begin(); it != strList.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}
