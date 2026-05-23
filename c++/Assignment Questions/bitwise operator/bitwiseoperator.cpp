#include <iostream>
using namespace std;
void onesComplement(int num) {
    int result = ~num; // Bitwise NOT operation
    cout << "One's complement of " << num << " is: " << result << endl;
}
void bitwiseshift(int num) {
    int leftShift = num << 1; // Left shift by 1 (equivalent to multiplying by 2)
    int rightShift = num >> 1; // Right shift by 1 (equivalent to dividing by 2)
    cout << "Left shift of " << num << " is: " << leftShift << endl;
    cout << "Right shift of " << num << " is: " << rightShift << endl;
}
void bitwiseoddoreven(int num) {
    if (num & 1) { // Check the least significant bit
        cout << num << " is odd." << endl;
    } else {
        cout << num << " is even." << endl;
    }
}
void getIthBit(int num, int i) {
    int ithBit = num & (1 << i); // Create a mask with only the ith bit set and perform AND to isolate the ith bit
    cout << "The " << i << "th bit of " << num << " is: " << ithBit << endl;

}
void setIthBit(int &num, int i) {
    num = num | (1 << i); // Set the ith bit by performing a bitwise OR with a mask
    cout << "After setting the " << i << "th bit, the number is: " << num << endl;
}         
void clearIthBit(int &num, int i) {
    num = num & ~(1 << i); // Clear the ith bit by performing a bitwise AND with the negation of a mask
    cout << "After clearing the " << i << "th bit, the number is: " << num << endl;
}
void checkforpoweroftwo(int num) {
    if (num > 0 && (num & (num - 1)) == 0) { // A number is a power of two if it has exactly one bit set
        cout << num << " is a power of two." << endl;
    } else {
        cout << num << " is not a power of two." << endl;
    }
}
void updateithbit(int &num, int i, int v) {
    num = (num & ~(1 << i)) | (v << i); // Clear the ith bit and set it to v
    cout << "After updating the " << i << "th bit to " << v << ", the number is: " << num << endl;
}   
void clearlastibits(int &num, int i) {
    num = num & (-1 << i); // Clear the last i bits by performing a bitwise AND with a mask
    cout << "After clearing the last " << i << " bits, the number is: " << num << endl;
}   
void countsetbits(int num) {
    int count = 0;
    while (num > 0) {
        count += num & 1; // Increment count if the least significant bit is set
        num >>= 1; // Right shift to check the next bit
    }
    cout << "Number of set bits: " << count << endl;
}
void fastexponentiation(int base, int exponent) {
    int result = 1;
    while (exponent > 0) {
        if (exponent & 1) { // If the least significant bit of the exponent is set
            result = result * base; // Multiply the result by the base
        }
        base = base * base; // Square the base
        exponent = exponent >> 1; // Right shift the exponent to check the next bit
    }
    cout << "Result of " << base << " raised to the power of " << exponent << " is: " << result << endl;
}
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

    int num = 10; // In binary: 1010
    onesComplement(num); // Output: One's complement of 10 is: -11 (in two's complement, ~1010 is 0101)
    bitwiseshift(num); // Output: Left shift of 10 is: 20, Right shift of 10 is: 5
    bitwiseoddoreven(num); // Output: 10 is even.
    getIthBit(num, 1); // Output: The 1th bit of 10 is: 1 (the second least significant bit)
    setIthBit(num, 0); // Output: After setting the 0th bit, the number is: 11 (in binary: 1011)
    clearIthBit(num, 1); // Output: After clearing the 1th bit, the number is: 9 (in binary: 1001)
    checkforpoweroftwo(num); // Output: 9 is not a power of two.
    updateithbit(num, 2, 1); // Output: After updating the 2th bit to 1, the number is: 13 (in binary: 1101)
    clearlastibits(num, 2); // Output: After clearing the last 2 bits, the number is: 12 (in binary: 1100)
    countsetbits(num); // Output: Number of set bits: 2
    fastexponentiation(2, 10); // Output: Result of 2 raised to the power of 10 is: 1024    
    return 0;
}   
