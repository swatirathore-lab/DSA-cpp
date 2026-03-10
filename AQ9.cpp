
#include <iostream>
using namespace std;
//triangle patttern
void trianglePattern() {
    bool val = true;
    int n=5;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<val<<" ";
             val = !val;
        }
        cout<<"\n";
    }
}

// RhombusPattern
void rhombusPattern() {
    int n=5;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i-1;j++){
            cout<<" ";
        }
        for(int j=1;j<=n;j++){
            cout<<"*";
        }
        cout<<"\n";
    }
    
}
//PalindromicPatternwithNumbers
void palindromicPattern() {
    int n=5;
    for(int i=1;i<=n;i++){
        //spaces
        for(int j=1;j<=n-i;j++){
            cout<<" ";
        }
        //nums backward
        for(int j=i;j>=1;j--){
            cout<<j;
        }
        //nums forward
        for(int j=2;j<=i;j++){
            cout<<j;
        }
        cout<<"\n";
    }
}
int main() {
    trianglePattern();
    rhombusPattern();
    palindromicPattern();
    return 0;
}