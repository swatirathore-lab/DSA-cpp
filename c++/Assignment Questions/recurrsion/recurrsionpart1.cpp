#include <iostream>
#include <vector>
using namespace std;

// Recursion: a function calling itself.

int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}
//numbers in decreasing order
void print (int n){
    if(n==0){
        return ;
    }
    cout<<n<<" ";
    print(n-1);
}
//sum of n natural number
int sum(int n) {
    if (n==1)
    {
        return 1;
    }
   return  n + sum(n-1);
}    
//print nth fibonacci number
int fibonacci(int n){
    if(n==0||n==1){
        return n;
    }
    
    return fibonacci(n-1)+fibonacci(n-2);
}
//check if array is sorted
bool issorted( int arr[],int n,int i){
    if(i==n-1){
        return true;
    }
    if(arr[i]>arr[i+1]){
        return false;
    }
    return issorted(arr,n,i+1);
}
//first occurence
int firstoccur(vector<int> arr,int i,int target){//because vector so no need to pass the size
    if(i==arr.size()){
        return -1;
    }
    if(arr[i]==target){
        return i;
    }
    return firstoccur(arr,i+1,target);
    
}
//last occurence
int lastoccur(vector<int>arr, int target,int i) {
    if(i== arr.size()){
        return -1;
    }
    int idxfound = lastoccur(arr,target,i+1);
    if(idxfound==-1 && arr[i]== target){
        return i;
    }
    return idxfound;
}
//print x to the power n
int pow(int x,int n){
    if(n==0){
        return 1;
    }
    int halfpower=pow(x,n/2);
    int halfpowersquare =halfpower*halfpower;
    if(n%2!=0){
        //odd
        return x*halfpowersquare;
    }
    return halfpowersquare;
}



int main() {
    int num = 5;
    cout << "Factorial of " << num << " is " << factorial(num) << endl;
    int num1 =87;
    cout<<"print numbers :";
    print(num1);
    cout<<endl;
    int n=5;
    cout<<"sum of n number is "<<sum(n)<<endl;
    cout<<"nth fibonacci is "<<fibonacci(n)<<endl;
    int arr[5]={1,2,3,4,5};
    int arr1[5]={1,4,5,6,2};
    cout<<"arr is sorted or not "<< issorted(arr,5,0)<<endl;
    cout<<"arr1 is sorted or not "<< issorted(arr1,5,0)<<endl;
    vector<int> arr3={1,2,3,3,3,4};
    cout<<firstoccur(arr3,0,3)<<endl;
    cout<<lastoccur(arr3,4,0)<<endl;
    cout<<pow(5,3)<<endl;
    return 0;
}
