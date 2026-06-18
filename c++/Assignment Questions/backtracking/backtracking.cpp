#include <iostream>
#include <string>
#include <vector>
using namespace std;
void printArr(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;


}
//backtracking on arrays
void changeArr(int arr[],int n,int i){
    if(i==n){
        printArr(arr,n);
        return;
    }
    arr[i]=i+1;
    changeArr(arr,n,i+1);
    arr[i]-= 2;//backtrack
}
//Find subsets
void substring(string str,string subset){
    if(str.size()==0){
        cout<<subset<<"\n";
        return;
    }
    int n=str.size();
    char ch=str[0];
    substring(str.substr(1,n-1),subset + ch);//yes choice
    substring(str.substr(1,n-1),subset);//no choice
}
//find permutations
void permutations(string str,string ans) {
    if(str.size() == 0){
        cout << ans << "\n";   // ✅ print when no characters left to permute
        return;
    }
    int n=str.size();
    for(int i=0;i<str.size();i++){
        char ch=str[i];
        //"abcdefgh",i= 2 =>"ab"+"defgh"=>
        string newstr = str.substr(0,i)+str.substr(i+1,n-i-1);//if you have to skip i element
        permutations(newstr,ans+ch);//to add the ith element into new string
    }

}
//N queens
void printBoard(vector<vector<char>>board){
    int n=board.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j];
        }
        cout<<endl;
    }
    cout<<"--------------------"<<"\n";
}
bool issafe(vector<vector<char>> board,int row,int col){
    int n=board.size();
    for(int j=0;j<col;j++){
        if(board[row][j]=='Q'){
            return false;
        }
    }
   
    for(int i=0;i<row;i++){
        if(board[i][col]=='Q'){
            return false;
        }
    }
    for(int i=row,j=col;i>=0 && j>=0;i--,j--){
        if(board[i][j]=='Q'){
            return false;
        }
    }
    for(int i=row,j=col;i>=0 && j<n;i--,j++){
        if(board[i][j]=='Q'){
            return false;
        }
    }
    return true;

}
int nQueens(vector<vector<char>> board,int row){//add void->int for count
    int n=board.size();
    if(row==n){
        printBoard(board);
        return 1;
    }
    int count=0;//for count
    for(int j=0;j<n;j++){
        if(issafe(board,row,j)){
            board[row][j]='Q';
            count += nQueens(board,row+1);//for count
            board[row][j]='.';
        }
    }
    return count;//for count
}




int main() {
    //backtracking on array
    int arr[5]={0};
    int n=5;
    changeArr(arr,n,0);
    printArr(arr,n);
    //find subsets
    string str="abc";
    substring(str,"");
    //find permutations
    string str1="abc";
    string ans="";
    permutations(str1,ans);
    //N queens
    vector<vector<char>>board;
    int n4=4;
    for(int i=0;i<n4;i++){
        vector<char> newRow;
        for(int j=0;j<n4;j++){
            newRow.push_back('.');
        }
        board.push_back(newRow);
    }
    int count=nQueens(board,0);//for count
    cout<<count<<endl;//for count
    return 0;
}