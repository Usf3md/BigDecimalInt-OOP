#include <iostream>
#include <string>

using namespace std;

class BigDecimalInt
{
    string num;

    //ahmed shaban code
public:
bool operator>(BigDecimalInt anotherDec){
        if(anotherDec.num[0] == '-' and num[0] == '+'){
            return true;
        }else if(anotherDec.num[0] == '+' and num[0] == '+'){
            if(anotherDec.num.size() > num.size()){
                return false;
            }
            else if(anotherDec.num.size() < num.size()){
                return true;
            }else{
                for(int i = 0; i < num.size();){
                    if(num[i] == anotherDec.num[i]){
                        i++;
                    }
                    else{
                        if(num[i] > anotherDec.num[i]){
                            return true;
                        }
                        else{
                            return false;
                        }
                    }
                }
            }
        }else if (anotherDec.num[0] == '+' and num[0] == '-'){
            return false;
        }else if(anotherDec.num[0] == '-' and num[0] == '-'){
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
        }
    }


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
        }else if(anotherDec.num[0] == '-' and num[0] == '-'){
            if(anotherDec.num.size() > num.size()){
                return false;
            }
            else if(anotherDec.num.size() < num.size()){
                return true;
            }else{
                for(int i = 0; i < num.size();){
                    if(num[i] == anotherDec.num[i]){
                        i++;
                    }
                    else{
                        if(num[i] > anotherDec.num[i]){
                            return true;
                        }
                        else{
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
public:
    bool operator==(BigDecimalInt anotherDec)
    {
        if (sign()==0&&anotherDec.sign()==0)//if nothing nothing
        {
            if (num==anotherDec.num)
                return true;
            else
                return false;
        }
        else if (sign()==-1&&anotherDec.sign()==-1)//if - -
        {
            if (num==anotherDec.num)
                return true;
            else
                return false;
        }
        else if (sign()==1&&anotherDec.sign()==1)//if + +
        {
            if (num==anotherDec.num)
                return true;
            else
                return false;
        }
        else if (sign()==0&&anotherDec.sign()==1)//if nothing +
        {
            anotherDec.num.erase(anotherDec.num.begin());
            if (num==anotherDec.num)
                return true;
            else
                return false;
        }
        else if (sign()==1&&anotherDec.sign()==0)//if + nothing
        {

            num.erase(num.begin());
            if (num==anotherDec.num)
                return true;
            else
                return false;
        }
    }
//==============================================================================
    BigDecimalInt operator= (BigDecimalInt anotherDec)
    {
        num=anotherDec.num;
        return anotherDec;
    }
//==============================================================================
    int size()
    {
        if (num[0]=='-'||num[0]=='+')
            return num.size()-1;
        else
            return num.size();
    }
//==============================================================================
    int sign()
    {
        if (num[0]=='-')
            return -1;
        else if (num[0]=='+')
            return 1 ;
        else
            return 0;
    }
//==============================================================================
    void pr()
    {
        int va = stoi(num);

        cout <<num;
    }
//====================================================================
    friend ostream& operator << (ostream& out, BigDecimalInt b);

};
ostream& operator<< (ostream& out, BigDecimalInt b)
{
    out<<b.num<<endl;
    return out;
}


int main()
{
    string BigDecimalInt1, BigDecimalInt2;
    cout << "Enter the first BigDecimalInt: ";
    cin >> BigDecimalInt1;

    cout << "Enter the second BigDecimalInt: ";
    cin >> BigDecimalInt2;

    BigDecimalInt bigNumber(BigDecimalInt1);
    BigDecimalInt smallNumber(BigDecimalInt2);

    // BigDecimalInt firstNumber("-1036444444444463464363468");
    // BigDecimalInt secondNumber("20834643634634643643643436436");
    // BigDecimalInt sumNumber = firstNumber + secondNumber;
    // cout << sumNumber.getNum();
    if(bigNumber < smallNumber){
        cout << BigDecimalInt2 << endl << "is greater than" << endl << BigDecimalInt1;
    }
    else if(bigNumber > smallNumber){
        cout << BigDecimalInt1 << endl << "is greater than" << endl << BigDecimalInt2;
    }
}
/*#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;
class BigDecimalInt
{
private :
    string num;
public:
    BigDecimalInt(string a )
    {
        num = a;
    }

//======================================================================
    bool operator==(BigDecimalInt anotherDec)
    {
        if (sign()==0&&anotherDec.sign()==0)//if nothing nothing
        {
            if (num==anotherDec.num)
                return true;
            else
                return false;
        }
        else if (sign()==-1&&anotherDec.sign()==-1)//if - -
        {
            if (num==anotherDec.num)
                return true;
            else
                return false;
        }
        else if (sign()==1&&anotherDec.sign()==1)//if + +
        {
            if (num==anotherDec.num)
                return true;
            else
                return false;
        }
        else if (sign()==0&&anotherDec.sign()==1)//if nothing +
        {
            anotherDec.num.erase(anotherDec.num.begin());
            if (num==anotherDec.num)
                return true;
            else
                return false;
        }
        else if (sign()==1&&anotherDec.sign()==0)//if + nothing
        {

            num.erase(num.begin());
            if (num==anotherDec.num)
                return true;
            else
                return false;
        }
    }
//==============================================================================
    BigDecimalInt operator= (BigDecimalInt anotherDec)
    {
        num=anotherDec.num;
        return anotherDec;
    }
//==============================================================================
    int size()
    {
        if (num[0]=='-'||num[0]=='+')
            return num.size()-1;
        else
            return num.size();
    }
//==============================================================================
    int sign()
    {
        if (num[0]=='-')
            return -1;
        else if (num[0]=='+')
            return 1 ;
        else
            return 0;
    }
//==============================================================================
    void pr()
    {
        int va = stoi(num);

        cout <<num;
    }
//====================================================================
    friend ostream& operator << (ostream& out, BigDecimalInt b);

};
ostream& operator<< (ostream& out, BigDecimalInt b)
{
    out<<b.num<<endl;
    return out;
}

int main()
{
    BigDecimalInt bigNumber("7");
    BigDecimalInt smallNumber("9");

    BigDecimalInt firstNumber("-1036444444444463464363468");
    BigDecimalInt secondNumber("20834643634634643643643436436");

    BigDecimalInt num("+65694");
    BigDecimalInt num2("694");
    firstNumber=secondNumber;
    cout<<firstNumber;
    if (smallNumber>bigNumber)
        cout <<"YUP"<<endl;
    else
        cout<<"NO"<<endl;
}
*/
