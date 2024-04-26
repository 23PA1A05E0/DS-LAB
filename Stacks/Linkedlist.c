#include<stdio.h>
#include<stdlib.h>

struct node{
   int data;
   struct node *next;
   
}*top=NULL;

void display();
void push(int data);
int pop();

int main(){
    int choice;
    int x,d;
    top=(struct node *)malloc(sizeof(struct node *));
    top=NULL;  
    printf("\n 1.push\n 2.pop\n 3.display\n 4.exit"); 
    do{
      printf("\nEnter the choice:");
      scanf("%d",&choice);
      switch(choice){
       
        case 1: printf("\nenter the element to insert:");
               scanf("%d",&x);
               push(x);
               break;
               
               
        case 2: d=pop();
               printf("The popped element is %d",d);
               break;
               
        case 3: display();
               break;        
       
        case 4: printf("Exits points\n");
               break;        
       
       default:printf("Enter the valid option 1/2/3/4");        
               break;
     
     }
   }
    while(choice!=4);
}
void push(int data){

  
  
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node *));
    temp->data=data;
    temp->next=top;
    top=temp;
}


int pop(){

    struct node *temp;
    if(top==NULL){
    	printf("Stack is empty\n");
    	return 0;
    }
    temp=(struct node *)malloc(sizeof(struct node *));
    temp=top;
    int d=top->data;
    top=top->next;
    temp=NULL;
    free(temp);
    return d;
}


void display(){

   struct node *ptr;
   ptr=top;
   if(top==NULL){
     printf("Stack is empty");
   }
   else{
     while(ptr!=NULL){
       printf("%d ",ptr->data);
       ptr=ptr->next;
   }   
 }

}





