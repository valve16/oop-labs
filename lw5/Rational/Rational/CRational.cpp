#include "CRational.h"

const char SLASH = '/';

CRational::CRational() 
	: m_num(0)
	, m_denom(1)
{
}

CRational::CRational(int value)
	: m_num(value)
	, m_denom(1)
{
}

int GCD(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int LCM(int a, int b)
{
    return (a / GCD(a, b)) * b;
}


CRational::CRational(int numerator, int denominator)
{
    if (denominator == 0) 
    {
        CRational();
    }
    else 
    {
        int gcd = GCD(numerator, denominator);
        m_num = numerator / gcd;
        m_denom = denominator / gcd;
        if (m_denom < 0) 
        {
            m_num = -m_num;
            m_denom = -m_denom;
        }
    }
}

int CRational::GetNumerator() const
{
    return m_num;
}

int CRational::GetDenominator() const
{
    return m_denom;
}

double CRational::ToDouble() const 
{
    return static_cast<double>(m_num) / m_denom; 
}

CRational CRational::operator -()const
{
    return CRational(-m_num, m_denom);
}

CRational CRational::operator +()const
{
    return *this;
}

CRational CRational::operator+=(const CRational& num)
{
    *this = *this + num;
    return *this;
}

CRational CRational::operator-=(const CRational& num)
{
    *this = *this - num;
    return *this;
}

CRational CRational::operator*=(const CRational& num)
{
    *this = *this * num;
    return *this;
}

CRational CRational::operator/=(const CRational& num)
{
    *this = *this / num;
    return *this;
}

CRational operator+(const CRational& num1, const CRational& num2)
{
    int lcm = LCM(num1.GetDenominator(), num2.GetDenominator());
    return CRational(num1.GetNumerator() * (lcm / num1.GetDenominator()) +
        num2.GetNumerator() * (lcm / num2.GetDenominator()), lcm);
}

CRational operator-(const CRational& num1, const CRational& num2)
{
    int lcm = LCM(num1.GetDenominator(), num2.GetDenominator());
    return CRational(num1.GetNumerator() * (lcm / num1.GetDenominator()) -
        num2.GetNumerator() * (lcm / num2.GetDenominator()), lcm);
}

CRational operator*(const CRational& num1, const CRational& num2)
{
    return CRational(num1.GetNumerator() * num2.GetNumerator(),
        num1.GetDenominator() * num2.GetDenominator());
}

CRational operator/(const CRational& num1, const CRational& num2)
{
    return CRational(num1.GetNumerator() * num2.GetDenominator(),
        num1.GetDenominator() * num2.GetNumerator());
}

bool operator==(const CRational& num1, const CRational& num2)
{
    return num1.GetNumerator() == num2.GetNumerator() 
        && num1.GetDenominator() == num2.GetDenominator();
}

bool operator!=(const CRational& num1, const CRational& num2)
{
    return num1.GetNumerator() != num2.GetNumerator() 
        || num1.GetDenominator() != num2.GetDenominator();
}

bool operator>(const CRational& num1, const CRational& num2)
{
    int lcm = LCM(num1.GetDenominator(), num2.GetDenominator());
    return (num1.GetNumerator() * (lcm / num1.GetDenominator()) >
        num2.GetNumerator() * (lcm / num2.GetDenominator()));
}

bool operator<(const CRational& num1, const CRational& num2)
{
    return num2 > num1;
}

bool operator<=(const CRational& num1, const CRational& num2)
{
    return !(num1 > num2);
}

bool operator>=(const CRational& num1, const CRational& num2)
{
    return !(num1 < num2);
}

std::istream& operator>>(std::istream& is, CRational& rational) {
    char symb;
    int num, denom;
    is >> num >> symb >> denom;
    if (symb != SLASH) 
    {
        is.setstate(std::ios_base::failbit);
    }
    else
    {
        rational = CRational(num, denom);
    }
    return is;
}

std::ostream& operator<<(std::ostream& os, const CRational& rational) {
    os << rational.GetNumerator() << SLASH << rational.GetDenominator();
    return os;
}