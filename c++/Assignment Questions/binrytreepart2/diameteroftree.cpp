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
int height(node* root){
    if(root==NULL){
        return 0;
    }
    int leftht=height(root->left);
    int rightht=height(root->right);
    int currht=max(leftht,rightht)+1;
    return currht;
}
int diameter(node* root){
    if(root==NULL){
        return 0;
    }
    int currdiam=height(root->left)+height(root->right)+1;
    int diamleft=diameter(root->left);
    int diamright=diameter(root->right);
    return max({currdiam, diamleft, diamright});//**********important  hai bhai{} */
}
pair<int, int> diameter2(node* root){
    if(root==NULL){
        return make_pair(0,0);

    }
    pair<int,int> leftinfo=diameter2(root->left);
    pair<int,int> rightinfo=diameter2(root->right);
    int currdiam =leftinfo.second+rightinfo.second+1;
    int finaldiam=max(currdiam,max(leftinfo.first,rightinfo.first));
    int finalht=max(leftinfo.first,rightinfo.first)+1;
    return make_pair(finaldiam,finalht);
}

int main(){
    vector<int> nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    node* root=build(nodes);
    cout<<"root = "<<root->data<<endl;
    cout<<diameter(root);
    cout<<diameter2(root).first;

}