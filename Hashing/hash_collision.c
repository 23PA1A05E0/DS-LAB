#include<stdio.h>
#include<stdlib.h>
# define size 10

struct node {
     int data;
     struct node *next;
};

struct node *head[size]={NULL},*c;

void insert(){
  int key,i;
  printf("Enter the element to insert");
  scanf("%d",&key);
  i=key%size;
  struct node *Newnode=(struct node *)malloc(sizeof(struct node *));
  Newnode->data=key;
  Newnode->next=NULL;
  if(head[i]==NULL)
     head[i]=Newnode;
  else{
     c=head[i];
     while(c!=NULL){
       c=c->next;
    }
   c->next=Newnode;   
 }   

}


int search(){
     int i,key;
     printf("Enter the element to searh");
     scanf("%d",&key);
     i=key%size;
     if(head[i]==NULL){
       printf("key is not found\n");
     }
     else{
        for(c=head[i];c!=NULL;c=c->next){
           if(c->data==key){
              printf("key is  found\n");
              break;
           }
           if(c==NULL)
              printf("key is not found\n");
        
      }    
   }
}


void display(){
       int i;
      for(i=0;i<size;i++){
	  printf("\n");
	  if(head[i]==NULL)
	     continue;
	  else{
	       
	       for(c=head[i];c!=NULL;c=c->next){
		    
		  printf("->%d ",c->data);
		 
	      }
        }    
         
    }
}
  
int main(){    

     int choice;
     printf("\n 1.Insert\n 2.Search\n 3.display\n 4.exit"); 
     while(1){
      printf("\nEnter the choice:");
      scanf("%d",&choice);
      switch(choice){
       
        case 1: insert();
                break;
               
               
        case 2: search();
               
                break;
               
        case 3: display();
                break;        
       
        case 4: printf("Exits points\n");
               exit(1);      
       
       default:printf("Enter the valid option 1/2/3/4");        
               break;
     
     }
  }
   
   

}
