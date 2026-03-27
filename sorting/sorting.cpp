#include <iostream>
#include <climits>
using namespace std;
//bubble sort
void print( int *arr, int n) {
    for (int i=0;i<n;i++){
        cout<<arr[i]<<",";
    }
}
void bubblesort(int *arr,int n) {//or arr[]or*
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
    print(arr,n);

}
//optimized bubble sort//so the loop will run only one time when we will do this
void bubblesort2(int *arr,int n) {
    for(int i=0;i<n-1;i++){
        cout<<"outer loop"<<",";
        bool isswap= false;//telling their is zero swap
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                isswap=true;//if there iss wap than it will be true
                cout<<"inner loop"<<",";
            }
            if(!isswap){
                return;//array is already sorted of swap is false only did not turned into true
            }
        }
    }
    print(arr,n);

}
void selectionsort(int *arr,int n){
    for(int i=0;i<n;i++){
        int minindex=i;
        //loop to find min
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minindex]){//remember koi chota element dhudna aage ke loop me
                minindex=j;
            }
        }
        swap(arr[i],arr[minindex]);//i ke sath minindex swap
    }
    print(arr,n);
}
int main(){
    int arr[6]={5,4,1,3,2};
    int n=sizeof(arr)/sizeof(int);
    bubblesort(arr,n);
    //optimized bubble sort
    int arr1[11]={1,2,3,4,5,6,7,8,9};
    int n1=sizeof(arr1)/sizeof(int);
    bubblesort2(arr1,n1);
    //selection sort
    selectionsort(arr,n);
}