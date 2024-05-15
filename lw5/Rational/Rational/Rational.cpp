#include <iostream>
#include "CRational.h"

int main()
{
    //int a, b;
    //a = 12;
    //b = 24;
    //int c = b % a;
    //std::cout << c << std::endl;

    //std::cout << LCM(6, 5);
    CRational a(4, 1);
    CRational b(2, 3);
    CRational c = a * b;
    std::cout << a.GetNumerator() << "/" << a.GetDenominator() << std::endl;
    std::cout << b.GetNumerator() << "/" << b.GetDenominator() << std::endl;
    std::cout << c.GetNumerator() << "/" << c.GetDenominator() << std::endl;
    std::cout << a << std::endl;
    std::cout << b.GetNumerator() << "/" << b.GetDenominator() << "!=" << a.GetNumerator() << "/" << a.GetDenominator() << " " << (a != b) << std::endl;
    return 0;
}
