#include <iostream>
#include <vector>
#include <queue>
#include <map>
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
void topview(node* root){
    queue<pair <node*,int>> q;//do not forget the < before pair
    map<int,int> m;//no need of pair
    q.push(make_pair(root,0));
    while(!q.empty()){
        pair<node*,int> curr=q.front();
        q.pop();
        node* currnode=curr.first;
        int currhd=curr.second;
        if(m.count(currhd)==0){
            m[currhd]=currnode->data;
        }
        if(currnode->left!=NULL){
            pair<node*,int> left=make_pair(currnode->left,currhd-1);
            q.push(left);
        }
        if(currnode->right!=NULL){
            pair<node*,int> right=make_pair(currnode->right,currhd+1);
            q.push(right);
        }

    }
    for(auto it:m){
        cout<<it.second;
    }
    cout<<endl;



}



int main(){
    vector <int> nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    node* root=build(nodes);
    topview(root);
    return 0;
}