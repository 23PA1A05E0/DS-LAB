#include<stdio.h>
int main(){
    int n,i,j;
    printf("enter the size of an array");
    scanf("%d",&n);
    int a[n],temp;
    printf("enter the %d of an array",n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<n-1;i++){
          for(j=i+1;j<n;j++){
          if(a[i]>a[j]){
              temp=a[j];
              a[j]=a[i];
              a[i]=temp;
              
            }
          }
    }
    printf("After bubble sort \n");
      for(i=0;i<n;i++){
          printf("%d\n",a[i]);
 }
    
}
