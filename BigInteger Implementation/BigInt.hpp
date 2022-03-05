/**
 ********GROUP-14(G-14)*******
 *Yatharth Anand   BT20CSE009*
 *Alastair D'souza BT20CSE027*
 *Garvit Verma     BT20CSE078*
 *****************************
 **/

#include <bits/stdc++.h>

using namespace std;

class BigInt
{
public:
    string digits;

    //  Constructors
    BigInt(long long int n = 0);
    BigInt(string &);
    BigInt(const char *);
    BigInt(BigInt &);

    //  Addition and Subtraction
    friend BigInt operator+(const BigInt &, const BigInt &);
    friend BigInt operator-(const BigInt &, const BigInt &);

    // Assignment
    BigInt &operator=(const BigInt &);

    friend int length(const BigInt &);

    // Read and Write
    friend ostream &operator<<(ostream &, const BigInt &);
    friend istream &operator>>(istream &, BigInt &);
};

//  Acts as a default constructor for the objects created.
BigInt::BigInt(long long int n)
{
    while (n)
    {
        digits.push_back(n % 10);
        n /= 10;
    }
}

//  If a string is passed through the constructor
//  Storing the string into digits in reverse order
BigInt::BigInt(string &pString)
{
    string temp = pString;
    this->digits = "";
    int n = pString.length();
    for (int i = n - 1; i >= 0; i--)
    {
        if (!isdigit(temp[i]) && (temp[i] != '-'))
            cout << "\nValue passed is not a number\n";
        if (isdigit(temp[i]))
        {
            this->digits.push_back(pString[i] - '0');
        }
        if (temp[i] == '-')
        {
            this->digits.push_back(pString[i] - '0');
        }
    }
}

BigInt::BigInt(const char *c)
{
    this->digits = "";
    for (int i = strlen(c) - 1; i >= 0; i--)
    {
        if (!isdigit(c[i]) && (c[i] != '-'))
            cout << "Value passed is not a number";
        if (isdigit(c[i]))
        {
            this->digits.push_back(c[i] - '0');
        }
        if (c[i] == '-')
        {
            this->digits.push_back('-');
        }
    }
}

BigInt::BigInt(BigInt &a)
{
    digits = a.digits;
}

BigInt &BigInt::operator=(const BigInt &a)
{
    digits = a.digits;
    return *this;
}

int Length(const BigInt &bi)
{
    return bi.digits.size();
}

BigInt operator+(const BigInt &a, const BigInt &b)
{
    BigInt temp;
    temp = a;
    BigInt tempb;
    tempb = b;

    int carry = 0, sum, i;
    int aLength = Length(temp), bLength = Length(b);
    // if (bLength > aLength)
    //     temp.digits.append(bLength - aLength, 0);
    // aLength = Length(a);

    //  If both numbers are negative.
    if (temp.digits.back() == '-' && tempb.digits.back() == '-') //  z = (-x) + (-y)
    {

        temp.digits.pop_back();
        tempb.digits.pop_back();

        aLength = Length(temp);
        bLength = Length(tempb);

        if (bLength > aLength)
            temp.digits.append(bLength - aLength, 0);
        aLength = Length(temp);

        for (i = 0; i < aLength; i++)
        {
            if (i < bLength)
                sum = (temp.digits[i] + tempb.digits[i]) + carry;
            else
                sum = temp.digits[i] + carry;
            carry = sum / 10;
            temp.digits[i] = (sum % 10);
        }
        if (carry)
            temp.digits.push_back(carry);

        temp.digits.append("-");

        return temp;
    }
    else if ((temp.digits.back() == '-') && (tempb.digits.back() != '-')) //  z = (-x) + (y)
    {
        temp.digits.pop_back();
        temp = tempb - temp;
        return temp;
    }
    else if ((temp.digits.back() != '-') && (tempb.digits.back() == '-')) //  z = (x) + (-y)
    {
        tempb.digits.pop_back();
        temp = temp - tempb;
        return temp;
    }
    else //  z = (x) + (y)
    {
        //  Normal addition

        if (bLength > aLength)
            temp.digits.append(bLength - aLength, 0);
        aLength = Length(temp);

        for (i = 0; i < aLength; i++)
        {
            if (i < bLength)
                sum = (temp.digits[i] + b.digits[i]) + carry;
            else
                sum = temp.digits[i] + carry;
            carry = sum / 10;
            temp.digits[i] = (sum % 10);
        }
        if (carry)
            temp.digits.push_back(carry);

        return temp;
    }
}

