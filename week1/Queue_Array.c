#include <stdio.h>
#define MAX 50

void enqueue();
void dequeue();
void display();
int queue[MAX];
int rear = - 1;
int front = - 1;
main()
{
    int c;
    while (1)
    {
        printf("\n\nQueue operations:");
        printf("\n1.Enqueue \n");
        printf("2.Dequeue \n");
        printf("3.Display all elements of queue \n");
        printf("4.Quit from program \n");
        printf("\nEnter your choice : ");
        scanf("%d", &c);
        if(c==1)
        {
            enqueue();
        }
        else if(c==2)
        {
            dequeue();
        }
        else if(c==3)
        {
         display();
        }
        else if(c==4)
        {
            exit(1);
        }
        else{
            printf("Invalid choice");
        }

    }
}

void enqueue()
{
    int item;
    if (rear == MAX - 1)
    printf("Queue Overflow \n");
    else
    {
        if (front == - 1)

        front = 0;
        printf("Insert the element in to queue : ");
        scanf("%d", &item);
        rear = rear + 1;
        queue[rear] = item;
    }
}

void dequeue()
{
    if (front == - 1 || front > rear)
    {
        printf("Queue is Empty \n");
        return ;
    }
    else
    {
        printf("Element deleted from queue is : %d\n", queue[front]);
        front = front + 1;
    }
}

void display()
{
    int i;
    if (front == - 1)
        printf("Queue is empty \n");
    else
    {
        if(front>rear)
        {


        printf("Queue is empty\n");

        }
        else{
        printf("Items in Queue: \n");
        for (i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
        }
    }
}
