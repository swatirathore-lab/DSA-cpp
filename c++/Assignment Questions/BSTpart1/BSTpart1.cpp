#include <iostream>
#include <vector>
using namespace std;

//create and insert a binary tree node
class Node {
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};
Node* insert(Node* root,int val){
    if(root==NULL){
        root=new Node(val);
        return root;
    }
    if(val<root->data){
        root->left=insert(root->left,val);
    }
    else if(val>root->data){
        root->right=insert(root->right,val);
    }
    else{
        cout<<"duplicate value found"<<endl;
        return root;
    }
}
Node* Buildbst(int arr[],int n){
    Node* root=NULL;
    for(int i=0;i<n;i++){
        insert(root,arr[i]);
    }
    return root;
}
void inorder(Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
//search in bst
Node* search(Node* root,int key){
    if(root==NULL || root->data==key){
        return root;
    }
    if(key<root->data){
        return search(root->left,key);
    }
    else{
        return search(root->right,key);
    }
}
Node* inorderSuccessor(Node* root){
    Node* curr=root;
    if(curr->left!=NULL){
        curr=curr->left;
    }
    return curr;
}
Node* deleteNode(Node* root,int key){
    if(root==NULL){
        return NULL;
    }
    if(key<root->data){
        root->left=deleteNode(root->left,key);
    }
    else if(key>root->data){
        root->right=deleteNode(root->right,key);
    }
    else{
        //case1: no child
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        else if(root->left==NULL || root->right==NULL){
            Node* temp=root->left==NULL?root->right:root->left;
            delete root;
            return temp;
        }
        else{
            Node* temp =inorderSuccessor(root->right);
            root->data=temp->data;
            root->right=deleteNode(root->right,temp->data);

        }
    }
    return root;
}
//root to leaf path
void printpath(vector<int> &path){
    for(int i=0;i<path.size();i++){
        cout<<path[i]<<" ";
    }
    cout<<endl;
}
Node* pathhelper(Node* root,vector<int> &path){
    if(root==NULL){
        return NULL;
    }
    path.push_back(root->data);
    if(root->left==NULL && root->right==NULL){
        printpath(path);
        path.pop_back();
        return NULL;
    }
    pathhelper(root->left,path);
    pathhelper(root->right,path);
    path.pop_back();
}
Node* roottoleaf(Node* root){
    vector<int> path;
    pathhelper(root,path);
    return root;
}
bool validatehelper(Node* root,Node* min,Node* max){
    if(root==NULL){
        return true;
    }
    if((min!=NULL && root->data<=min->data) || (max!=NULL && root->data>=max->data)){
        return false;
    }
    return validatehelper(root->left,min,root) && validatehelper(root->right,root,max);
}
//validate bst
bool validatebst(Node* root){
    return validatehelper(root,NULL,NULL);
}

int main() {
    int arr[]={5,1,4,3,2,7};
    int n=sizeof(arr)/sizeof(int);
    Node* root=Buildbst(arr,n);
    inorder(root);
    Node* result=search(root,3);
    if(result){
        cout<<"Element found in BST"<<endl;
    }
    else{
        cout<<"Element not found in BST"<<endl;
    }
    roottoleaf(root);
    validatebst(root)?cout<<"Valid BST"<<endl:cout<<"Invalid BST"<<endl;
}