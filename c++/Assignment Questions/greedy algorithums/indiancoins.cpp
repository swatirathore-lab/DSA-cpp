#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int getminimumchange(vector<int> coins,int V){
    int ans=0;
    int n =coins.size();
    for(int i=n;i>=0 && V>=0;i--){
        if(V>=coins[i]){
            ans=ans+V/coins[i];
            V=V%coins[i];
        }
    }
    return ans;
}
int main(){
    vector<int> coins={1,2,5,10,20,50,100,200,500,2000};
    int V=590;
    cout<<getminimumchange(coins,V)<<endl;
}