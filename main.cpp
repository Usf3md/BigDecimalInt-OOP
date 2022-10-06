#include <iostream>
#include <string>

using namespace std;

class BigDecimalInt
{
    string num;
    //int sign;
    char sign;

// Ali El Iraqi Code
public:
        bool operator<(BigDecimalInt anotherDec){
        if(anotherDec.sign == '-' and sign == '+'){
            return false;
        }else if(anotherDec.sign == '+' and sign == '+'){
            if(anotherDec.num.size() > num.size()){
                return true;
            }
            else if(anotherDec.num.size() < num.size()){
                return false;
            }else{
                for(int i = 0; i < num.size();){
                    if(num[i] == anotherDec.num[i]){
                        i++;
                    }
                    else{
                        if(num[i] > anotherDec.num[i]){
                            return false;
                        }
                        else{
                            return true;
                        }
                    }
                }
            }
        }else if (anotherDec.sign == '+' and sign == '-'){
            return true;
        }
    }
    
// USF EMAD CODE
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
        return ((sign == '+') ? "+" : "-") + num;
    }

private:
    int getSign(string s) // gets the sign of the number and returns 1 or -1
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
};

int main()
{
    BigDecimalInt bigNumber("-2345237857235872350235707832598757392");
    BigDecimalInt smallNumber("+537238957983257983275982735735298235");

    // BigDecimalInt firstNumber("-1036444444444463464363468");
    // BigDecimalInt secondNumber("20834643634634643643643436436");
    // BigDecimalInt sumNumber = firstNumber + secondNumber;
    // cout << sumNumber.getNum();
    cout << (bigNumber < smallNumber);
}
