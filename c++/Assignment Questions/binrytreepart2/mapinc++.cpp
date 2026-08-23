#include <iostream>
#include <map>
#include <string>
using namespace std;
int main(){
    map<int,string> m;
    m[101]="rahul";
    m[110]="neha";
    m[131]="rahul";
    for(auto it :m){
        cout<<"double="<<it.first*2<<endl;
    }
    return 0;
}