BigInt operator-(const BigInt &a, const BigInt &b)
{
    BigInt temp;
    temp = a;
    BigInt tempb;
    tempb = b;

    int borrow = 0, diff, i;
    int aLength, bLength;

    if (tempb.digits.back() != '-' && temp.digits.back() == '-') //  z = (-x) - (y)
    {
        temp.digits.pop_back();
        aLength = Length(temp);
        bLength = Length(tempb);

        if (bLength > aLength)
            temp.digits.append(bLength - aLength, 0);
        aLength = Length(temp);

        for (i = 0; i < aLength; i++)
        {
            if (i < bLength)
                diff = (temp.digits[i] + tempb.digits[i]) + borrow;
            else
                diff = temp.digits[i] + borrow;
            borrow = diff / 10;
            temp.digits[i] = (diff % 10);
        }
        if (borrow)
            temp.digits.push_back(borrow);

        temp.digits.append("-");

        return temp;
    }
    else if (tempb.digits.back() == '-' && temp.digits.back() != '-') //  z = (x) - (-y)
    {
        tempb.digits.pop_back();
        temp = temp + tempb;
        return temp;
    }
    else if (temp.digits.back() == '-' && tempb.digits.back() == '-') //  z = (-x) - (-y)
    {
        temp.digits.pop_back();
        tempb.digits.pop_back();
        temp = tempb - temp;
        return temp;
    }
    else //  z = (x) - (y)
    {
        aLength = Length(temp);
        bLength = Length(tempb);

        if (aLength < bLength)
        {
            temp = b;
            tempb = a;
            aLength = Length(temp);
            bLength = Length(tempb);

            for (i = 0; i < aLength; i++)
            {
                if (i < bLength)
                    diff = (temp.digits[i] - tempb.digits[i]) + borrow;
                else
                    diff = temp.digits[i] + borrow;
                if (diff < 0)
                    diff += 10,
                        borrow = -1;
                else
                    borrow = 0;
                temp.digits[i] = diff;
            }
            while (aLength > 1 && temp.digits[aLength - 1] == 0)
                temp.digits.pop_back(),
                    aLength--;
            temp.digits.append("-");
        }
        else if (bLength == aLength)
        {
            int flag = 0;
            for (int i = bLength - 1; i >= 0; i--)
            {
                if (tempb.digits[i] > temp.digits[i])
                {
                    flag++;
                }
            }
            if (flag != 0)
            {
                temp = b;
                tempb = a;

                for (i = 0; i < aLength; i++)
                {
                    if (i < bLength)
                        diff = (temp.digits[i] - tempb.digits[i]) + borrow;
                    else
                        diff = temp.digits[i] + borrow;
                    if (diff < 0)
                        diff += 10,
                            borrow = -1;
                    else
                        borrow = 0;
                    temp.digits[i] = diff;
                }
                while (aLength > 1 && temp.digits[aLength - 1] == 0)
                    temp.digits.pop_back(),
                        aLength--;
                temp.digits.append("-");
            }
            else
            {
                for (i = 0; i < aLength; i++)
                {
                    if (i < bLength)
                        diff = (temp.digits[i] - tempb.digits[i]) + borrow;
                    else
                        diff = temp.digits[i] + borrow;
                    if (diff < 0)
                        diff += 10,
                            borrow = -1;
                    else
                        borrow = 0;
                    temp.digits[i] = diff;
                }
                while (aLength > 1 && temp.digits[aLength - 1] == 0)
                    temp.digits.pop_back(),
                        aLength--;
            }
        }
        else
        {
            for (i = 0; i < aLength; i++)
            {
                if (i < bLength)
                    diff = (temp.digits[i] - tempb.digits[i]) + borrow;
                else
                    diff = temp.digits[i] + borrow;
                if (diff < 0)
                    diff += 10,
                        borrow = -1;
                else
                    borrow = 0;
                temp.digits[i] = diff;
            }
            while (aLength > 1 && temp.digits[aLength - 1] == 0)
                temp.digits.pop_back(),
                    aLength--;
        }

        return temp;
    }
}

ostream &operator<<(ostream &out, const BigInt &a)
{
    for (int i = a.digits.size() - 1; i >= 0; i--)
        if (a.digits[i] == '-')
        {
            cout << a.digits[i];
        }
        else
        {
            cout << (short)a.digits[i];
        }
    return cout;
}