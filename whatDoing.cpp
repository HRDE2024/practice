#include <iostream>

using namespace std;

void quotientRemainder() {
    int divisor, dividend, quotient, remainder;

    cout << "Enter dividend: ";
    cin >> dividend;

    cout << "Enter divisor: ";
    cin >> divisor;

    quotient = dividend / divisor;
    remainder = dividend % divisor;

    cout << "Quotient = " << quotient << endl;
    cout << "Remainder = " << remainder << endl;
}

void sizeofVariable() {

    cout << "Size of char: " << sizeof(char) << " byte\n"
         << "Size of int: " << sizeof(int) << " byte\n"
         << "Size of float: " << sizeof(float) << " byte\n"
         << "Size of bool: " << sizeof(bool) << " byte\n"
         << endl;

    return;
}

int main() {

    sizeofVariable();

    return 0;
}

// https://www.youtube.com/watch?v=_u76OwhHOCI
// https://www.programiz.com/cpp-programming/examples/sizeof-operator