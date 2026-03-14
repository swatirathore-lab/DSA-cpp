#include <iostream>
using namespace std;
int printArray(int arr[], int n) {
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
//find largest in array
int findLargest(int arr[], int n) {
    int largest = arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>largest){
            largest = arr[i];
        }
    }
    cout<<"largest element in array is "<<largest<<endl;
}
//linear search in array
int linearSearch(int *arr, int n, int key) {
    for(int i=0; i<n; i++){
        if(arr[i] == key){
            return i;
        }
    }
    return -1;
    
    
}

void reverseinarrayusingspace(int arr[], int n) {
    int copyarr[n];
    for(int i=0; i<n; i++){
        copyarr[i] = arr[n-i-1];
    }
    cout << "reversed array: ";
    for(int i=0; i<n; i++){
        cout << copyarr[i] << " ";
    }
    cout << endl;
    
    
}

int main() {
    int n, key;
    cout<<"enter the length of array"<<endl;
    cin>>n;
    int start=0, end=n-1,temp;
    int arr[n];
    cout<<"enter elements of array"<<endl;
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }
    printArray(arr, n);
    findLargest(arr, n);
    cout<<"enter the element to search"<<endl;
    cin>>key;

    int index= linearSearch(arr,n,key);
    if(index==-1){
        cout<<"element not found in array"<<endl;
    }
    else{
        cout<<"element found at index "<<index<<endl;
    }
    reverseinarrayusingspace(arr, n);
    
    return 0;
}