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
    BigDecimalInt operator-(BigDecimalInt anotherDec)
    {
        anotherDec.signInt *= -1;
        anotherDec.signChar = ((anotherDec.signChar == '+') ? '-' : '+');
        return *this + anotherDec;
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
    }
    BigDecimalInt(int DecInt) // overload for integer inputs
    {
        string DecStr = to_string(DecInt);
        signChar = getSign(DecStr);
        if (signChar == '-')
        {
            signInt = -1;
        }
        num = removeSign(DecStr);
        if (!num.length())
        {
            num = "0";
        }
    }

    BigDecimalInt operator+(BigDecimalInt anotherDec) // Not Complete
    {
        BigDecimalInt first = *this;
        BigDecimalInt second = anotherDec;
        char tempSign[]{first.signChar, second.signChar};
        char mainSign;
        first.signChar = '+';
        second.signChar = '+';
        bool firstIsBigger = (first > second);
        mainSign = tempSign[(firstIsBigger ? 0 : 1)];
        if (firstIsBigger)
        {
            second.num = getLeadingZeros(first.num, second.num) + second.num;
        }
        else
        {
            first.num = getLeadingZeros(second.num, first.num) + first.num;
        }
        if ((first.signInt * second.signInt) != 1)
        {
            first.signChar = (firstIsBigger ? '+' : '-');
            first.signInt = (firstIsBigger ? 1 : -1);
            second.signChar = (firstIsBigger ? '-' : '+');
            second.signInt = (firstIsBigger ? -1 : 1);
        }
        else
        {
            first.signInt = 1;
            second.signInt = 1;
        }

        string sum;
        int carry{0};
        int value{0};
        for (int i = first.num.length() - 1; i >= 0; i--)
        {
            value = carry + first.signInt * (first.num[i] - 48) + second.signInt * (second.num[i] - 48);
            cout << carry << " + " << first.signInt << " * " << (first.num[i] - 48) << " + " << second.signInt << " * " << (second.num[i] - 48) << " = " << value << endl;
            carry = 0;

            if (i > 0)
            {
                if (value > 9)
                {
                    carry = 1;
                    value %= 10;
                }
                else if (value < 0)
                {
                    carry = -1;
                    value += 10;
                }
            }
            sum = to_string(abs(value)) + sum;
        }
        sum = mainSign + removeLeadingZeros(sum);
        return BigDecimalInt(sum);
    }

    string
    getNum()
    {
        return removeLeadingZeros(((num == "0") ? "" : ((signChar == '+') ? "" : "-")) + num);
    }

private:
    string getLeadingZeros(string s1, string s2)
    {
        string zeros;
        for (int i = 0; i < s1.length() - s2.length(); i++)
        {
            zeros += "0";
        }
        return zeros;
    }
    string removeLeadingZeros(string s)
    {
        for (int i = 0; i < s.length() - 1; i++)
        {
            if (s[0] == '0')
            {
                s = s.erase(0, 1);
            }
            else
            {
                break;
            }
        }
        return s;
    }
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
    BigDecimalInt num4 = num2 + num1;
    BigDecimalInt num5 = num2 - num1;
    cout << "num1 = " << num1 << endl;
    cout << "num2 = " << num2 << endl;
    // Next statement will print 236913578023691357802369135780
    cout << "num2 + num1 = " << num4 << endl;
    // Next statement will print -313456789011345678901134567890
    cout << "num2 - num1 = " << num5 << endl;
}