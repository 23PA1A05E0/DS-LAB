#include<stdio.h>
#include<stdlib.h>

struct Queue {
    int data;
    struct Queue *next;
} ;

struct Queue *front=NULL;
struct Queue *Rear=NULL;

void display() {
    struct Queue *temp;
    temp=malloc(sizeof(struct Queue)) ;
    temp=front;
    if(front==NULL||Rear==NULL) {
        printf("Queue is an empty");
    }
    else {
        printf("\n Elements in Queue is:");
        while(temp!=NULL) {
            printf("%d ", temp->data);
            temp=temp->next;
        }
    }
    printf("\n");
}

struct Queue* insert(int data) {
    struct Queue *newP=NULL;
    newP=malloc(sizeof(struct Queue)) ;
    newP->data=data;
    newP->next=NULL;
    if(front==NULL && Rear==NULL) {
        front=Rear=newP;
    }
    else {
        Rear->next =newP;
        Rear=newP;
    }
}

int  delete() {
    if(front==NULL && Rear==NULL) {
        printf("Queue is empty ");
        return 0;
    }
    else {
        int data;
        struct Queue *temp;
        temp=front;
        data=temp->data;
        front=front->next;
        free(temp);
        temp=NULL;
        return data;
    }
}

int main() {
    {
        int choice, element, data;
        while (1)
        {
            printf("\n1.Insert element to queue \n");
            printf("2.Delete element from queue \n");
            printf("3.Display all elements of queue \n");
            printf("4.Quit \n\n");
            printf("Enter your choice : ");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                printf("enter the element to insert:");
                scanf("%d", &element);
                insert(element);
                break;
            case 2:
                data=delete();
                printf("\nRemoved element is-------- %d\n", data);
                break;
            case 3:
                display();
                break;
            case 4:
                exit(1);
            default:
                printf("Wrong choice \n");
            }
        }
    }

}
