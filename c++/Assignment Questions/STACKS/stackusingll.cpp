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
    return 0;
}