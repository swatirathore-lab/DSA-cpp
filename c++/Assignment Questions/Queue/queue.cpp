#include <iostream>
using namespace std;
class node {
    public:
    int data;
    node* next;
    node(int data) {
        this->data = data;
        this->next = NULL;
    }
};
class queue {
    node* head;
    node* tail;
public:
    queue() {
        head = NULL;
        tail = NULL;
    }
    void push(int data) {
        node* newNode = new node(data);
        if (head == NULL) {
            head = tail=newNode;
            
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    void pop() {
        if (head ==NULL){
            cout<<"Queue is empty"<<endl;
        } else {
            node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    int front() {
        if (head == NULL) {
            cout<<"Queue is empty"<<endl;
            return -1;
        } else {
            return head->data;
        }
    }
    bool isEmpty() {
        return head == NULL;
    }
    
};
int main() {
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    while(!q.isEmpty()){
        cout<<q.front()<<endl;
        q.pop();
    }
    return 0;
}