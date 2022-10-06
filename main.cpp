#include <iostream>
#include <string>

using namespace std;

class BigDecimalInt
{
    string num;
    int sign;

public:
    BigDecimalInt(string DecStr) // Overload for string inputs
    {
        sign = getSign(DecStr);
        num = removeSign(DecStr);
    };
    BigDecimalInt(int DecInt) // overload for integer inputs
    {
        string DecStr = to_string(DecInt);
        sign = getSign(DecStr);
        num = removeSign(DecStr);
    };

    BigDecimalInt operator+(BigDecimalInt anotherDec) // Not Complete
    {
        // int carry = 0;
        // BigDecimalInt biggest = (num.length() > anotherDec.num.length() ? *this : anotherDec);
        // BigDecimalInt smallest = (num.length() > anotherDec.num.length() ? anotherDec : *this);
        // string zeros;
        // for (int i = 0; i < biggest.num.length() - smallest.num.length(); i++)
        // {
        //     zeros += "0";
        // }
        // smallest.num = zeros + smallest.num;
        // string sum;
        // int value;
        // for (int i = biggest.num.length() - 1; i >= 0; i--)
        // {
        //     value = carry + biggest.sign * (biggest.num[i] - 48) + smallest.sign * (smallest.num[i] - 48);
        //     carry = 0;
        //     sum = to_string(value)[to_string(value).length() - 1] + sum;
        //     carry = value / 10;
        // }
        // sum = ((biggest.sign == 1) ? "+" : "-") + sum;
        // return BigDecimalInt(sum);
    }

    string getNum()
    {
        return ((sign == 1) ? "+" : "-") + num;
    }

private:
    int getSign(string s) // gets the sign of the number and returns 1 or -1
    {
        if (s[0] == '-')
        {
            return -1;
        }
        return 1;
    }
    string removeSign(string s) // removes the +/- signs at the beginning of the string
    {
        if (!isdigit(s[0]))
        {
            s = s.erase(0, 1);
        }
        return s;
    }
};

int main()
{
    // BigDecimalInt firstNumber("-108");
    // BigDecimalInt secondNumber("208");
    // BigDecimalInt sumNumber = firstNumber + secondNumber;
    // cout << sumNumber.getNum();
}
