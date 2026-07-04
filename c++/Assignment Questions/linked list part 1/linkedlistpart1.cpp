#include <iostream>
using namespace std;
//LL implementation
class node {
    public:
    int data;
    node* next;
    node(int val){
        data=val;
        next=NULL;
    }
    ~node(){//for deleting entire ll we are doing it
        if(next!=NULL){
            delete next;
            next=NULL;
        }
    }
};
class list {
    node* head;
    node* tail;
public:
    list() {
        head=NULL;
        tail=NULL;
    }
    ~list() {//for deleting entire ll we are doing it
        if(head!=NULL){
            delete head;
            head=NULL;
        }
    }
    void push_front(int val){
        node* newnode = new node(val);//dynamic allocation hota new ko use karne se
        // node* newnode(val);//static
        if(head==NULL){
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
    void printlist() {
        node* temp=head;
        
        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL\n";
    }
    void insert(int val,int pos){
        node* newnode = new node (val);
        node* temp = head;
        for(int i=0;i<pos-1;i++){
            if(temp==NULL){
                cout<<"position is INVALID\n";
                return;
            }

            temp=temp->next;
        }
        //temp is now at pos-1 i.e prev/left
        newnode->next = temp->next;
        temp->next=newnode;

    }
    void pop_front(){
        node* temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }
    void pop_back() {
        node* temp =head;
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        temp->next=NULL;
        delete tail;
        tail=temp;

    }
    int searchitr(int key){
        int idx=0;
        node* temp=head;
        while(temp!=NULL){
            if(temp->data==key){
                return idx;
            }
            temp=temp->next;
            idx++;
        }
        return -1;

    }
    //head is private so to acess it helper is made
    int helper(node* temp,int key){
        if(temp == NULL){     // <-- base case: ran off the end, not found
        return -1;
        }
        if(temp->data==key){
            return 0;
        }
        int idx=helper(temp->next,key);
        if(idx==-1){
            return -1;
        }
        return idx+1;
    }
    int searchrec(int key){
        return helper(head,key);
    }
    void reverse() {
        node* curr=head;
        node* prev=NULL;
        while(curr!=NULL){
            node* next =curr->next;
            curr->next=prev;
            //updation for next itr
            prev=curr;
            curr=next;
        }
        //prev=lastnode=newhead;
        head=prev;
    }
    int getsize(){
        int sz=0;
        node* temp=head;
        while(temp!=NULL){
            temp=temp->next;
            sz++;
        }
        return sz;
    }
    void removenth(int n){//o(n);o(1)
        int size=getsize();
        node* prev =head;
        for(int i=1;i<(size-n);i++){//i=size-n=>prev=>deletion node prev
            prev=prev->next;
        }
        node* todel=prev->next;
        cout<<"going to delete: "<<todel->data<<endl;
        prev->next=prev->next->next;

    }
    bool isPalinHelper(node*& back, node* front) {
        if(front==NULL){
            return true;
        }
        bool smallpalindrom=isPalinHelper(back,front->next);
        bool currentpalindrom=(front->data==back->data);
        back=back->next;
        return smallpalindrom && currentpalindrom;
    // front: the pointer that recurses deep first (goes node1 -> node2 -> ... -> NULL)
    // back:  passed BY REFERENCE so all recursive calls share and update the SAME variable,
    //        starts at head, only moves forward AFTER a recursive call returns
    }

    bool isPalindrome() {
        node* back = head;
        return isPalinHelper(back, head);
    }

};

int main() {
    list ll;
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(1);
    //1->2->3->null
    ll.printlist();//1->2->3->NULL
    // ll.pop_front();
    // ll.insert(100,2);
    // ll.printlist();
    // cout << ll.searchitr(2) << endl;
    // cout<<ll.searchrec(4)<<endl;
    // ll.reverse();
    // ll.printlist();
    // ll.removenth(2);
    // ll.printlist();
    cout<<ll.isPalindrome();
    return 0;

}
