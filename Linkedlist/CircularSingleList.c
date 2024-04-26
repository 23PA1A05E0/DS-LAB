#include<stdio.h>
#include<stdlib.h>


struct node* add_at_beginning(struct node *tail, int data);
struct node* add_at_end(struct node *tail, int data);
struct node* delete_at_beginning(struct node *tail);

struct node {
    int data;
    struct node *next;
};


void dispaly(struct node *tail) {
    struct node *ptr;
    ptr=tail->next;
    do {
        printf("%d ", ptr->data);
        ptr=ptr->next;
    }
    while(ptr!=tail->next) ;



}
struct node* add_at_beginning(struct node *tail, int data) {
    if(tail==NULL) {
        printf("List is aready empty");
    }
    struct node *temp;
    temp=malloc(sizeof(struct node)) ;
    temp->data=data;
    temp->next=NULL;
    temp->next=tail->next;
    tail->next=temp;
    //  tail=temp;
    //return temp;

}


struct node* add_at_position (struct node *tail, int data, int pos) {

    if(tail==NULL) {
        printf("List is aready empty");
    }

    if(pos==1) {
        add_at_beginning(tail, data) ;
        return tail;
    }

    struct node *newp, *ptr;
    newp=malloc(sizeof(struct node)) ;
    ptr=tail->next;
    newp->data=data;
    newp->next=NULL;
    pos--;
    while(pos>1) {
        ptr=ptr->next;
        pos--;
    }

    newp->next=ptr->next;
    ptr->next=newp;
    //return tail;
    
    if(ptr==tail) 
        tail=newp;
        return tail;
    

}





struct node* add_at_end(struct node *tail, int data) {
    if(tail==NULL) {
        printf("List is aready empty");
    }
    struct node *temp;
    temp=malloc(sizeof(struct node) );
    temp->data=data;
    temp->next=NULL;
    temp->next=tail->next;
    tail->next=temp;
    tail=temp;
    return tail;

}

struct node* delete_at_position(struct node* tail, int pos) {
    if(tail==NULL) {
        printf("List is aready empty");
    }
    if(tail->next==tail) {
        tail=NULL;
        free(tail) ;
        return tail;
    }
    if(pos==1) {
        delete_at_beginning(tail);
    }
    else {
        struct node *ptr, *temp ;
        ptr=tail->next;
        while(pos>2) {
            ptr=ptr->next;
            pos--;
        }
        temp=ptr->next;
        ptr->next=temp->next;
        free(temp) ;

        return tail;
    }
}


struct node* delete_at_beginning(struct node *tail) {
    struct node *temp, *ptr;
    temp=tail->next;
    ptr=temp->next;
    tail->next=ptr;
    free(temp) ;
}

struct node* delete_at_end(struct node *tail) {
    if(tail==NULL) {
        printf("List is already empty");
    }
    struct node *temp;
    temp=tail->next;
    if(tail->next==tail) {
        tail=NULL;
        free(tail) ;
        return tail;
    }
    while(temp->next!=tail)
    {
        temp=temp->next;
    }
    temp->next=tail->next;

    free(tail) ;
    tail=temp;
    return tail;
}

int main() {
    struct node *tail;
    tail=(struct node*) malloc(sizeof(struct node*)) ;
    tail->data=20;
    tail->next=tail;
    add_at_beginning(tail, 10);
    tail=add_at_end(tail, 30);
    tail=add_at_end(tail, 40);
    // delete_at_beginning(tail) ;
    tail= add_at_position(tail,50, 5) ;
    dispaly(tail) ;

}
