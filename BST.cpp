#include<bits/stdc++.h>
using namespace std;
struct node{
int data;
struct node*left=NULL;
struct node*right=NULL;
};
node*create_node(int item){
node*newnode=new node();
newnode->data=item;
newnode->left=NULL;
newnode->right=NULL;
return newnode;
}
node*create_bst(node*root,int x){
if(root==NULL){
       root=create_node(x);
}
else if(x>root->data){
       root->right=create_bst(root->right,x);
}
else {
       root->left=create_bst(root->left,x);
}
return root;
}

void inorder_traverse(node*root){
if(root==NULL) return;

inorder_traverse(root->left);
 cout<<root->data<<" ";
inorder_traverse(root->right);

}
bool search(node* root, int val) {
    if (root == NULL) return false; 
    if (root->data == val) return true; 
    if (val > root->data) 
        return search(root->right, val); 
    return search(root->left, val); 
}

int main(){
int n;
cin>>n;
int a[n];
for(int i=0;i<n;i++)cin>>a[i];
node*root=NULL;
for(int i=0;i<n;i++){
root=create_bst(root,a[i]);
}

inorder_traverse(root);
   int val;
   cin>>val;
   if(search(root,val)) cout<<"YES";
   else cout<<"NO";
}
