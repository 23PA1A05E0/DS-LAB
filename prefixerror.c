#include <stdio.h>
#include<string.h>
#define max 50               
char stack[max];
int top = -1;
char infix[50],postfix[50];
char reverse[52];

void push(char element)     
{
	stack[++top]=element;
}
char pop(){
	return(stack[top--]);
}

int priority(char x)
{
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    
    if(x=='^') 
       return 3;
    return 0;   
} 


 int check(char ch)   
{   
    return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')|| (ch>='0' && ch<='9' ));   
}   

int main(void) {
	char ch,element;
	int i=0,k=0,j=0,len;
	printf("READ THE INFIX\n\n");
	scanf("%s",infix);
	len=strlen(infix);
	printf("\n%d\n",len);
	for(i=len-1;infix[i]!='\0';i--){
	   reverse[j]=infix[i];
	   i--;
	   j++;
	  
	}
	reverse[j]='\0';
	printf("\n%s\n",reverse);
	for(i=0;reverse!='\0';i++){
	  if(reverse[i]=='('){
	    reverse[i]=')';
	  }
	  if(reverse[i]==')'){
	    reverse[i]='(';
	  }
	
	}
	push('#');                                 
        i=0;
	while((ch = reverse[i++])!='\0'){
		if(ch=='(')
		push(ch);
		else if(check(ch))
		postfix[k++]=ch;
		else if(ch==')'){
			while(stack[top]!='(')
			{
			postfix[k++]=pop();
			}
			element=pop();                    
		}
		else{
			while(priority(stack[top])>=priority(ch))  
			postfix[k++]=pop();
			push(ch);
		}
	}
	while(stack[top]!='#'){
		postfix[k++]=pop();
	}
	postfix[k]='\0';
	printf("\n\nGiven Infix Expn: %s\nPostfix Expn: %s\n", infix, postfix);
	return 0;
}
