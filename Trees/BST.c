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
        root->left=insert(root->left,data);
       }
       else if(data>root->data){
          root->right=insert(root->right,data);
       }
      
     return root;
     }
}
					
void Inorder(struct node *root){
	if(root->left!=NULL)
		Inorder(root->left);
	printf("%d ",root->data);
	if(root->right!=NULL)
		Inorder(root->right);
}

void Preorder(struct node *root){
        printf("%d ",root->data); 
	if(root->left!=NULL)
		Preorder(root->left);
		
	if(root->right!=NULL)
		Preorder(root->right);
}

void Postorder(struct node *root){

	if(root->left!=NULL)
		Preorder(root->left);
		
	if(root->right!=NULL)
	       Preorder(root->right);
        printf("%d ",root->data); 		
}

int search(struct node *root,int key){
    if(key==root->data){
      printf("\nKey is found\n");
      return 0;
      } 
      else if (key<root->data  ||  key>root->data){
        if(key<root->data){
          search(root->left,key);
          
       }
       if(key>root->data){
         search(root->right,key);
       }
    
    }
    
 }   

int main(){

   struct node *root=NULL;
   root=insert(root,50);
   root=insert(root,20);
   root=insert(root,60);
   printf("\nInorder manner:");
   Inorder(root);
   printf("\nIn preorder manner:");
   Preorder(root);
   printf("\nIn Postorder manner:");
   Postorder(root);
   
  
   search(root,20 );

}
