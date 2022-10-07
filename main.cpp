#include <iostream>
#include <string>

using namespace std;

class BigDecimalInt
{
    string num;

    // Ali El Iraqi Code
public:
    bool operator<(BigDecimalInt anotherDec)
    {
        if (anotherDec.num[0] == '-' && num[0] == '+')
        {
            return false;
        }
        else if (anotherDec.num[0] == '+' && num[0] == '+')
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
        else if (anotherDec.num[0] == '+' && num[0] == '-')
        {
            return true;
        }
    }

    // USF EMAD CODE
public:
    BigDecimalInt(string DecStr) // Overload for string inputs
    {
        num = addPositiveSign(DecStr);
    };
    BigDecimalInt(int DecInt) // overload for integer inputs
    {
        string DecStr = to_string(DecInt);
        num = addPositiveSign(DecStr);
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
        return ((num[0] == '+') ? "+" : "-") + num[0];
    }

private:
    string addPositiveSign(string s) // adds the + sign at the beginning of the string
    {
        if (isdigit(s[0]))
        {
            return "+" + s;
        }
        return s;
    }
};

int main()
{
    BigDecimalInt bigNumber("-4");
    BigDecimalInt smallNumber("-5");

    // BigDecimalInt firstNumber("-1036444444444463464363468");
    // BigDecimalInt secondNumber("20834643634634643643643436436");
    // BigDecimalInt sumNumber = firstNumber + secondNumber;
    // cout << sumNumber.getNum();
    cout << (bigNumber < smallNumber);
}
