#include <iostream>
#include <climits>
#include <algorithm>//for inbuilt sort
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
void bubblesort2(int *arr1,int n1) {
    for(int i=0;i<n1-1;i++){
        cout<<"outer loop"<<",";
        bool isswap= false;//telling their is zero swap
        for(int j=0;j<n1-i-1;j++){
            if(arr1[j]>arr1[j+1]){
                swap(arr1[j],arr1[j+1]);
                isswap=true;//if there iss wap than it will be true
                cout<<"inner loop"<<",";
            }
        }//please keep it out of inner loop earleir ypu krpt it in inner loop
        if(isswap==false){
            break;//if there is no swap than break the loop
        }
    }
    print(arr1,n1);

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
void insertionsort(int *arr ,int n){
    for(int i=1;i<n;i++){
        int curr=arr[i];
        int prev=i-1;
        //prev ke term me puri loop jo ki peeche hai ek number to wapis jakr usko theek karna padega usko aage
        while(prev>=0 &&arr[prev]>curr){
            swap(arr[prev],arr[prev+1]);
            prev--;
        }
        arr[prev+1]=curr;//prev+1 because prev is already decremented
    }
    print(arr,n);
}
void countingsort(int *arr,int n){
    int freq[10000];//freq array ka size array ki range ke equal so dynamic value consider it big
    int minvalue=INT_MAX, maxvalue=INT_MIN;//doubt why do weinitialize opposite
    for (int i=0;i<n;i++){
        minvalue=min(minvalue,arr[i]);
        maxvalue=max(maxvalue,arr[i]);

    }
    //1st step
    for(int i=0;i<n;i++){
        freq[arr[i]]++;
    }
    //2nd step range max-min
    for(int i=minvalue, j=0;i<=maxvalue;i++){
        while(freq[i]>0){
            arr[j++]=i;
            freq[i]--;
        }
    }
    print(arr,n);
}
//inbuilt sort
void inbuiltsort(int *arr,int n){
    sort(arr,arr+n);
    print(arr,n);
    sort(arr,arr+n,greater<int>());//for descending order
    print(arr,n);
}

int main(){
    int arr[5]={5,4,1,3,2};// more value than 5 like you wrote 6 earleir can produce garbage value
    int n=sizeof(arr)/sizeof(int);
    bubblesort(arr,n);
    //optimized bubble sort
    int arr1[9]={1,2,3,4,5,6,7,8,9};
    int n1=sizeof(arr1)/sizeof(int);
    bubblesort2(arr1,n1);
    //selection sort
    selectionsort(arr,n);
    //insertion sort
    insertionsort(arr,n);
    //countingsort
    countingsort(arr,n);
    //inbuilt sort
    inbuiltsort(arr,n);
}