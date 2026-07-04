#include <iostream>
#include <stack>
#include <vector>
using namespace std;
void pushatbottom(stack<int> &s, int data) {
    if(s.empty()) {
        s.push(data);//push at top is equal to push at bottom when stack is empty
        return;
    }
    int topval = s.top();
    s.pop();
    pushatbottom(s, data);
    s.push(topval);
}
string reversestring(string str){//O(n)//o(n)
    stack<char> s;
    for(int i=0; i<str.length(); i++) {
        char ch = str[i];
        s.push(ch);
    }
    string ans = "";
    while(!s.empty()) {
        char ch = s.top();
        ans.push_back(ch);
        s.pop();
    }
    return ans;
}
void reverseStack(stack<int> &s) {
    if(s.empty()) {
        return;
    }
    int topval = s.top();
    s.pop();
    reverseStack(s);
    pushatbottom(s, topval);
}   
void stockspanproblem(vector<int> &stock, vector<int> &span) {
    stack<int> s;
    s.push(0);
    span[0] = 1;
    for(int i=1; i<stock.size(); i++) {
        int currprice = stock[i];
        while(!s.empty() && currprice > stock[s.top()]) {
            s.pop();
        }
        if(s.empty()) {
            span[i] = i+1;
        } else {
            int prevhigh = s.top();
            span[i] = i - prevhigh;
        }
        s.push(i);
    }
}
int main() {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    pushatbottom(s, 0);
    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    string str = "abcde";
    cout << "Original string: " << str << endl;
    string reversedStr = reversestring(str);
    cout << "Reversed string: " << reversedStr << endl;
    stack<int> s1;
    s1.push(1); 
    s1.push(2);
    s1.push(3);
    cout << "Original stack: ";
    while(!s1.empty()) {
        cout << s1.top() << " ";
        s1.pop();
    }
    cout << endl;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    reverseStack(s1);
    cout << "Reversed stack: "; 
    while(!s1.empty()) {
        cout << s1.top() << " ";
        s1.pop();
    }
    cout << endl;
    //stock span problem
    vector<int> stock = {100, 80, 60, 70, 60, 75, 85};
    vector<int> span = { 0, 0, 0, 0, 0, 0, 0 };
    stockspanproblem(stock, span);
    cout << "Stock span: ";
    for(int i=0; i<span.size(); i++) {
        cout << span[i] << " ";
    }
    cout << endl;
    return 0;
}