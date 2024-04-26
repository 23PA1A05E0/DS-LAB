#include<stdio.h>
#include<stdlib.h>

struct node {
   int data;
   struct node *next;
  
};

void display(struct node *tail){
   struct node *ptr;
   ptr=tail->next;
   do{
   printf("%d ",ptr->data);
   ptr=ptr->next;
   }
   while(ptr!=tail->next);
   printf("\n");
}
struct node* Create_a_node(struct node *tail,int data){
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node*));
    temp->data=data;
    temp->next=temp;
    tail=temp;
    return tail;
}

void add_at_beginning(struct node *tail,int data){
     if(tail==NULL){
     printf("Link is Empty");
     }
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node*));
    temp->data=data;
    temp->next=NULL;
    temp->next=tail->next;
    tail->next=temp;
    return;

}


struct node* add_at_end(struct node *tail,int data){
    if(tail==NULL){
     printf("Link is Empty");
    }
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node*));
    temp->data=data;
    temp->next=NULL;
    temp->next=tail->next;
    tail->next=temp;
    tail=temp;
    return tail;    

}

struct node* add_at_position(struct node *tail,int data,int pos){
     if(tail==NULL){
     printf("Link is Empty");
     }
     if(pos==1){
     add_at_beginning(tail,data);
     return tail;
     }
     
      struct node *temp,*ptr;
      ptr=tail->next;
      temp=(struct node*)malloc(sizeof(struct node*));
      temp->data=data;
      temp->next=NULL;
      pos--;
      while(pos>1){
        ptr=ptr->next;
        pos--;
     }
     temp->next=ptr->next;
     ptr->next=temp;
     if(ptr==tail)
      tail=temp; 
     
     return tail;

}

void delete_at_beginning(struct node *tail){
    if(tail==tail->next){
    free(tail);
    }
    struct node *ptr;
    ptr=tail->next;
    tail->next=ptr->next;
    free(ptr);

}

void  delete_at_end(struct node *tail){
   struct node *ptr;
   ptr=tail->next;
   while(ptr->next!=tail){
    ptr=ptr->next;
   }
   ptr->next=tail->next;
   tail=NULL;
   free(tail);
   tail=ptr;
   
}

struct node* delete_at_position(struct node *tail,int pos)
{
   if(tail==tail->next){
   free(tail);
   return tail;
   }
   if(pos==1){
   delete_at_beginning(tail);
   }
   
   else{
    struct node *ptr,*ptr1;
   ptr=tail->next;
   while(pos>2){
   ptr=ptr->next;
   pos--;
   }
   ptr1=ptr->next;
   ptr->next=ptr1->next;
   free(ptr1);
   return tail;
  }
}

int main(){
   struct node *tail=NULL;
   tail=(struct node*)malloc(sizeof(struct node*));
   tail->data=20;
   tail->next=tail;
   add_at_beginning(tail,10);
   tail=add_at_end(tail,30);
   tail=add_at_position(tail,15,2);
   /*delete_at_beginning(tail);
   delete_at_end(tail);
   delete_at_position(tail,2);*/
   display(tail);
   int n,d;
   printf("enter number to do opeation\n(1-creation 2-insertion at beginning 3-delete at beinning )");
   scanf("%d",&n);
   switch(n){
   
   case 1:printf("enter data");
          scanf("%d",&d);
          tail=Create_a_node(tail,d);
          break;
    
   case 2:printf("enter data to note down");
          scanf("%d",&d);
          add_at_beginning(tail,d); 
          break;
          
   case 3:delete_at_beginning(tail);
           break;
       
   default:printf("Invalid position");
           break;
           
   }
   printf("element in List:: ");
   display(tail);
                              
 
  
}
