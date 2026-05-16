#include <iostream>
using namespace std;  
int question1(int arr[3][3]) {
    int count=0;
    for (int i=0;i<3;i++) {
        for (int j=0;j<3;j++) {
            if (arr[i][j]==7) {
                count++;
                cout<<"number of 7's are "<<count<<endl;
            }
        }
    }
    return count;
}  
int question2(int arr[3][3]){
    int sum=0;
    for(int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            sum+=arr[i][j];
        }
    }

    cout<<"sum of all elements is "<<sum<<endl;
    return sum;
}
int question3(int arr[3][3]){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            arr[i][j]=arr[j][i];
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main() {
    int arr[3][3] ={
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    int arr1[3][3] ={
        {1,2,3},
        {4,5,6}
    };
    question1(arr);
    question2(arr);
    question3(arr1);
    return 0;
}