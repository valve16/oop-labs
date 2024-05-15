#pragma once
#include <iostream>
#include <sstream>
class CRational
{
public:
    // ������������ ������������ �����, ������ ���� (0/1)
    CRational();

    // ������������ ������������ �����, ������ value (value/1)
    CRational(int value);

    // ������������ ������������ �����, ������ numerator/denominator
    // ������������ ����� ������ ��������� � ��������������� ����:
    // ����������� ������������� (��������� ����� ���� �������������)
    // ��������� � ����������� �� ����� ����� ��������� (6/8 => 3/4 � �.�.)
    // ���� ����������� ����� ����, ������ ���������������� ������������ �����, ������ ����,
    // ���� ������ ���� ��������� ���������� std::invalid_argument.
    CRational(int numerator, int denominator);

    // ���������� ���������
    int GetNumerator() const;

    // ���������� ����������� (����������� �����)
    int GetDenominator() const;

    // ���������� ��������� ��������� � ����������� � ���� ����� double
    double ToDouble() const;

    // ������ ��������� �������� �������
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