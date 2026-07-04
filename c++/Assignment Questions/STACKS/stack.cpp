#include <iostream>
using namespace std;
//stacks using vectors
#include <vector>
//stack using vector and class template
template <class T>
class Stack {
// stacks using vectors
//     vector <int> vec;
// public:
//     void push(int value) {//O(1)
//         vec.push_back(value);
//     }
//     void pop() {
//         if (isEmpty()) {
//             cout << "Stack is empty" << endl;
//             return;
//         }   
//         vec.pop_back();
//     }
//     int top() {
//         if (isEmpty()) {
//             cout << "Stack is empty" << endl;
//             return -1;
//         }
//         int lastidx = vec.size() - 1;
//         return vec[lastidx];
//     }
//     bool isEmpty() {
//         return vec.empty();
//     }
//stack using vector and class template
vector <T> vec;
public:
    void push(T value) {//O(1)
        vec.push_back(value);
    }
    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }   
        vec.pop_back();
    }
    T top() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        int lastidx = vec.size() - 1;
        return vec[lastidx];
    }
    bool isEmpty() {
        return vec.empty();
    }
};
int main() {
    // stacks using vectors
    // Stack s;
    // s.push(10);
    // s.push(20); 
    // s.push(30);
    // while(!s.isEmpty()) {
    //     cout << s.top() << " ";
    //     s.pop();
    // }
    //stacks using vectors and teemplate
    Stack<char> s;
    s.push('a');
    s.push('b'); 
    s.push('c');
    while(!s.isEmpty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    return 0;
}