#include <iostream>
#include <vector>
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
void kthhelper(node* root,int k,int currlevel){
    if(root==NULL){
        return;
    }
    if(currlevel==k){
        cout<<root->data<<" ";
        return;
    }
    kthhelper(root->left,k,currlevel+1);
    kthhelper(root->right,k,currlevel+1);
}
void kthlevelnode(node* root,int k){//o(n)
    kthhelper(root,k,1);
    cout<<endl;

}
int main(){
    vector<int> nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    node* root=build(nodes);
    kthlevelnode(root, 2); // example: print level 2 nodes
}