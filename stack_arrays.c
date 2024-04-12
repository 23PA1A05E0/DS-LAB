#include<stdio.h>
int stack[100],choice,n,x,i,top;
void display();
void push();
void pop();
void exit();

int main(){
   top=-1;
   printf("Enter the size of stack");
   scanf("%d",&n);
   
   printf("\n 1-push\n 2-pop\n 3-display\n 4-exit\n");
   do
   {
     printf("\nEnter the choice:");
     scanf("%d",&choice);
     switch(choice)
     {
       
       case 1: push();
               break;
               
       case 2: pop();
               break;
       
       case 3: display();
               break;
       
       case 4: printf("Exit points\n");
               break;
       
      default: printf("Enter the valid option 1/2/3/4");
               break;                              
    }   
  }
   while(choice!=4);
   return 0;
  
}

void push(){
    if(top>=n-1){
      printf("stack overflow");
    }
    else{
      printf("Enter the element to insert:");
      scanf("%d",&x);
      top++;
      stack[top]=x;
    
    }
   return;
}

void pop(){

  if(top<=-1){
    printf("stack is underflow");
  }
  else{
    printf("the popped element is %d",stack[top]);
    top--;
  }

}
  
void display(){
 if(n>=0){
   printf("The element in stack:\n");
   for(i=top;i>=0;i--){
  
     printf("%d\n",stack[i]);   
  }
  printf("Enter the next choice");
}

else{
  printf("Stack is empty");
 }
  return;
} 
  
  
  
  
  
  
  
  
  
  
  
  
