#include<stdio.h>
#include<stdlib.h>

#define MAX 100//Maximum number of elements


void push();
void pop();
void display();
int top=-1,stack[MAX];

void push()
{
int val;
if(top==MAX-1)
{
printf("\nStack is full");
}
else
{
printf("\nEnter element to push:");
scanf("%d",&val);
top=top+1;
stack[top]=val;
}
}

void pop()
{
if(top==-1)
{
printf("\nStack is empty");
}
else
{
printf("\nDeleted element is : %d",stack[top]);
top=top-1;
}
}

void display()
{
int i;
if(top==-1)
{
printf("\nStack is empty");
}
else
{
printf("\nItems present in the Stack : \n");
for(i=top;i>=0;--i)
printf("%d\n",stack[i]);
}
}



int main()
{
    int n,c;
    while(1)
    {
        printf("\n\nStack operations: \n1. Push \n2. Pop\n3. Display all elements of stack\n4. Exit ");
        printf("\nEnter your Choice : ");
        scanf("%d", &c);
        if(c==1)
        {
                push();

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
return 0;
}

