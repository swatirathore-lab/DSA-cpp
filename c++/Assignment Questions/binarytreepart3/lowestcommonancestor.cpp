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
bool roottonode(node* root,int n,vector<int> &path){// path is with ^ because otherwise changes in belowed function would not be visible in the code
    if(root==NULL){
        return false;
    }
    path.push_back(root->data);
    if(root->data==n){
        return true;
    }
    int isleft=roottonode(root->left,n,path);
    int isright=roottonode(root->right,n,path);
    if(isleft || isright){
        return true;
    }
    path.pop_back();
    return false;

}
int lowestcommonancestor(node* root,int n1,int n2){
    vector<int> path1;
    vector<int> path2;
    roottonode(root,n1,path1);
    roottonode(root,n2,path2);
    int lca=-1;
    for(int i=0,j=0;i<path1.size()&&j<path2.size();i++,j++){
        if(path1[i] != path2[i]){
            return lca;
        }
        lca=path1[i];
    }
    return lca;


}

int main(){
    vector<int> nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    node* root=build(nodes);
    int n1=4,n2=5;
    cout<<lowestcommonancestor(root,n1,n2);//o(n)
    
}