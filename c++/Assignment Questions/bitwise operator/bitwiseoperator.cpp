#include <iostream>
using namespace std;
int main() {
    int a = 5; // In binary: 0101
    int b = 3; // In binary: 0011

    // Bitwise AND
    int andResult = a & b; // Result: 1 (0001 in binary)
    cout << "Bitwise AND of " << a << " and " << b << " is: " << andResult << endl;

    // Bitwise OR
    int orResult = a | b; // Result: 7 (0111 in binary)
    cout << "Bitwise OR of " << a << " and " << b << " is: " << orResult << endl;

    // Bitwise XOR
    int xorResult = a ^ b; // Result: 6 (0110 in binary)
    cout << "Bitwise XOR of " << a << " and " << b << " is: " << xorResult << endl;

    // Bitwise NOT
    int notResultA = ~a; // Result: -6 (in two's complement, ~0101 is 1010)
    cout << "Bitwise NOT of " << a << " is: " << notResultA << endl;

    return 0;
}   
