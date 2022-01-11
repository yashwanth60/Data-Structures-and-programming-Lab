#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

struct node {
    char scl[3][10];
    struct node *next;
};
struct node *head = NULL;


void add()
{
    struct node *newnode,*temp;
    newnode = (struct node *)malloc(sizeof(struct node));


    if(newnode == NULL)
    {
        printf("\nOverflow\n");
    }

    else
    {

        if(head == NULL)
        {
            head = newnode;
            newnode -> next = head;
            for(int i=0;i<3;i++)
            {

               scanf("%s",newnode -> scl[i]);
            }
        }

        else
        {
            temp = head;
            while(temp -> next != head)
            {
                temp = temp -> next;
            }
            temp -> next = newnode;
            newnode -> next = head;
            for(int i=0;i<3;i++)
            {
               scanf(" %s",newnode->scl[i]);
            }
        }

        printf("\n Node is inserted to the List\n");
    }

}

void display()
{
    struct node *p;
    p =head;
    printf("\n Colors are \n");
    while(p->next != head)
    {
        for(int i=0;i<3;i++)
        {
        printf(" %s\t", p->scl[i]);
        }
        p = p->next;
        printf("\n");
    }
    int j=0;
while(j<3)
{
    printf(" %s\t ", p->scl[j]);
    j++;
}

    printf("\n");
}

void Displaysecond_string()
{
    struct node *p;
    p =head;
    while(p->next != head)
    {

        printf(" %s \n", p->scl[1]);

        p = p->next;

    }

    printf(" %s \n", p->scl[1]);

}


void Display_colorReplace()
{
   struct node *p;
   p =head;
   strcpy(p->scl[0],"color");
    while(p->next != head)
    {

        p = p->next;

    }

    strcpy(p->scl[0],"color");

    display();
}

int isMatch(){
    struct node *p;
    p =head;
    while(p->next != head)
    {

        if(strcmp(p->scl[2],p->next->scl[0])!=0)
        {
            return 0;
        }
        p = p->next;

    }
    return 1;
}


int main()
{
    int nodes;
    printf("Enter number of Nodes :");
    scanf("%d",&nodes);
    printf("Enter elements to Insert in to singly circular linked list: \n");
    for(int i=0; i<nodes ; i++)
    {
        add();

        printf("Please Enter Elements for next node:\n");
    }

	display();
	printf("\nSecond string colors in the  Linked list are: \n");
	Displaysecond_string();

	if(isMatch())
	{
	    printf("\n String Matching");
	}
	else
    {
        printf("\n String not Matching ");
    }

	Display_colorReplace();

	if(isMatch())
	{
	    printf("\n String Matching ");
	}
	else
    {
        printf("\n String not Matching ");
    }

	return 0;
}
