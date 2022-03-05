#include <iostream>
#include "BigInt.hpp"

using namespace std;

int main()
{
    BigInt a;
    a = "-1234567890123456789012328492479372497568593250324";
    BigInt b("12387587345740345957359727492484864862846283464982462");

    cout << "a = " << a << "\n\n\n";
    cout << "b = " << b << "\n\n\n";

    BigInt sum;
    sum = a + b;
    cout << "a + b = " << sum << "\n\n\n";

    BigInt diff;
    diff = a - b;
    cout << "a - b = " << diff << "\n\n\n";
}