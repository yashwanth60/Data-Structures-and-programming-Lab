#include<stdio.h>
#include<stdlib.h>
int arr[16];
int value;
int front1=-1,front2=4,front3=7,front4=9;
int rear1=-1,rear2=4,rear3=7,rear4=9;
int max1=4,max2=7,max3=9,max4=15;
void insert(){
	//checking condition for overflow
	if(rear3 >= max3){
		if(rear2 >= max2){
			if(rear1 >= max1){
				if(rear4 >= max4){
					printf("Queue Overflow\n");
				}
				else{
					//insert value at desired location in queue
					insert_elements(&front4,&rear4,4);
				}
			}
			else{
				insert_elements(&front1,&rear1,1);
				}
			}
		else{
			insert_elements(&front2,&rear2,2);
		}
	}
	else{
		insert_elements(&front3,&rear3,3);
	}
}
//Insert values into queue
int insert_elements(int *front, int *rear, int index){
printf("Enter the value ");
if(scanf("%d",&value) == 1){
if(index == 4){
if(*front==9 && *rear==9){
	++(*front);
	arr[++(*rear)]=value;
	}
else{
	arr[++(*rear)]=value;
}
}
else if(index == 3){
if(*front==7 && *rear==7){
	++(*front);
	arr[++(*rear)]=value;
	}
else{
	arr[++(*rear)]=value;
}
}
else if(index==2){
	if(*front==4 && *rear==4){
	++(*front);
	arr[++(*rear)]=value;
	}
else{
	arr[++(*rear)]=value;
}
}
else if(index == 1){
	if(*front==-1 && *rear==-1){
	++(*front);
	arr[++(*rear)]=value;
	}
else{
	arr[++(*rear)]=value;
}
}
}
else{
	printf("Please Enter only Integers\n");
	exit(0);
}
}

void Arrange_Queue(int *front,int *rear,int index){
	int i;
	// printing the deleted element from queue
	printf("Deleted element is %d from the Queue %d\n",arr[*front],index);
	//pushing all values towards left in the queue after deletion to maintain queue
	for (i=*front; i < *rear; i++)
    {
        arr[i] = arr[i + 1];
    }
	(*rear)--;
	if(index==1){
    if (*rear == -1)
    *front = -1;
	}
	else if(index==2){
	if (*rear == 4)
    *front = 4;
	}
	else if(index == 3){
	if (*rear == 7)
    *front = 7;
	}
	else if(index==4){
	if (*rear == 9)
    *front = 9;

	}
}

void Delete(){
	//Underflow condition
	if(front4 == 9 && rear4==9){
		if(front1==-1 && rear1==-1){
			if(front2==4 && rear2==4){
				if(front3==7 && rear3==7)
				printf("Queue Underflow\n");
				else{
				//function called to delete and rearrange the elements
				Arrange_Queue(&front3,&rear3,3);
				}
			}
			else{
				Arrange_Queue(&front2,&rear2,2);
			}
		}
		else{
			Arrange_Queue(&front1,&rear1,1);
		}
	}
	else{
		Arrange_Queue(&front4,&rear4,4);
	}
}
//display the elements in the queue
void display(){
	int i;
	printf("Elements in Queue1 : ");
	//checking the base condition of queues
	if(front1 != -1){
	for(i=front1;i<=rear1;i++)
	printf("%d ",arr[i]);
	}
	printf("\nElements in Queue2 : ");
	if(front2 != 4){
	for(i=front2;i<=rear2;i++)
	printf("%d ",arr[i]);
}
	printf("\nElements in Queue3 : ");
	if(front3 != 7){
	for(i=front3;i<=rear3;i++)
	printf("%d ",arr[i]);
}
	printf("\nElements in Queue4 : ");
	if(front4 != 9){
	for(i=front4;i<=rear4;i++)
	printf("%d ",arr[i]);
}
	printf("\n");
}
int main(){
	int choice=0;
	while(choice!=4){
	printf("\n1.Insert in to Queue\n 2.Delete from Queue\n 3.Display\n 4.Exit\n Enter the choice:  ");
	if(scanf("%d",&choice)==1){
	if(choice==1)
	insert();
	else if(choice==2)
	Delete();
	else if(choice==3)
	display();
	else if(choice==4)
		break;
	else
	printf("Enter valid choice\n");
	}
	else{
		printf("Please Enter only integers\n");
		exit(0);
	}
}
}
