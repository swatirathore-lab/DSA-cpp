#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <stack>

using namespace std;
//create stack using linked list
template<class T>
class node {
    public:
    T data;
    node<T>* next;
    node(T value) {
        data = value;
        next = nullptr;
    }
};
template<class T>
class Stack {
    node<T>* topNode;
public:
    Stack() {
        topNode = nullptr;
    }
    void push(T value) {
        node<T>* newNode = new node<T>(value);
        newNode->next = topNode;
        topNode = newNode;
    }
    void pop() {
        if (topNode == nullptr) {
            cout << "Stack is empty" << endl;
            return;
        }
        node<T>* temp = topNode;
        topNode = topNode->next;
        delete temp;
    }
    T top() {
        if (topNode == nullptr) {
            cout << "Stack is empty" << endl;
            return T();
        }
        return topNode->data;
    }
    bool isEmpty() {
        return topNode == nullptr;
    }
};    
void nextgreater(vector<int>& arr, vector<int>& ans){
    stack<int> s;
    int idx=arr.size()-1;
    ans[idx]=-1;
    s.push(arr[idx]);
    for(int i=idx-1;i>=0;i--){
        while(!s.empty() && s.top()<=arr[i]){
            s.pop();
        }
        if(s.empty()){
            ans[i]=-1;
        }
        else{
            ans[i]=s.top();
        }
        s.push(arr[i]);

    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}
//Valid Parenthesis

// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:
// 1. Open brackets must be closed by the same type of brackets.
// 2. Open brackets must be closed in the correct order.
// 3. Every close bracket has a corresponding open bracket of the same type.

// Examples:
// [(])  → invalid
// [()]  → valid
void validparenthesis(string s){
    stack<char> st;
    for(int i=0;i<s.length();i++){
        if(s[i]=='(' || s[i]=='{' || s[i]=='['){
            st.push(s[i]);
        }
        else{
            if(st.empty()){
                cout<<"Invalid"<<endl;
                return;
            }
            char top=st.top();
            if((s[i]==')' && top=='(') || (s[i]=='}' && top=='{') || (s[i]==']' && top=='[')){
                st.pop();
            }
            else{
                cout<<"Invalid"<<endl;
                return;
            }
        }
    }
    if(st.empty()){
        cout<<"Valid"<<endl;
    }
    else{
        cout<<"Invalid"<<endl;
    }
}   


int main() {
    Stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    while(!s.isEmpty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    vector<int> arr ={6,8,0,1,3};
    vector<int> ans ={0,0,0,0,0};
    nextgreater(arr, ans);
    validparenthesis("[(])");
    validparenthesis("[()]");
    return 0;
}