  #include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
struct node
  {
  int data;
  struct node *next;
  };
 struct node *start;
   void create(void)
    {
      struct node *nn;
      int a;
      nn=(struct node *)malloc(sizeof(struct node));
      printf("enter data");
     scanf("%d",&nn->data);
a=nn->data;
if(start==NULL) 
{
nn->next=NULL;
start=nn;
}
else
{
nn->next=start;
start=nn;
}
printf("%d succ. inserted\n",a);
return;
}
void deletion(void)
{
struct node *pt,*t;
int x;
if(start==NULL)
{
printf("sll is empty\n");
return;
}
printf("enter data to be deleted:");
scanf("%d",&x);
if(x==start->data)
{
t=start;
start=start->next;
free(t);
printf("%d is succ. deleted\n",x);
return;
}
pt=start;
t=start->next;
while(t!=NULL&&t->data!=x)
{
pt=t;t=t->next;
}
if(t==NULL)
{
printf("%d does not exist\n",x);return;
}
else
{
pt->next=t->next;
}
printf("%d is succ. deleted\n",x);
free(t);
return;
}
int main()
{
int c,a;
start=NULL;
do
{
printf("1:insert\n2:delete\n enter choice:");
scanf("%d",&c);
switch(c)
{
break;
case 1:create( ); break;
case 2:deletion( ); break;
case 3: printf("exit"); break;
default:printf("wrong choice\n");
break;
}
}
while(c!=3);

}



