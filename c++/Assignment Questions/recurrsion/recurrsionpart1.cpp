#include <iostream>
using namespace std;

// Recursion: a function calling itself.

int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}
//numbers in decreasing order
int print (int n){
    if(n==0){
        return ;
    }
    cout<<n<<"";
    print(n-1);
}

int main() {
    int num = 5;
    cout << "Factorial of " << num << " is " << factorial(num) << endl;
    int num1 =87;
    cout<<"print numbers" << print(num1)<<endl;
    return 0;
}
