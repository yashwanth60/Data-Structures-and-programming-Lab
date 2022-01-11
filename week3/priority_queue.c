#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int arr[40];
char name[40][20];
int front=-1, rear=-1,size;

void insert_name_score()
{
    if (rear < size - 1)
    {
    	char student_name[25];
    	int marks;
    	printf("Enter Student name : ");
    	scanf("%s",student_name);
    	printf("Enter Student Gate score : ");
    	if(scanf("%d",&marks)==1){
    	if(marks<0 || marks >=1000)
        {
		printf("Enter valid gate score between 0 to 1000 \n");
        }
		else{
    if ((front == -1) && (rear == -1))
    {

        ++rear;
        strcpy(name[rear],student_name);
        arr[rear]=marks;
         ++front;
    }
    else{
    int i,j;
    for (i = 0; i <= rear; i++)
    {
        if (marks > arr[i])
        {
            for (j = rear + 1; j > i; j--)
            {
                arr[j] = arr[j - 1];
                strcpy(name[j],name[j-1]);
            }
            arr[i] = marks;
            strcpy(name[i],student_name);
            rear++;
            return;
        }
    }
    arr[i] = marks;
    strcpy(name[i],student_name);
    rear++;
}
}
	}
	else{
		printf("Invalid input . Please Enter Only integers\n");
		exit(0);
	}
}
else
    {
        printf("Queue overflow\n");
    }
}

void Delete()
{
    int i;
    if ((front==-1) && (rear==-1))
    {
        printf("Queue underflow\n");
    }
    else{
    printf("%s ---->  %d\n",name[0],arr[0]);
    for (i=0; i < rear; i++)
    {
        arr[i] = arr[i + 1];
        strcpy(name[i],name[i+1]);
    }
	rear--;
    if (rear == -1)
    front = -1;
}
}


void display()
{
    if ((front == -1) && (rear == -1))
    {
        printf("Queue is empty\n");
    }
    else{
    int i;
	for (i=front;i <= rear; i++)
    {
        printf("%s ---->  %d\n",name[i],arr[i]);
    }
}
}


void main()
{
    int choice=0;
    printf("Enter the size of Queue: ");
    if(scanf("%d",&size) == 1){
    while (choice!=4)
    {
    	printf("\n1.Insert \n2.Delete \n3.Display \n4.Exit: \nEnter your choice :");
        if(scanf("%d", &choice)==1){
        if(choice==1)
            insert_name_score();
        else if(choice== 2)
            Delete();
        else if(choice== 3)
            display();
        else if(choice==4)
            break;
        else
        	printf("Enter valid choice\n");
        }
        else{
        	printf("Invalid input . Please Enter Only integers\n");
        	exit(0);
		}
}
}
else{
	printf("Invalid input . Please Enter Only integers\n");
	exit(0);
}
}
