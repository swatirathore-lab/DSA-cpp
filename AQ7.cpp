#include <iostream>
#include <cmath>
using namespace std;
void checknumber() {
    int n ;
    cout << "input a number" << endl;
    cin >> n ;
    if (n == 0) {
        cout << "the number is zero" << endl;
    } else if (n > 0) {
        cout << "the number is positive" << endl;
    } else {
        cout << "the number is negative" << endl;
    }

}

void checkleapyear() {
    int year;
    cout << "enter a year " << endl;
    cin >> year ;
    if (year % 4  == 0 &&( year % 400 == 0 || year % 100 != 0)) {
        cout << "the year is leap year" << endl ;
    } else {
        cout << "the year is not a leap year" << endl ;
    }       
}


void checkarmstrongnumber() {
    int a,count=0,num,i,sum,digit;
    cout << " enter a number " << endl ;
    cin >> a ;
    num = a;
    while ( num !=0 ) 
    {
        num =num %10 ;
        count++;
        num =num / 10;
    }
    while (sum <= a ) 
    {
        digit = num %10 ;
        sum = sum + pow(digit,count);
        num =num /10;
    }
    if (sum == a) {
        cout <<"the no. is armstrong number"<< endl;
    } else {
        cout <<"the no. is not armstrong number"<< endl;    
    }
    
}
int main() {
    checknumber();
    checkleapyear();
    checkarmstrongnumber();
    return 0;
}
