//heap sort program
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX 100
int arr[MAX]={0};
int flag=0;
int count=0;



void swap(int *x, int *y)
{
	int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void Heapify_Min(int arr[], int n, int i)
{

  int min = i;
  int l = (2 * i) + 1;
  int r = (2 * i)+ 2;

  if (l < n && arr[l] < arr[min])
  {
  	 min = l;
  }


  if (r < n && arr[r] < arr[min])
  {
  	 min = r;
  }


    if (min != i)
	{
      swap(&arr[i], &arr[min]);
      Heapify_Min(arr, n, min);
  	}
}


void Heapify_Max(int arr[], int n, int i)
{
  int max = i;
  int l = ( 2 * i) + 1;
  int r = (2 * i )+ 2;

  if (l < n && arr[l] > arr[max])
 	{
	 	max = l;
	}

  if (r < n && arr[r] > arr[max])
  {
  	    max = r;
  }

    if (max != i)
	{
      swap(&arr[i], &arr[max]);
      Heapify_Max(arr, n, max);
  	}
}


void display(int array[],int n)
{
	int i;
	printf("\n Array elements are: ");
	for(i=0;i<n;i++)
	{
		printf("  %d",array[i]);
	}
	printf("\n\n");
}



void Heapify()
{
	int n,size,i;
	printf("\n Enter Size of an Array : ");
	scanf("%d",&n);
	count = n;
	printf("\n Enter Elements in to Array: ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	display(arr,n);

	if(flag==1)
	{
		//Max heap
	    for (i = n / 2 - 1; i >= 0; i--)
	    {
	    	Heapify_Max(arr, n, i);
		}
		printf("\n Max heap build\n");
	}
	else if (flag == 2)
	{
		//Min heap
		for (i = n / 2 - 1; i >= 0; i--)
	    {
	    	Heapify_Min(arr, n, i);
		}
		printf("\n Min heap build\n");

	}
}



void insert()
{
	int key,i,j,n;
	printf("\n Enter key value to insert in to heap: ");
	scanf("%d",&key);
	n=count;
	arr[n]=key;
	count++;
	n++;
	if(flag==1)
	{
		//Max heap
	    for (i = n / 2 - 1; i >= 0; i--)
	    {
	    	Heapify_Max(arr, n, i);
		}
	}
	else if(flag==2)
	{
		//Min heap
		for (i = n / 2 - 1; i >= 0; i--)
	    {
	    	Heapify_Min(arr, n, i);
		}
	}
    printf("\n %d was inserted\n\n",key);


}





void heapsort()
{
	int i,j,n;
	n=count;
	int arr2[n];
	for(i=0;i<n;i++)
	{
		arr2[i]=arr[i];
	}
	    // Heap sort

	if(flag==1)
	{
		//Max heap
		for (i = n - 1; i >= 0; i--)
		{
	      swap(&arr2[0], &arr2[i]);


	      Heapify_Max(arr2, i, 0);
	    }
	}
	else
	{
		//Min heap
		for (i = n - 1; i >= 0; i--)
		{
	      swap(&arr2[0], &arr2[i]);

	      // Heapify root element
	      Heapify_Min(arr2, i, 0);
	    }

	}
    display(arr2,n);
}


void del()
{
	int i,j,key,n,index,k=0;
	printf("\n Enter value to delete: ");
	scanf("%d",&key);
	n=count;
	for(i=0;i<n;i++)
	{
		if(arr[i]==key)
		{
			k=1;
			index=i;
			break;
		}
	}
	if(k==0)
	{
		printf("\n Element not found\n\n");
		return;
	}
	swap(&arr[index],&arr[n-1]);
	arr[n-1]=0;
	count--;
	n--;
	if(flag==1)
	{
		//Max heap
	    for (i = n / 2 - 1; i >= 0; i--)
	    {
	    	Heapify_Max(arr, n, i);
		}
	}
	else
	{
		//Min heap
		for (i = n / 2 - 1; i >= 0; i--)
	    {
	    	Heapify_Min(arr, n, i);
		}
	}
    printf("\n %d was deleted from heap\n\n",key);

}


void main()
{
	int i,choice,choice1,check=0,val;
	printf("\n Heap sort Algorithm \n");
	printf("\n 1.Use Max heapify");
	printf("\n 2.Use Min heapify");
	printf("\n\n Enter Your choice: ");
	val = scanf("%d",&choice);

	if(val!=1)
	{
		printf("\n Invaid choice");
		exit(0);
	}
	if(choice==1 || choice==2)
	{
		flag=choice;
		while(1)
		{
			if(choice==1)
			{
				printf("\n\n Max heapify");
			}
			else if (choice == 2)
			{
				printf("\n\n Min heapify");
			}
			printf("\n 1. Build heap by inserting Integers");
			printf("\n 2. Insert a key in to heap ");
			printf("\n 3. Delete function ");
			printf("\n 4. Sort function");
			printf("\n 5. Exit");
			printf("\n\n Enter Your choice: ");
			scanf("%d",&choice1);
			if(choice1 == 1)
			{
				//build heap
				if(check==0)
				{
					Heapify();
					check=1;
				}
				else
				{
					printf("\n Heap already build\n");
				}
			}
			else if(choice1 == 2)
			{
				//insert a key
				if(check==0)
				{
					printf("\n Heap Was not build \n\n");
				}
				else
				{
					insert();
				}
			}
			else if(choice1==3)
			{
				//delete
				if(check==0)
				{
					printf("\n Heap Was not build\n\n");
				}
				else
				{
					del();
				}

			}
			else if(choice1==4)
			{
				//sort function
				if(check==0)
				{
					printf("\n Heap was not build\n\n");
				}
				else
				{
					heapsort();
				}
			}
			else if(choice1==5)
			{
				break;
			}
			else
			{
				printf("\n Invalid input. Try again!");
			}
		}
	}
	else
	{
		printf("\n Invalid choice. !");
	}

}
