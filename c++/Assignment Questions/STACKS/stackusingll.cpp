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
void nextgreater(vector<int>& arr, vector<int>& ans){//o(n) time and o(n) space
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
void validparenthesis(string s){//o(n) time and o(n) space
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
// Duplicate Parentheses

// Given a balanced expression that can contain opening and closing parenthesis, check if it contains any duplicate parenthesis or not.

// Input:  ((x+y))+z
// Output: true
// Explanation: Duplicate () found in subexpression ((x+y))

// Input:  (x+y)
// Output: false
// Explanation: No duplicate () is found

// Input:  ((x+y)+((z)))
// Output: true
// Explanation: Duplicate () found in subexpression ((z))
bool duplicateparenthesis(string s){//o(n) time and o(n) space
    stack<char> st;
    for(int i=0;i<s.length();i++){
        int ch=s[i];
        if(ch!=')'){
            st.push(ch);
        }else{
            if(st.top()=='('){
                cout<<"Duplicate Parenthesis Found"<<endl;
                return true;
            }
            while(st.top()!='('){
                st.pop();
            }
            st.pop();
        }

    }
    return false;
}
void print(vector<int> v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
int maxgreaterareahistogram(vector<int> height){
    int n=height.size();
    vector<int> nsl(n);
    vector<int> nsr(n);
    stack<int> s;
    //next smaller left
    nsl[0]=-1;
    s.push(0);
    for(int i=0;i<height.size();i++){
        int current=height[i];
        while(!s.empty() && height[s.top()]>=current){
            s.pop();
        }
        if(s.empty()){
            nsl[i]=-1;
        }else{
            nsl[i]=s.top();
        }
        s.push(i);//push current index to stack because we need to find next smaller left for next elements
    }
    print(nsl);
    while(!s.empty()){
        s.pop();
    }//wapas se stack ko empty kar diya kyuki we need to find next smaller right
    //next smaller right
    
    nsr[n-1]=n;
    s.push(n-1);
    for(int i=n-2;i>=0;i--){
        int current=height[i];
        while(!s.empty() && height[s.top()]>=current){
            s.pop();
        }
        if(s.empty()){
            nsr[i]=n;
        }else{
            nsr[i]=s.top();
        }
        s.push(i);
    }

    int maxarea=0;
    for(int i=0;i<n;i++){
        int ht=height[i];
        int width=nsr[i]-nsl[i]-1;
        int area=ht*width;
        maxarea=max(maxarea,area);
    }
    cout<<"Max Area in Histogram: "<<maxarea<<endl;
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
    duplicateparenthesis("((x+y))+z");  
    duplicateparenthesis("(x+y)");
    maxgreaterareahistogram({2,1,5,6,2,3});
    return 0;
}