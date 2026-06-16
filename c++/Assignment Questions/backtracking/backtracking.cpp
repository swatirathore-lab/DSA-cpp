#include <iostream>
#include <string>
#include <vector>
using namespace std;
void printArr(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;


}
//backtracking on arrays
void changeArr(int arr[],int n,int i){
    if(i==n){
        printArr(arr,n);
        return;
    }
    arr[i]=i+1;
    changeArr(arr,n,i+1);
    arr[i]-= 2;//backtrack
}
//Find subsets
void substring(string str,string subset){
    if(str.size()==0){
        cout<<subset<<"\n";
        return;
    }
    int n=str.size();
    char ch=str[0];
    substring(str.substr(1,n-1),subset + ch);//yes choice
    substring(str.substr(1,n-1),subset);//no choice
}
//find permutations
void permutations(string str,string ans) {
    if(str.size() == 0){
        cout << ans << "\n";   // ✅ print when no characters left to permute
        return;
    }
    int n=str.size();
    for(int i=0;i<str.size();i++){
        char ch=str[i];
        //"abcdefgh",i= 2 =>"ab"+"defgh"=>
        string newstr = str.substr(0,i)+str.substr(i+1,n-i-1);//if you have to skip i element
        permutations(newstr,ans+ch);//to add the ith element into new string
    }

}

int main() {
    int arr[5]={0};
    int n=5;
    changeArr(arr,n,0);
    printArr(arr,n);
    string str="abc";
    substring(str,"");
    string str1="abc";
    string ans="";
    permutations(str1,ans);
    return 0;

}