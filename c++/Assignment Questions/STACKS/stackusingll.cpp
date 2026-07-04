#include <iostream>
#include <vector>
#include <list>
#include <string>

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


int main() {
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