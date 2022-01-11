
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

void display();
void push(int);
void pop();

int main()
{
    int n,c;
    while(1)
    {
        printf("\n\nStack operations using Linkedlist: \n1. Push \n2. Pop\n3. Display all elements of stack\n4. Exit");
        printf("\nEnter your Choice : ");
        scanf("%d", &c);
        if(c==1)
        {
             printf("\nEnter Item: ");
                scanf("%d", &n);
                push(n);

        }
        else if(c==2)
        {
            pop();
        }
        else if(c==3)
        {

            display();

        }
        else if(c==4)
        {
            exit(0);
        }
        else
        {
            printf("Invalid choice");

        }
    }

}

void push(int item)
{
    struct node *ptr = malloc(sizeof(struct node));
    ptr->data = item;
    ptr->next = top;
    top = ptr;
    printf("\n%d is added to stack",top->data);
}

void display()
{
    struct node *ptr;
    ptr = top;
    if(ptr!=NULL)
    {
    printf("Items present in the stack:");
    while (ptr != NULL)
    {
        printf("\n%d", ptr->data);
        ptr = ptr->next;
    }
    }
    else
    {
        printf("No item to display");
    }
}

void pop()
{
    if (top == NULL)
    {
        printf("\nStack is empty ");
    }
    else
    {
        struct node *temp;
        temp = top;
        top = top->next;
        printf("\n%d deleted", temp->data);
        free(temp);
    }
}
