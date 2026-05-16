#include <iostream>
#include <cmath>
using namespace std;
void areaofsquare() {
    int n=1;
    cout<<"please enter avalue of n"<<endl;
    cin>>n;
    int result=1;
    for(int i=1;i<=n;i++){
        result=result*i;
    }
    cout<<"the factorial of anumber is"<<result<<endl;
}

void areaofcircle() {
    for(int i=1;i<=10;i++){
        cout<<"the multiplication table of 5 is "<<5*i<<endl;
    }
}

void simpleintrest(){
    int sum,temp,power,n,count;
    cout<<"please enter a value of n"<<endl;
    cin>>n;
    count=0;
    temp=n;
    while (temp>0){
        count++;
        temp=temp/10;
    }
    temp=n;
    sum=0;
    power=0;
    while (temp>0){
        int digit=temp%10;
        power=pow(digit,count);
        sum=sum+power;
        temp=temp/10;
    }
    if(sum==n){
        cout<<"the number is armstrong number"<<endl;
    }
    else{
        cout<<"the number is not armstrong number"<<endl;
    }
}    
#include <iostream>
using namespace std;
void totalcost() {
    int N;
    cout<<"please enter a value of N"<<endl;
    cin>>N;
    for (int i=2;i<=N;i++){
        int curr=i;
        bool isPrime=true;
        
        for (int j=2;j*j<=i;j++){
            if (curr%j==0){
                isPrime=false;
                break;
            }
        }
        if (isPrime){
            cout<<curr<<" ";
        }
    }
    cout<<endl;
                       
}


void fibonacciSeries() {
    int n;
    cout<<"please enter a number"<<endl;
    cin>>n;
    int first=0,sec=1;
    for(int i=2; i<n; i++){
        int third = first + sec;
        cout<<third<<" ";
        first=sec;
        sec= third;
    }
    cout<<"the fibonacci series is "<<first<<" "<<sec<<" ";
    cout<< "\n"; 
}

int main() {
    areaofsquare();
    areaofcircle();
    simpleintrest();
    totalcost();
    fibonacciSeries();
    return 0;
}