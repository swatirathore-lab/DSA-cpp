#include <iostream>
#include <deque>
using namespace std;
class Queue{
    deque<int> d;
    public:
    void push(int data){
        d.push_back(data);
    }
    void pop(){
        if(d.empty()){
            cout<<"queue is empty"<<endl;
            return;
        }
        else{
            d.pop_front();
        }
    }
    void front(){
        if(d.empty()){
            cout<<"queue is empty"<<endl;
            return;
        }
        else{
            cout<<d.front()<<endl;
        }
    }
    bool empty(){
        return d.empty();
    }
    
};
int main() {
    Queue q;
    for(int i=1;i<6;i++){
        q.push(i);
    }
    for(int i=1;i<6;i++){
        q.front();
        q.pop();
    }
    return 0;
}