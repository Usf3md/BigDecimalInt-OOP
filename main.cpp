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
    bool operator>(BigDecimalInt anotherDec)
    {
        if (anotherDec.signChar == '-' && signChar == '+')
        {
            return true;
        }
        else if (anotherDec.signChar == '+' && signChar == '+')
        {
            if (anotherDec.num.size() > num.size())
            {
                return false;
            }
            else if (anotherDec.num.size() < num.size())
            {
                return true;
            }
            else
            {
                for (int i = 0; i < num.size();)
                {
                    if (num[i] == anotherDec.num[i])
                    {
                        i++;
                    }
                    else
                    {
                        if (num[i] > anotherDec.num[i])
                        {
                            return true;
                        }
                        else
                        {
                            return false;
                        }
                    }
                }
            }
        }
        else if (anotherDec.signChar == '+' && signChar == '-')
        {
            return false;
        }
        else if (anotherDec.signChar == '-' && signChar == '-')
        {
            if (anotherDec.num.size() > num.size())
            {
                return true;
            }
            else if (anotherDec.num.size() < num.size())
            {
                return false;
            }
            else
            {
                for (int i = 0; i < num.size();)
                {
                    if (num[i] == anotherDec.num[i])
                    {
                        i++;
                    }
                    else
                    {
                        if (num[i] > anotherDec.num[i])
                        {
                            return false;
                        }
                        else
                        {
                            return true;
                        }
                    }
                }
            }
        }
    }

    // Ali El Iraqi Code <
public:
    // Ali El Iraqi Code <
public:
    bool operator<(BigDecimalInt anotherDec)
    {
        if (anotherDec.signChar == '-' && signChar == '+')
        {
            return false;
        }
        else if (anotherDec.signChar == '+' && signChar == '+')
        {
            if (anotherDec.num.size() > num.size())
            {
                return true;
            }
            else if (anotherDec.num.size() < num.size())
            {
                return false;
            }
            else
            {
                for (int i = 0; i < num.size();)
                {
                    if (num[i] == anotherDec.num[i])
                    {
                        i++;
                    }
                    else
                    {
                        if (num[i] > anotherDec.num[i])
                        {
                            return false;
                        }
                        else
                        {
                            return true;
                        }
                    }
                }
            }
        }
        else if (anotherDec.signChar == '+' && signChar == '-')
        {
            return true;
        }
        else if (anotherDec.signChar == '-' && signChar == '-')
        {
            if (anotherDec.num.size() > num.size())
            {
                return false;
            }
            else if (anotherDec.num.size() < num.size())
            {
                return true;
            }
            else
            {
                for (int i = 0; i < num.size();)
                {
                    if (num[i] == anotherDec.num[i])
                    {
                        i++;
                    }
                    else
                    {
                        if (num[i] > anotherDec.num[i])
                        {
                            return true;
                        }
                        else
                        {
                            return false;
                        }
                    }
                }
            }
        }
    }

    // USF EMAD CODE
public:
    BigDecimalInt(string DecStr) // Overload for string inputs
    {
        signChar = getSign(DecStr);
        if (signChar == '-')
        {
            signInt = -1;
        }
        num = removeSign(DecStr);
        if ((signChar != '-') && (signChar != '+'))
        {
            throw invalid_argument("Beginning is not a sign!");
        }
        for (int i = 0; i < num.length(); i++)
        {
            if (!isdigit(num[i]))
            {
                throw invalid_argument("Digits allowed only!");
            }
        }
    };
    BigDecimalInt(int DecInt) // overload for integer inputs
    {
        string DecStr = to_string(DecInt);
        signChar = getSign(DecStr);
        if (signChar == '-')
        {
            signInt = -1;
        }
        num = removeSign(DecStr);
    };

    BigDecimalInt operator+(BigDecimalInt anotherDec) // Not Complete
    {
        int carry = 0;
        bool switched = false;
        BigDecimalInt biggest = (num.length() > anotherDec.num.length() ? *this : anotherDec);
        BigDecimalInt smallest = (num.length() > anotherDec.num.length() ? anotherDec : *this);
        string zeros;
        for (int i = 0; i < biggest.num.length() - smallest.num.length(); i++)
        {
            zeros += "0";
        }
        if (biggest.signInt == -1)
        {
            biggest.signInt *= -1;
            smallest.signInt *= -1;
            switched = true;
        }
        smallest.num = zeros + smallest.num;
        string sum;
        int value;
        for (int i = biggest.num.length() - 1; i >= 0; i--)
        {
            value = carry + biggest.signInt * (biggest.num[i] - 48) + smallest.signInt * (smallest.num[i] - 48);
            carry = 0;
            if (value >= 0)
            {
                if ((value > 9))
                {
                    carry = value / 10;
                    sum = to_string(abs(value - (value / 10) * 10)) + sum;
                }
                else
                {
                    sum = to_string(abs(value)) + sum;
                }
            }
            else
            {
                carry = -1;
                sum = to_string(abs(value + 10)) + sum;
            }
            if (i == 0 && carry)
            {
                sum = to_string(abs(carry)) + sum;
            }
        }
        for (int i = 0; i < sum.length(); i++)
        {
            if (sum[0] == '0')
            {
                sum = sum.erase(0, 1);
            }
            else
            {
                break;
            }
        }
        if (switched)
        {
            biggest.signInt *= -1;
            smallest.signInt *= -1;
        }
        sum = ((biggest.signChar == '+') ? "+" : "-") + sum;
        return BigDecimalInt(sum);
    }

    string getNum()
    {
        return ((signChar == '+') ? "+" : "-") + num;
    }

private:
    int getSign(string s)
    {
        if (s[0] == '-')
        {
            return '-';
        }
        return '+';
    }
    string removeSign(string s) // removes the +/- signs at the beginning of the string
    {
        if (!isdigit(s[0]))
        {
            s = s.erase(0, 1);
        }
        return s;
    }

public:
    bool operator==(BigDecimalInt anotherDec)
    {
        return (getNum() == anotherDec.getNum());
    }
    //==============================================================================
    BigDecimalInt operator=(BigDecimalInt anotherDec)
    {
        num = anotherDec.num;
        signChar = anotherDec.signChar;
        signInt = anotherDec.signInt;
        return anotherDec;
    }
    //==============================================================================
    int size()
    {
        return num.size();
    }
    //==============================================================================
    int sign()
    {
        return signChar;
    }
    //==============================================================================
    friend ostream &operator<<(ostream &out, BigDecimalInt b);
};
ostream &operator<<(ostream &out, BigDecimalInt b)
{
    out << b.getNum();
    return out;
}

int main()
{
    BigDecimalInt num1("123456789012345678901234567890");
    BigDecimalInt num2("+113456789011345678901134567890");
    BigDecimalInt num3("-200000000000000000000000000000");
    BigDecimalInt num4 = num1 + num2;
    // BigDecimalInt num5 = num2 - num1;
    cout << num1 + num2 << endl;
    cout << "num1 = " << num1 << endl;
    cout << "num2 = " << num2 << endl;
    // Next statement will print 236913578023691357802369135780
    cout << "num2 + num1 = " << num4 << endl;

    // Next statement will print -313456789011345678901134567890
    // cout << "num2 - num1 = " << num5 << endl;
}