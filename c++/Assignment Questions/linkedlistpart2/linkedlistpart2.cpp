#include <iostream>
using namespace std;
#include <list>
#include <iterator>

//LL implementation
class node {
    public:
    int data;
    node* next;
    node(int val){
        data=val;
        next=NULL;
    }
};
class List {
    public:
    node* head;
    node* tail;

    List() {
        head=NULL;
        tail=NULL;
    }
    void push_front(int val){
        node* newnode = new node(val);//dynamic allocation hota new ko use karne se
        // node* newnode(val);//static
        if(tail==NULL){
            head=tail=newnode;
        }else {
            newnode->next = head;
            head = newnode;
        }
    }
    void push_back(int val){
        node* newnode =new node(val);
        if(head==NULL){
            head=tail=newnode;
        }else {
            tail->next=newnode;
            tail=newnode;
        }
    }
    void pop_front(){
        if(head==NULL){
            return;
        }
        node* temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }
};
void printlist(node* head) {
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL\n";
}
bool iscycle(node* head){
    node* fast=head;
    node* slow=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(fast==slow){
            cout<<"loop/cycle in a linked list"<<endl;
            return true;
        }
    }
    cout<<"loop/cycle not in a linked list"<<endl;
    return false;
} 
void removecycle(node* head){
    node* fast=head;
    node* slow=head;
    bool iscycle=false;//is baari to cycle hume delete karni hai rather than giving trye or false so for that
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(fast==slow){
            cout<<"cycle do exist"<<endl;
            iscycle=true;
            break;
        }
    }
    if(!iscycle){
        cout<<"cycyle do not exist"<<endl;
        return;
    }
    slow=head;
    if(slow==fast){
        while(fast->next!=slow){
            fast=fast->next;
        }
        fast->next=NULL;
    }else{
        node* prev=fast;//to add track the last node
        while(slow!=fast){
            slow=slow->next;
            prev=fast;
            fast=fast->next;
        }
        prev->next=NULL;
    }
} 
void printList(list<int> ll){
    list<int>::iterator itr;
    for(itr =ll.begin();itr != ll.end();itr++){
        cout<<(*itr)<<" ->";
    }
    cout<<"NULL"<<endl;
}
node* splitatmid(node* head){
    node* slow = head;
    node* fast= head;
    node* prev=NULL;
    while(fast!=NULL && fast->next!=NULL){//uhm && is important not ||
        prev=slow;     
        slow=slow->next;
        fast=fast->next->next;
    }
    if(prev!=NULL){
        prev->next=NULL;
    }
    if(prev!=NULL){
        prev->next =NULL;//split at middle
    }
    return slow;
}
node* merge(node* left ,node* right){
    List ans;
    node* i=left;
    node* j=right;
    while(i != NULL && j !=NULL){
        if(i->data==j->data){
            ans.push_back(i->data);
            i=i->next;
        }else{
            ans.push_back(j->data);
            j=j->next;
        }
    }
    while(i!=NULL){
        ans.push_back(i->data);
        i=i->next;
    }
    while(j!=NULL){
        ans.push_back(j->data);
        j=j->next;
    }
    return ans.head;
}
node* mergesort(node* head){
    if(head->next==NULL || head==NULL){
        return head;
    }
    node* righthead=splitatmid(head);
    node* left=mergesort(head);//lefthead
    node* right=mergesort(righthead);//righthead
    return merge(left,right);
}
//zig-zag linked list
node* reverseforzigzag(node* head){
    node* prev=NULL;
    node* curr=head;//head not NULL
    node* next=NULL;
    while(curr!=NULL){//I forgot the part where it should be curr not head minor mistakes
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;

}
node* zigzag(node* head){
    node* righthead=splitatmid(head);
    node* rightheadreversed=reverseforzigzag(righthead);//pass the righthead not an head have to reverse the right side not the whole ll
    //alternate merging
    node* left=head;
    node* right=rightheadreversed;
    node* tail=right;//for add shit
    while(left!=NULL && right!=NULL){
        node* nextleft=left->next;
        node* nextright=right->next;
        left->next=right;
        right->next=nextleft;
        tail=right;//odd shit last element store ho jata nextright banane se pehle phir aage jakr usse jod lete hai agle se
        left=nextleft;
        right=nextright;
    }
    if(right!=NULL){//if not while otherwise infinite loop
        tail->next=right;
    }
    return head;
    
}


int main(){
    // list<int> ll;
    // ll.push_front(2);
    // ll.push_front(1);
    // ll.push_back(3);
    // ll.push_back(4);
    // printList(ll);
    // cout<<ll.size()<<endl;
    // cout<<"head= "<<ll.front()<<"\n";
    // cout<<"tail= "<<ll.back()<<"\n";
    // ll.pop_front();
    // printList(ll);
    // ll.pop_back();
    // printList(ll);
    // List ll;
    // ll.push_front(3);
    // ll.push_front(2);
    // ll.push_front(1);
    // ll.push_front(4);
    // ll.push_front(5);
    // //5->4->3->2->1->NULL
    // printlist(ll.head);
    // ll.head=mergesort(ll.head);//important so that the value don't get thrown away
    // printlist(ll.head);
    ////zigzag linked list
    List ll;
    ll.push_front(5);
    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    printlist(ll.head);
    ll.head=zigzag(ll.head);
    printlist(ll.head);



    return 0;
}