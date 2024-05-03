#include<stdio.h>
#include<stdlib.h>

struct node{
     int data;
     struct node *left,*right;
};

struct node* CreateNode(int data){
      struct node *temp;
      temp=(struct node*)malloc(sizeof(struct node*));
      temp->data=data;
      return temp;
}

struct node* insert(struct node *root,int data){
     if(root==NULL)
        return CreateNode(data);
     else{
       if(data<root->data){
        root=insert(root->left,data);
       }
       else if(data>root->data){
          root=insert(root->right,data)
       }
       return root;
     
     }
}


void Inorder(struct node *root){
     if



}

int main(){

   struct node *root=NULL;
   root=insert(root,50);
   


}
