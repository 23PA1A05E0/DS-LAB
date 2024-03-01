#include<stdio.h>
#include<stdlib.h>


struct node{
      int data;
      struct node *link;
};

void display(struct node *head){

    struct node *ptr;
    ptr=head;
    
    while(ptr!=NULL){
    
      printf("%d  ",ptr->data);
      ptr=ptr->link;
    
    }

}
void add_at_beginning(struct node **head,int data){

     struct node *temp;
     temp=malloc(sizeof(struct node*));
     temp->data=data;
     temp->link=*head;
     *head=temp;
 
}

void add_at_position(struct node *head,int data,int pos){

     struct node *ptr,*temp;
     ptr=head;
     temp=malloc(sizeof(struct node*));
     temp->data=data;
     temp->link=NULL;
     
     while(pos-2>0){
         
         ptr=ptr->link;
         pos--;
     }
     temp->link=ptr->link;
     ptr->link=temp;
 
}

void add_at_end(struct node *head,int data){

     struct node *ptr,*temp;
     ptr=head;
     temp=malloc(sizeof(struct node*));
     temp->data=data;
     temp->link=NULL;
     while(ptr->link!=NULL){
        
         ptr=ptr->link;
     }
     
     ptr->link=temp;
 
}

int count_nodes(struct node *head){

    struct node *ptr;
    ptr=head;
    int count=0;
    while(ptr!=NULL){
         ptr=ptr->link;
         count++;
               
 
    }
 return count;
 
 }

int main()
{ 
  int size;
  struct node *head;
  head=malloc(sizeof(struct node*));
  head->data=10;
  head->link=NULL;
  struct node *current;
  current=malloc(sizeof(struct node*));
  
  current->data=20;
  current->link=NULL;
  
  head->link=current;
  
  current=malloc(sizeof(struct node*));
  
  current->data=30;
  current->link=NULL;
  
  head->link->link=current;
  
  //add_at_beginning(&head,5);
  add_at_position(head,60,2);
  //add_at_end(head,40);
  
  display(head);
  size=count_nodes(head);
  
  printf("\nNo of nodes:%d",size);
  return 0;
}
