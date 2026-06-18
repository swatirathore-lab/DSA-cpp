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
//Grid Ways
int gridways(int r,int c,int n,int m,string ans){
    if(r==n-1 && c==n-1){//Bc
        cout<<ans<<"\n";
        return 1;
    }
    if(r>=n || c>=n){
        return 0;
    }
    //right
    int v1=gridways(r,c+1,n,m,ans+"R");
    //down
    int v2=gridways(r+1,c,n,m,ans+"D");
    return v1+v2;
}
//sudoku solver
void printsudoku(int sudoku[9][9]){
    for(int i=0;i<=8;i++){
        for(int j=0;j<=8;j++){
            cout<<sudoku[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
}
bool issafee(int sudoku[9][9],int dig,int row,int col){
    //vertical
    for(int i=0;i<=8;i++){
        if(sudoku[i][col]==dig){
            return false;
        }
    }
    //horizontal
    for (int j=0;j<=8;j++){
        if(sudoku[row][j]==dig){
            return false;
        }
    }
    //grid 
    int strrow=(row/3)*3;
    int strcol=(col/3)*3;
    for(int i=strrow;i<=strrow+2;i++){
        for(int j=strcol;j<=strcol+2;j++){
            if(sudoku[i][j]==dig){
                return false;
            }
        }
    }
    
    return true;
}
bool sudokusolver(int sudoku[9][9],int row,int col){
    if(row==9){
        printsudoku(sudoku);
        return true;
    }
    int newrow=row;
    int newcol=col+1;
    if(newcol==9){
        newrow=row+1;
        newcol=0;
    }
    if(sudoku[row][col]!=0){
        return sudokusolver(sudoku,newrow,newcol);
    }
    for(int dig=1;dig<=9;dig++){
        if(issafee(sudoku,dig,row,col)){
            sudoku[row][col]=dig;
            if(sudokusolver(sudoku,newrow,newcol)){//backtrack karke true dega agar value sahi hai
                return true;
            }
            sudoku[row][col]=0;
        }
    }
    
    return false;//pura complete ho gya still false value
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
    int n5=3;
    int m5=3;
    string ans1="";
    cout<<gridways(0,0,n5,m5,ans1);
    //sudoku solver
    int sudoku[9][9] = {{0, 0, 0, 0, 0, 8, 0, 0, 5},
                     {3, 0, 6, 9, 0, 0, 8, 0, 0},
                     {0, 0, 1, 5, 0, 0, 0, 0, 9},
                     {5, 1, 0, 7, 0, 3, 4, 0, 6},
                     {0, 0, 4, 0, 0, 0, 1, 0, 0},
                     {0, 0, 0, 1, 0, 4, 2, 0, 0},
                     {0, 6, 0, 4, 1, 0, 0, 8, 0},
                     {4, 2, 5, 0, 0, 0, 0, 0, 1},
                     {1, 0, 8, 0, 0, 0, 0, 0, 0}};
    bool solved = sudokusolver(sudoku,0,0);
    cout << "Solved: " << solved << endl;               
    return 0;
}