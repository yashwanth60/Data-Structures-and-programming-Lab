#include<stdio.h>
#include<stdlib.h>

struct node
{
int data;
struct node *next;
}*p;

struct node *n;

//Function to Add the items at beginning of the List
void addbeg(int num)
{
struct node *temp;
temp=(struct node *)malloc(sizeof(struct node));
temp->data=num;
if(p==NULL)
{
p=temp;
p->next=NULL;
}
else
{
temp->next=p;
p=temp;
}
}

//Function to Add the items at end of the List

void addend(int num)
{
struct node *temp,*r;

temp=(struct node *)malloc(sizeof(struct node));
temp->data=num;
r=(struct node *)p;
if(p==NULL)
{
p=temp;
p->next=NULL;
}
else
{
while(r->next!=NULL)
r=r->next;
r->next=temp;
r=temp;
r->next=NULL;
}
}
int count()
{
struct node *n;
int c=0;
n=p;
while(n!=NULL)
{
n=n->next;
c++;
}
return(c);
}



//Function to Display the items of the List
void display(struct node *r)
{
r=p;
if(r==NULL)
{
printf("No element in the list");
return;
}
while(r!=NULL)
{
printf("->%d",r->data);
r=r->next;
}
printf("\n");
}

//Function to calculate decimal value from binary values
void Calculate_Decimal_value(struct node *r)
{
    int num;
r=p;
if(r==NULL)
{
printf("No element in the list");
return;
}
int btod = 0,bnum;
int c = count();
//printf("c:%d",c);
int i=c-1;
while(r!=NULL && i>=0)
{
    bnum = r->data;
    btod = btod + bnum*(pow(2,i));

printf("->%d",r->data);
r=r->next;
--i;
}
printf("\nDecimal value for given binary number :%d",btod);
}

void main()
{
        int i;
        p=NULL;
        while(1)
        {
                printf("\n1.Insert a Binary number at beginning");
                printf("\n2.Insert a Binary number at last");
                printf("\n3.Display the Binary numbers");
                printf("\n4.Calculate Decimal value and Exit from program");
                printf("\n\nEnter your choice : ");
                scanf("%d",&i);
                if(i == 1)
                {
                   int num;
                   printf("please  enter number:");
                   scanf("%d",&num);
                   if(num==1 || num==0)
                   {
                       addbeg(num);
                   }
                   else{
                    printf("Please enter 0 or 1");
                   }


                }
        else if(i == 2)
              {
                   int num;
                    printf("please enter number:");
                    scanf("%d",&num);
                    if(num==1 || num==0)
                   {
                       addend(num);
                   }
                   else{
                    printf("Please enter 0 or 1");
                   }

              }
             else if(i==3)
              {
                  printf("The elements in list are :\n ");
                 display(n);

              }


              else if (i==4){

                    Calculate_Decimal_value(n);
              exit(0);


              }
              else{
                printf("please enter valid choice:");
              }

}
}


