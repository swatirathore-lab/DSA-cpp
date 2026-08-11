#include <iostream>
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
void preorder(node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

}
void postorder(node* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";

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
void levelorder1(node* root){
    if(root==NULL){
        return;
    }
    queue<node*> q;//node bana lo instead of int star* is very important
    q.push(root);
    q.push(NULL);//for*******
    

    while(!q.empty()){
        node* curr=q.front();
        q.pop();
        
        if(curr==NULL){
            cout<<endl;//agar curr null hai to endl charcatwrr daal do
            //agar null character nikalneke baad queue khali ho gayi
            if(q.empty()){
                break;
            }
            q.push(NULL);//to track next line
        }
        else{
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
int count(node* root){
    if(root==NULL){
        return 0;
    }
    int countlt=count(root->left);
    int countrt=count(root->right);
    return countlt+countrt+1;

}
int sum(node* root){
    if(root==NULL){
        return 0;
    }
    int sumleft=sum(root->left);
    int sumright=sum(root->right);
    return sumleft+sumright+root->data;

}
int main(){
    vector<int> nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    node* root=build(nodes);
    cout<<"root = "<<root->data<<endl;
    preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    levelorder(root);
    cout<<endl;
    levelorder1(root);
    cout<<endl;
    cout<<height(root);
    cout<<endl;
    cout<<count(root);
    cout<<endl;
    cout<<sum(root);
    cout<<endl;

    return 0;
}