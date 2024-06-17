
// C Program to Implement a Queue using an Array
#include <stdio.h>

#define MAX 50

void insert_front();
void insert_rear();
void delete_front();
void delete_rear();
void display();
int queue_array[MAX];
int rear = - 1;
int front = - 1;
int main()
{
    int choice;
    while (1)
    {
        printf("\n1.Insert element to queue at _rear\n");
        printf("\n2.Insert element to queue at front\n");
        printf("3.Delete element from queue at front\n");
        printf("4.Delete element from queue at rear\n");
        printf("5.Display all elements of queue \n");
        printf("6.Quit \n\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert_rear();
            break;
        case 2:
            insert_front();
            break;
        case 3:
            delete_front();
            break;
        case 4:
            delete_rear();
            break;
        case 5:
            display();
            break;
        case 6:
            exit(1);
        default:
            printf("Wrong choice \n");
        }
    }
}

void insert_rear()
{
    int add_item;
    if (rear == MAX - 1)
        printf("\nQueue Overflow \n\n");
    else
    {
        if (front == -1)
            front = 0;
        printf("Inset the element in queue : ");
        scanf("%d", &add_item);
        rear = rear + 1;
        queue_array[rear] = add_item;
    }
}

void insert_front()
{
    int add_item;
    if (front==0)
        printf("\nInsertion is not possible\n\n");
    else if(front==-1)
    {
        front = rear=0;
        printf("Inset the element in queue : ");
        scanf("%d", &add_item);
        queue_array[front] = add_item;
    }
}


void delete_front()
{
    if (front == - 1 || front > rear)
    {
        printf("Queue Underflow \n");
        return ;
    }
    else
    {
        if(rear==front) {
            printf("Element deleted from queue is : %d\n", queue_array[front]);
            front=rear=-1;
        }
        else {
            printf("Element deleted from queue is : %d\n", queue_array[front]);
            front = front + 1;
        }
    }
}
void delete_rear()
{
    if (rear == - 1 )
    {
        printf("Queue Underflow \n");
        return ;
    }
    else if(rear==front) {
        printf("Element deleted from queue is : %d\n", queue_array[front]);
        front=rear=-1;
    }
    else {
        printf("Element deleted from queue is : %d\n", queue_array[rear]);
        rear = rear-1;
    }
}



void display()
{
    int i;
    if (front == - 1)
        printf("Queue is empty \n");
    else
    {
        printf("Queue is : \n");
        for (i = front; i <= rear; i++)
            printf("%d ", queue_array[i]);
        printf("\n");
    }
}