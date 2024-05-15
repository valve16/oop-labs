#pragma once
#include <iostream>
#include <sstream>
class CRational
{
public:
    //  онструирует рациональное число, равное нулю (0/1)
    CRational();

    //  онструирует рациональное число, равное value (value/1)
    CRational(int value);

    //  онструирует рациональное число, равное numerator/denominator
    // –ациональное число должно хранитьс€ в нормализованном виде:
    // знаменатель положительный (числитель может быть отрицательным)
    // числитель и знаменатель не имеют общих делителей (6/8 => 3/4 и т.п.)
    // ≈сли знаменатель равен нулю, должно конструироватьс€ рациональное число, равное нулю,
    // либо должно быть выброшено исключение std::invalid_argument.
    CRational(int numerator, int denominator);

    // ¬озвращает числитель
    int GetNumerator() const;

    // ¬озвращает знаменатель (натуральное число)
    int GetDenominator() const;

    // ¬озвращает отношение числител€ и знаменател€ в виде числа double
    double ToDouble() const;

    // ѕрочие операторы согласно заданию
    CRational operator -()const;
    CRational operator +()const;
    CRational operator+=(const CRational& num);
    CRational operator-=(const CRational& num);
    CRational operator*=(const CRational& num);
    CRational operator/=(const CRational& num);

    std::pair<int, CRational> ToCompoundFraction()const;
    //static int GCD(int a, int b);
   // static int LCM(int a, int b);
private:
    int m_num, m_denom;
};

int LCM(int a, int b);
int GCD(int a, int b);
CRational operator+(const CRational& num1, const CRational& num2);
CRational operator-(const CRational& num1, const CRational& num2);
CRational operator*(const CRational& num1, const CRational& num2);
CRational operator/(const CRational& num1, const CRational& num2);
bool operator==(const CRational& num1, const CRational& num2);
bool operator!=(const CRational& num1, const CRational& num2);
bool operator>(const CRational& num1, const CRational& num2);
bool operator<(const CRational & num1, const CRational & num2);
bool operator<=(const CRational & num1, const CRational & num2);
bool operator>=(const CRational & num1, const CRational & num2);
std::istream& operator>>(std::istream& is, CRational& rational);
std::ostream& operator<<(std::ostream& os, const CRational& rational);