#include <iostream>
using namespace std;
int binarysearch(int arr[], int n,int ele){
    int first,last,mid;
    first=0;
    last=n-1;
    for(int i=0;i<n;i++){
        mid=(first+last)/2;
        if(arr[mid]==ele){
            return mid;
        }
        else if(arr[mid] <ele){
            first=mid+1; 
        }
        else {
            last=mid-1;
        }
    }
    return -1;
}
int main(){
    int n,ele;
    cout<<"enter the length of array"<<endl;
    cin>>n;
    
    int arr[n];
    cout<<"enter the elements of array"<<endl;
    for(int i=0;i<n;i++){
           cin>>arr[i];
    }
    cout<<"eneter elements to search"<<endl;
    cin>>ele;
    int index=binarysearch( arr,n,ele);
    if(index==-1) {
        cout <<"element not found"<<endl;
    } else {
        cout<<"elemnt found at index"<<index<<endl;
    }
    return 0;
}
// //### How Binary Search works 💡
// ```
// array = [2, 4, 6, 8, 10]  search = 8

// first=0, last=4, mid=2 → arr[2]=6 < 8 → search right
// first=3, last=4, mid=3 → arr[3]=8 == 8 → found at index 3! ✅