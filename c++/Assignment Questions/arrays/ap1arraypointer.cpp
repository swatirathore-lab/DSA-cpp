#include <iostream>
using namespace std;
int main() {
    int a=10;
    int *ptr=&a;
    int *ptr3= ptr+3;
    int arr[20]={1,2,3,4,5,6};
    int *ptr1 =arr;//1 ko point kar rha
    int *ptr2=ptr1 +3;//4 ko point karega
    cout <<ptr1<<"\n";
    cout <<ptr2<<"\n";
    cout <<*ptr1<<"\n";
    cout <<*ptr2<<"\n";
    //comparison
    cout<<(ptr2<ptr1)<<"\n";
    cout<<(ptr1<ptr2)<<"\n";
    //upar array se pehle wali cheezein ke liye
    cout <<ptr<<"\n";
    cout <<ptr3<<"\n";
    cout<<ptr3-ptr<<"\n";
    cout <<ptr<<"\n";
    ptr++;
    cout <<ptr<<"\n";
    ptr+3;
    cout <<ptr<<"\n";
}