#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    node(int data){
        this->data=data;
        left=right=NULL;
    }
    

};
static int idx=-1;

node* build(vector<int> nodes){
        
    idx++;
    if(nodes[idx]==-1){
        return NULL;
    }
        
    node* currnode=new node{nodes[idx]};
    currnode->left=build(nodes);
    currnode->right=build(nodes);
    return currnode;
}
void levelorder(node* root){
    if(root==NULL){
        return;
    }
    queue<node*> q;//node bana lo instead of int star* is very important
    q.push(root);

    while(!q.empty()){
        node* curr=q.front();
        q.pop();
        // BUG: nothing ever prints curr->data here!
        cout << curr->data << " ";
        if(curr->left!=NULL){
            q.push(curr->left);
        }
        if(curr->right!=NULL){
            q.push(curr->right);
        }

    }
    
}
int transform(node* root){
    if(root==NULL){
        return 0;
    }
    int leftold=transform(root->left);
    int rightold=transform(root->right);
    int currold=root->data;
    root->data=leftold+rightold;
    if(root->left!=NULL){
        root->data+=root->left->data;
    }
    if(root->right!=NULL){
        root->data+=root->right->data;
    }
    return currold;
}
int main(){
    vector<int> nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    node* root=build(nodes);
    cout<<transform(root);
    levelorder(root);
}