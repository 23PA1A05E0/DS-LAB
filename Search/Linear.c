#include<stdio.h>
int main() 
   {
   int a[50]={1,2,3,4,5,6,7,8,9,10};
   int n=10, i, pos, num, t=0;
   printf("enter the number to search");
   scanf("%d", &num);
   for(i=0;i<n;i++)
   {
   if(num==a[i])
   {
   t=1;
   break;
   }
   }
   if(t==1)
   {
   printf("index no is %d", i);
   } 
   else
   {
   
   printf("it is not found in the given array" );
   } 
   return 0;
   }
