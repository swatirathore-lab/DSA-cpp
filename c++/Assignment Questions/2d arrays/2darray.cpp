#include <iostream>
using namespace std;
int spiralmatrix(int arr[3][3], int m, int n) {
    int scol = 0, ecol = m - 1, srow = 0, erow = n - 1;
    while (srow <= erow && scol <= ecol) {
        //top
        for (int i = srow; i <= erow; i++) {
            cout << arr[i][scol] << " ";
        }
        scol++;
        //right
        for (int i = srow; i <= erow; i++) {
            cout << arr[i][ecol] << " ";
        }
        ecol--;
        //bottom
        if (srow <= erow) {
            for (int i = ecol; i >= scol; i--) {
                cout << arr[erow][i] << " ";
            }
            erow--;
        }
        //left
        if (scol <= ecol) {
            for (int i = erow; i >= srow; i--) {
                cout << arr[i][scol] << " ";
            }
            scol++;
        }
    }
    return 0;

}
int diagonalsum(int arr[3][3], int m, int n) {
    int sum = 0;
    for (int i = 0; i < m; i++) {
        sum += arr[i][i]; // primary diagonal
        if (i != n - 1 - i) { // avoid double counting the center element in odd-sized matrices
            sum += arr[i][n - 1 - i]; // secondary diagonal
        }
    }
    cout << sum << endl;
    return sum;
}
//o(n) time complexity and o(1) space complexity
int diagonalsum2(int arr[3][3], int m, int n) {
    int sum = 0;
    for (int i = 0; i < m; i++) {
        sum += arr[i][i]; // primary diagonal
        if(i!=n-i-1){
            sum += arr[i][n - 1 - i]; // secondary diagonal 
        }
    }
    cout << sum << endl;
    return sum;
}
bool searcheleinsortedarray(int arr[3][3], int m, int n, int key) {
    int i=0,j=n-1;
    while(i<m && j>=0){
        if(arr[i][j]==key){
            return true;
        }
        else if(arr[i][j]>key){
            j--;
        }
        else{
            i++;
        }
    }
    return false;   
}
void printmatrixpointer(int (*arr)[3], int m, int n){//or int arr[][3],int n,int m) 
    cout<<"0th row ptr"<<arr<<endl;
    cout<<"1st row ptr"<<arr+1<<endl;
    cout<<"2nd row ptr"<<arr+2<<endl;
    cout<<"0th row value"<<*arr<<endl;
    cout<<"1st row value"<<*(arr+1)<<endl;
    cout<<"2nd row value"<<*(arr+2)<<endl;
    cout<<"Element at (2,2):"<<*(*(arr+2)+2)<<endl;
}

int main() {
    //intro to 2d arrays
    int students[3][3] = {
        {85, 90, 78},
        {92, 88, 95},
        {80, 85, 82}
    };
    //input and output of array
    int arr[3][3];
    cout << "Enter integers to fill the 2D array:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> arr[i][j];
        }
    }

    cout << "The elements of the 2D array are:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    //spiral matrix
    cout << "Spiral order of the 2D array is:" << endl;
    spiralmatrix(arr, 3, 3);
    //diagonal sum
    cout << "Diagonal sum of the 2D array is:" << endl;
    diagonalsum(arr,3,3);
    //search in sorted matrix
    cout << "Enter the element to search in the sorted 2D array:" << endl;
    int key;    
    cin >> key;
    searcheleinsortedarray(arr,3,3,key)?cout<<"Element found":cout<<"Element not found";
    //matrixpointer
    cout <<arr<<endl;
    cout<<arr+1<<endl;
    cout<<arr<<"="<<arr[0][0]<<endl;
    cout<<arr+1<<"="<<arr[0][1]<<endl;
    cout<<arr+2<<"="<<arr[1][0]<<endl;
    //matrixpointer in function

    return 0;
}