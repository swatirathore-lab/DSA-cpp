
#include <iostream>
#include <deque>
using namespace std;
class stack{
    deque<int> d;
    public:
    void push(int data) {
        d.push_front(data);

    }
    void pop() {
        if(d.empty()){
            cout<<"stack is empty"<<endl;
            return;
        }
        else{
            d.pop_front();
        }
    }
    void top() {
        if (d.empty()){
            cout<<"stack is empty"<<endl;
        }
        else{
            cout<<d.front()<<endl;
        }
    }
    bool empty(){
        return d.empty();
    }

};
class stack1 {
    deque<int> d;
    public:
    void push(int data) {
        d.push_back(data);

    }
    void pop() {
        if(d.empty()){
            cout<<"stack is empty"<<endl;
            return;
        }
        else{
            d.pop_back();
        }
    }
    void top() {
        if (d.empty()){
            cout<<"stack is empty"<<endl;
        }
        else{
            cout<<d.back()<<endl;
        }
    }
    bool empty(){
        return d.empty();
    }

};
int main() {
    stack s;
    for(int i=1;i<=5;i++){
        s.push(i);
    }
    for(int i=1;i<=5;i++){
        s.top();
        s.pop();
    }
    stack1 s1;
    for(int i=1;i<=5;i++){
        s1.push(i);
    }
    for(int i=1;i<=5;i++){
        s1.top();
        s1.pop();
    }
    return 0;
}
