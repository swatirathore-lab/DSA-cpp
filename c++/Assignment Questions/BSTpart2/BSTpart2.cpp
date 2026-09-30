#include <iostream>
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

}
node* buildbst(int arr[],int n){
    node* root=NULL;
    for(int i=0;i<n;i++){
        insert(root,arr[i]);
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
    return 0;
}


