

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
void vectorDemo() {
    vector<int> v(10, -1); // create a vector of 10 integers, all initialized to -1
    cout<<v.size()<<"\n"; // print the size of the vector
    cout << "Vector elements: ";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " "; // access elements using index
    }
    cout << endl;
}
void vectorimplemenatationinmemory() {
    vector<int> v={1,2,3,4,};
    cout<<"size of vector is "<<v.size()<<endl;// size of vector is 4
    cout<<"capacity of vector is "<<v.capacity()<<endl;// capacity of vector is 4
    v.push_back(5);
    cout<<"size of vector is "<<v.size()<<endl;// size of vector is 5
    cout<<"capacity of vector is "<<v.capacity()<<endl;// capacity of vector is 8
}
vector<int> pairSum(vector<int> arr,int target){
    int st=0, end=arr.size()-1;
    int currSum=0;
    while(st<end){
        currSum=arr[st]+arr[end];
        if(currSum==target){
            return {st,end};
        }
        else if(currSum>target){
            end--;
        }
        else{
            st++;
        }
    }
}
void twoDvector(){
    vector<vector<int>> matrix={{1,2,3},{4,5,6},{7,8,9}}; // create a 2D vector of 3 rows and 4 columns, all initialized to -1
    cout<<"2D Vector elements: "<<endl;
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[i].size();j++){
            cout<<matrix[i][j]<<" "; // access elements using index
        }
        cout<<endl;
    }
}
int main() {
    function();
    twoDdynamicarrays();
    vectorDemo();
    vectorimplemenatationinmemory();
    pairSum({1,2,3,4,5}, 5);
    return 0;
}
    



