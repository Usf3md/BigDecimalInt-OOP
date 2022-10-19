#ifndef BIG_DECIMAL
#define BIG_DECIMAL

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class BigDecimalInt
{
    string num;
    char signChar;
    int signInt{1};
    // ahmed shaban code
public:
    bool operator>(BigDecimalInt anotherDec);
    // Ali El Iraqi Code <
public:
    bool operator<(BigDecimalInt anotherDec);
    BigDecimalInt operator-(BigDecimalInt anotherDec);
    // USF EMAD CODE
public:
    BigDecimalInt(string DecStr); // Overload for string inputs
    BigDecimalInt(int DecInt);    // overload for integer inputs
    BigDecimalInt operator+(BigDecimalInt anotherDec);
    string getNum();

private:
    string getLeadingZeros(string s1, string s2);
    string removeLeadingZeros(string s);
    int getSign(string s);
    string removeSign(string s); // removes the +/- signs at the beginning of the string
public:
    bool operator==(BigDecimalInt anotherDec);
    //==============================================================================
    BigDecimalInt operator=(BigDecimalInt anotherDec);
    //==============================================================================
    int size();
    //==============================================================================
    int sign();
    //==============================================================================
    friend ostream &operator<<(ostream &out, BigDecimalInt b);
};
ostream &operator<<(ostream &out, BigDecimalInt b);
#endif