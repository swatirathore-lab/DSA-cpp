#include <iostream>
#include <vector>
using namespace std;
//merge sort
void merge(int arr[], int si,int mid,int ei){//time complexity O(n) and space complexity O(n)
    vector<int> temp;//temporary array
    int i=si;//iterator for left half
    int j=mid+1;//iterator for right half
    int k=0;//iterator for temp array

    while(i<=mid && j<=ei){
        if(arr[i]<arr[j]){
            temp.push_back(arr[i++]);
        }
        else{
            temp.push_back(arr[j++]);
        }
    }
    //if left half is remaining
    while(i<=mid){
        temp.push_back(arr[i++]);
    }
    //if right half is remaining
    while(j<=ei){
        temp.push_back(arr[j++]);
    }
    //copy temp array to original array,loop original arrar par chll raha
    for(int i=si;i<=ei;i++){
        arr[i]=temp[i-si];
    }
}
void mergesort(int arr[], int si,int ei){//time complexity O(logn) 
    //base case
    if(si>=ei){
        return;
    }
    int mid =(si +ei)/2;//si+(ei-si)/2 kyu nahi likha kyuki overflow ka chance nahi hai
    mergesort(arr,si,mid);//left half
    mergesort(arr,mid+1,ei);//right half
    merge(arr,si,mid,ei);//conquer step
}
void printarr(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
//quick sort
int partition(int arr[], int si,int ei){
    int pivot=arr[ei];//choosing last element as pivot
    int i=si-1;//index of smaller element
    for(int j=si;j<ei;j++){
        if(arr[j]<pivot){
            i++;//increment index of smaller element
            swap(arr[i],arr[j]);
        }
    }
    i++;
    swap(arr[i],arr[ei]);//placing pivot in correct position    
    return i;//returning index of smaller element
}
void quicksort(int arr[], int si,int ei){
    //base case
    if(si>=ei){
        return;
    }
    int pivotindex=partition(arr,si,ei);//partitioning index
    quicksort(arr,si,pivotindex-1);//left half
    quicksort(arr,pivotindex+1,ei);//right half
}

int main() {
    int arr[6] ={6,3,7,5,2,4};
    int n=6;
    mergesort(arr,0,n-1);
    printarr(arr, n);
    quicksort(arr,0,n-1);
    printarr(arr, n);
    return 0;
}