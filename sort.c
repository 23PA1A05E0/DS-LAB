
//Sorting Techinques
#include<stdio.h>
void Read(int [],int );
void print(int [],int );
void selection(int [],int );
void insertion(int [],int );
void swap(int *,int*);
    void Read(int a[],int n){
        int i;
        for(i=0;i<n;i++){
          scanf("%d",&a[i]);
        }
      } 
      
    void print(int a[],int n){
        int i;
        for( i=0;i<n;i++)
           printf("%d\t", a[i]);        
    }   
    
    void selection(int a[],int n){
         int i,j,min_index;
         for(i=0;i<n-1;i++){
            min_index=i;
            for(j=i+1;j<n;j++){
                if(a[min_index]>a[j]){
                  min_index=j;
                }
             }
            if(min_index!=i){
              swap(&a[min_index],&a[i]);
           
            }
         
         }
    }
    
    
    void swap(int *x,int *y){
       int temp=*x;
       *x=*y;
       *y=temp;
    }
      int main()
      {
       int n,i;
      
      printf("enter the size of an array");
      scanf("%d",&n);
      int a[n];
      printf("enter the %d elements",n);
      Read(a,n);
       /*for(i=0;i<n;i++)
       {
          scanf("%d",&a[i]);
          }*/
      printf("Before sorting\n");
      print(a,n);
      selection(a,n);
      printf("\nAfter sorting\n");
      print(a,n);
      
      return 0;
    }
    
    
    
    
    
    
    
    
