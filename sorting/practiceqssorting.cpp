#include <iostream>
using namespace std;


void print( char *arr, int n) {
    for (int i=0;i<n;i++){
        cout<<arr[i]<<",";
    }
}
void sortchar(char *arr ,int n){
    for(int i=1;i<n;i++){
        int curr=arr[i];
        int prev=i-1;
        //prev ke term me puri loop jo ki peeche hai ek number to wapis jakr usko theek karna padega usko aage
        while(prev>=0 &&arr[prev]<curr){//for descending order change > to < and for ascending order change < to >
            swap(arr[prev],arr[prev+1]);
            prev--;
        }
        arr[prev+1]=curr;//prev+1 because prev is already decremented
    }
    print(arr,n);
}
int main(){
    char ch[6]={'f','b','a','e','c','d'};
    int n=sizeof(ch)/sizeof(char);
    sortchar(ch,n);
}
