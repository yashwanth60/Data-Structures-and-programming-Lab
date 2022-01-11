#include<stdio.h>
#include<conio.h>

struct Node
{
   int data;
   struct Node *next;
};

struct Node *front = NULL,*rear = NULL;

void enqueue(int);
void dequeue();
void display();

void main()
{
    int c,item;
    while (1)
    {
        printf("\n\nQueue operations Using Linked List:");
        printf("\n1.Enqueue \n");
        printf("2.Dequeue \n");
        printf("3.Display all elements of queue \n");
        printf("4.Quit from program \n");
        printf("\nEnter your choice : ");
        scanf("%d", &c);
        if(c==1)
        {
            printf("\nEnter your item to queue: \n");
                scanf("%d",&item);
                enqueue(item);
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
void enqueue(int value)
{
    struct Node *newnode;
    newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode -> data = value;
    newnode -> next = NULL;

    if(front == NULL)
        front = rear = newnode;
    else
    {
        rear -> next = newnode;
        rear = newnode;
    }
    printf("\n Item inserted in Queue: \n");
}

void dequeue()
{
    if(front == NULL)
        printf("\n Queue is Empty\n");
    else
    {
        struct Node *temp = front;
        front = front -> next;
        printf("\n Deleted Item is: %d\n", temp->data);
        free(temp);
    }
}

void display()
{
    if(front == NULL)
        printf("\n Queue is Empty\n");
    else
    {
        printf("Items in Queue: \n");
        struct Node *temp = front;
        while(temp->next != NULL)
        {
            printf("%d --> ",temp->data);
            temp = temp -> next;
        }
        printf("%d \n",temp->data);
   }
}



