// #include <iostream>
// using namespace std;
// int main() {
//     int n;
//     cout<<"enter length of array"<<endl;
//     cin>>n;
//     int arr[n];
//     cout<<"enter elements of array"<<endl;
//     for (int i=0;i<n;i++){
//         cin>> arr[i];
//     }
//     for(int i=0;i<n;i++){
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl;
//     return 0;
// }
// find largest in array
#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter length of array"<<endl;
    cin>>n;
    int arr[n];
    cout<<"enter elements of array"<<endl;
    for (int i=0;i<n;i++){
        cin>> arr[i];
    }
    int largest = arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>largest){
            largest = arr[i];
        }
    }
    cout<<"largest element in array is "<<largest<<endl;
    return 0;
}
