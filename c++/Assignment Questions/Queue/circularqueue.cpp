#include <iostream>
using namespace std;
class Queue{
    
    
    int *arr;//array to store queue elements
    int capacity;//maximum capacity of the queue
    int currsize;//current size of the queue
    int f,r;//front and rear of the queue
    public:
    Queue(int capacity){
        this->capacity=capacity;
        arr=new int (capacity);
        currsize=0;
        f=0;
        r=-1;
    }
    void push(int data) {
        //n kya hai n hai capacity ke equal to ya usse chhota hona chahiye
        if(currsize == capacity){
            cout<<"Queue is full"<<endl;
            return;
        }
        r=(r+1)%capacity;
        arr[r]= data;
        currsize++;

    }
    void pop(){
        if(empty()){
            cout<<"Queue is empty"<<endl;
            return;
        }
        f=(f+1)%capacity;
        currsize--;

    }
    int front() {
        if(empty()){
            cout<<"Queue is empty"<<endl;
            return -1;
        }

        return arr[f];

    }
    bool empty(){
        return currsize==0;
    }
};
int main () {
    Queue q(4);
    q.push(1);
    q.push(2);
    q.push(3);
    cout<<q.front()<<endl;
    q.pop();
    cout<<q.front()<<endl;
    q.push(4);
    cout<<q.front()<<endl;

    return 0;
}