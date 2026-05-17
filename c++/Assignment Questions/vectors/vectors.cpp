

#include <iostream>
#include <vector>   
using namespace std;

/// @brief Function to demonstrate dynamic array allocation
void function() {
    //int arr[100]={1,2,3,4,5,}; compile time par size pta hai to phir static memory
    int size;
    cin>>size;
    int x=1;
    int *arr = new int[size]; // dynamic memory allocation
    for(int i=0;i<size;i++){
        arr[i]=x;
        cout<<arr[i]<<" ";
        x++;
    }
    cout <<endl;
    delete[] arr; // deallocate memory
}
void twoDdynamicarrays() {
    int rows,cols;
    cout<<"enter rows";
    cin>>rows;
    cout<<"enter cols";
    cin>>cols;
    int **arr = new int*[rows]; // dynamic memory allocation for rows
    for(int i=0;i<rows;i++){
        arr[i] = new int[cols]; // dynamic memory allocation for columns
    }
    int x=1;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            arr[i][j]=x;
            cout<<arr[i][j]<<" ";
            x++;
        }
        cout<<endl;
    }
    // deallocate memory
    for(int i=0;i<rows;i++){
        delete[] arr[i]; // deallocate memory for columns
    }
    delete[] arr; // deallocate memory for rows
}
int main() {
    function();
    twoDdynamicarrays();
    return 0;

}

