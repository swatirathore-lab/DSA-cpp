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
        this->left=this->right=NULL;
    }

};
node* insert(node* root,int key){
    if(root==NULL){
        root=new node(key);
        return root;
    }
    if(key<root->data){
        root->left=insert(root->left,key);
    }
    else if(key>root->data){
        root->right=insert(root->right,key);
    }
    else{
        cout<<"duplicate value found"<<endl;
        return root;    
    }
    return root;

}
node* buildbst(int arr[],int n){
    node* root=NULL;
    for(int i=0;i<n;i++){
        root=insert(root,arr[i]);
    }
    return root;
}
// sorted array to balanced bst
node* sortedarraytobalancedbst(int arr[],int start,int end){
    if(start>end){//bhul gayi thi kaise karte
        return NULL;
    }
    int mid=start+(end-start)/2;//bhul gayi thi kaise karte
    node* curr=new node(arr[mid]);
    curr->left=sortedarraytobalancedbst(arr,start,mid-1);
    curr->right=sortedarraytobalancedbst(arr,mid+1,end);
    return curr;
}
//bst to balanced bst
node* BSTfrombalancedsequence(vector<int> arr,int start,int end){
    if(start>end){//bhul gayi thi kaise karte
        return NULL;
    }
    int mid=start+(end-start)/2;//bhul gayi thi kaise karte
    node* curr=new node(arr[mid]);
    curr->left=BSTfrombalancedsequence(arr,start,mid-1);
    curr->right=BSTfrombalancedsequence(arr,mid+1,end);
    return curr;
}
void gettinginorder(node* root,vector<int>& nodes){//& jaruri hai warna copy ban rahi ye galti tumne repeteadly ki hai
    if(root==NULL){
        return;
    }
    gettinginorder(root->left,nodes);
    cout<<root->data<<" ";
    nodes.push_back(root->data);//ye bhi bhul gaye the aap nodes me data push karna
    gettinginorder(root->right,nodes);
}
node* balancedbst(node* root){
    vector<int> nodes;
    gettinginorder(root,nodes);
    return BSTfrombalancedsequence(nodes,0,nodes.size()-1);//please rememeber how to pass when there is vector and pleasee godsake return 
}

void inorder(node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void preorder(node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main(){
    int arr[]={3,4,5,6,7,8,9};
    int n=sizeof(arr)/sizeof(int);
    node* root=sortedarraytobalancedbst(arr,0,n-1);//jab last index bhejenge to size se ek kum bhejeng
    inorder(root);
    cout<<endl;
    preorder(root);
    cout<<endl;
    node* root1=new node(6);
    root1->left=new node(5);
    root1->left->left=new node(4);
    root1->left->left->left=new node(3);
    root1->right=new node(7);
    root1->right->right=new node(8);
    root1->right->right->right=new node(9);
    root1=balancedbst(root1);
    cout<<endl;
    preorder(root1);
    cout<<endl;

    return 0;
}


