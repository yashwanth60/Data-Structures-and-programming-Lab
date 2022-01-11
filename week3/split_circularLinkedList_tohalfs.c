
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node * next;
}Node;
typedef struct CircularLinkedList
{
	struct Node * head;
}CLL;

Node *LinkNode(int data, Node *first)
{
	Node *m = (Node *) malloc(sizeof(Node));
	if (m == NULL)
	{
		return NULL;
	}
	m->data = data;
	m->next = first;
	return m;
}


CLL * getCLL()
{
	CLL * m = (CLL * ) malloc(sizeof(CLL));
	if (m == NULL)
	{
		return NULL;
	}
	m->head = NULL;
	return m;
}
void insert(CLL * m)
{   int value;
    scanf("%d",&value);
	Node * node = LinkNode(value, m->head);
	if ((m->head == NULL))
	{
		m->head = node;
		node->next = m->head;
	}
	else
	{
		Node * temp = m->head;
		while (temp->next != m->head)
		{
			temp = temp->next;
		}
		temp->next = node;
	}
}
void display(CLL * m)
{
	if ((m->head == NULL))
	{
		printf("Empty Linked List");
	}
	else
	{
		printf("\nLinked List Element :");
		Node * temp = m->head;
		while (temp != NULL)
		{

			printf(" %d ", temp->data);
			temp = temp->next;
			if ((temp == m->head))
			{

				return;
			}
		}
		printf("Not Circular Linked List");
	}
}
CLL * splitCLL(CLL * m)
{
	CLL * o = getCLL();
	if ((m->head == NULL))
	{
		printf("Empty Linked List");
	}
	else
	{
		Node * temp = m->head;
		Node * middle = NULL;
		while (temp != NULL && temp->next != m->head &&
               temp->next->next != m->head)
		{
			if ((middle == NULL))
			{
				middle = temp->next;
			}
			else
			{
				middle = middle->next;
			}

			temp = temp->next->next;
		}
		if ((middle == NULL))
		{
			if ((temp->next != m->head))
			{

				o->head = temp->next;

				o->head->next = o->head;

				m->head->next = temp;
			}
		}
		else
		{

			o->head = middle->next;

			middle->next = m->head;

			if ((temp->next == m->head))
			{

				temp->next = o->head;
			}
			else if ((temp->next->next == m->head))
			{

				temp->next->next = o->head;
			}
		}
	}
	return o;
}
int main()
{
    int n;
	CLL * c1 = getCLL();

	while(1)
    {

    printf("\n1.Insert number to Circular linked list:");
    printf("\n2.Display Two Halves of the Circular Linked List and Exit from program:");
    printf("\nEnter your Choice:\n");
    scanf("%d",&n);
    if(n==1){
     printf("\nEnter number to Circular linked list:");
	insert(c1);
    }
    else if(n==2)
    {

    printf("Before spliting: ");
	display(c1);
	printf("\nAfter spliting: \n");
	CLL * c2 = splitCLL(c1);
	printf("\nCircular Linked List1: ");
	display(c1);
	printf("\nCircular Linked List2: ");
	display(c2);
	exit(0);
    }
    else
    {

        printf("\nPlease select valid choice");
    }
    }

}
