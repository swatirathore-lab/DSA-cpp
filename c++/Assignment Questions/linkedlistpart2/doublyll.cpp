#include <iostream>
using namespace std;
class node{
    public:
    int data;
    node* prev;
    node* next;
    node(int val){
        data=val;
        prev=next=NULL;

    }
};
class doubly {
    public:
    node* head;
    node* tail;
    doubly(){
        head=tail=NULL;

    }
    void push_front(int val){
    if(head==NULL){
        node* newnode=new node( val);
        head=tail=newnode;
        
    }else{
        node* newnode=new node(val);
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
    }
    }
    void pop_front(){
        node* temp=head;
        head=head->next;
        while(head!=NULL){//one node condition bhi isme justify ho jati
            head=head->next;

        }
        temp->next=NULL;
        delete temp;
    }
    void printlist() {
        node* temp=head;
        
        while(temp!=NULL){
            cout<<temp->data<<"<=>";
            temp=temp->next;
        }
        cout<<"NULL\n";
    }
};

int main() {
    doubly ll;
    ll.push_front(5);
    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.printlist();
    ll.pop_front();
    ll.pop_front();
    ll.printlist();
}
