#include <iostream>
using namespace std;
int palindrome(int n)
{
    int rev=0, rem, temp;
    temp=n;
    while(temp!=0)
    {
        rem=temp%10;
        rev=rev*10+rem;// the core logic i forget
        temp=temp/10;
    }
    return rev;
}
int sumofdigits(int p)
{ int sum=0, rem, temp;
temp=p;
while(temp!=0)
{
    rem=temp%10;
    sum=sum+rem;
    temp=temp/10;
}
return sum;
}
int function(int a, int b)
{
    return (a^2+b^2+2*a*b);
}
int largestof3(int x,int y,int z)
{
    if(x>y && x>z)
    {
        return x;
    }
    else if (y>x && y>z)
    {
        return y;
    }
    else
    {
        return z;
    }
}
char getnextchar( char ch)
{
    if (ch=='z')
    {
        return 'a';
    }
    else
    {
        return ch+1;
    }
}
int main()
{ 
    int n,p,a,b,x,y,z;
    char ch;
    cout<<"Enter a value of n: ";
    cin>>n;
    cout<<"Enter a value of p: ";
    cin>>p;
    cout<<"Enter values of a and b: ";
    cin>>a>>b;
    cout<<"Enter values of x, y, and z: ";
    cin>>x>>y>>z;
    cout<<"Enter a character:";
    cin>>ch;
    if(n==palindrome(n))// if the number is equal to its reverse then it is a palindrome number
    {
        cout<<n<<" is a palindrome number.";
    }
    else
    {
        cout<<n<<" is not a palindrome number.";
    }
    cout<<"The sum of digit of "<<p<< "is"<<sumofdigits(p);
    cout<<"The value of the function is: "<<function(a,b);
    cout<<"The gretaest number is"<<largestof3(x,y,z);
    cout<<"The next character is: "<<getnextchar(ch);
    cout<<endl;
    return 0;
}

