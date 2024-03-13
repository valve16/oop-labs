#include <iostream>
#include "StringProcess.h"
#include <string>

int main(int argc, char* argv[]) 
{
    if (argc != 1)
    {
        std::cout << "Invalid arguments count\n";
        return 1;
    }

    std::string line;
    while (std::getline(std::cin, line)) 
    {
        std::cout << HtmlDecode(line) << std::endl;
    }

    if (std::cin.bad())
    {
        std::cout << "Fail to read file";
        return 1;
    }

    return 0;
}