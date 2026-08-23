#include <iostream>
#include <algorithm>   // needed for max({a, b, c})
#include <queue>
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
bool isidentical(node* root1,node* root2){
    if(root1==NULL && root2==NULL){
        return true;
    }
    if(root1==NULL || root2==NULL){
        return false;
    }
    if(root1->data!=root2->data){
        return false;
    }
    return isidentical(root1->left,root2->left) && isidentical(root1->right,root2->right);

         
    
}
bool issubtree(node* root,node* subroot){
    //base conditions
    if(root==NULL && subroot==NULL){
        return true;
    }
    if(root==NULL || subroot==NULL){
        return false;
    }
    if(root->data==subroot->data){
        //check rest of the tree for identical nodes
        if(isidentical(root,subroot)){
            return true;
        }
    }
    int leftsubtree=issubtree(root->left,subroot);
    if(!leftsubtree){
        return issubtree(root->right,subroot);
    }
    return true;
}
int main(){
    vector<int> nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    node* root=build(nodes);
    node* subroot=new node(2);
    subroot->left=new node(4);
    subroot->right=new node(5);
    cout<<issubtree(root,subroot);
    return 0;
}
