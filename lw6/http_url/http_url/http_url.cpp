
#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>
#include "CHttpUrl.h"
#include "UrlHandler.h"

int main()
{
    CUrlHandler handle;
    handle.Handle(std::cin, std::cout);

    return 0;
}