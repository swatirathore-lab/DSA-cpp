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
int kthancestor(node* root,int node,int k){
    if(root==NULL){
        return -1;
    }
    if(root->data==node){//remember data check karege node ke sath
        return 0;
    }
    int leftdist=kthancestor(root->left,node,k);
    int rightdist=kthancestor(root->right,node,k);
    if(leftdist==-1 && rightdist==-1){
        return -1;
    }
    int valdist=leftdist==-1?rightdist:leftdist;
    if(valdist+1==k){
        cout<<"kth ancestor would be :"<<root->data<<endl;
    }
    return valdist+1;
}
int main(){
    vector<int> nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    node* root=build(nodes);
    int node=5,k=2;
    kthancestor(root,node,k);
    return 0;
}
// Bottom line — "distance count karke node kaise return ho raha"
// Har level pe upar jaate hue +1 hota jaata hai (jaise ek counter jo target milne ke baad har parent call mein badhta hai).
// Jab valdist+1 == k match ho jaata hai, uss waqt jo bhi root hai — wahi hai kth ancestor — kyunki hum exactly k steps upar target se pahunch chuke hain.
// Node khud return nahi ho raha (return type int hai) — sirf distance number return hota hai upar tak; jab distance k ke barabar milta hai, tabhi root->data ko print kar diya jaata hai (return nahi kiya jaata, isiliye main() mein value use nahi ho sakti).