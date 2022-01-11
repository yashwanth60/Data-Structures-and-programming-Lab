
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int no_of_Values = 0;
int *arr=NULL;
void insert(int n)
{

 int pvalue,value,key,i,hkey,Double_hash;
 printf("\nEnter a value to insert into hash table:\n");
 scanf("%d",&value);
Double_hash = 7-(value %7);
 pvalue = value;
 hkey=abs(value)%n;
 for(i=0;i<n;i++)
    {
     key=(hkey+(i*Double_hash))%n;
     if(arr[key] == INT_MAX && key == 0)
     {
        arr[key]=pvalue;
        no_of_Values = no_of_Values + 1;
         break;
     }
      if(arr[key] == INT_MAX && key!= 0)
     {
        arr[key]=pvalue;
        no_of_Values = no_of_Values + 1;
         break;
     }
    }
    if(i == n)
     printf("\nValue cannot be inserted - HashTable was filled\n");
}
void search(int n)
{
 int value,key,i,hkey,Double_hash;
 printf("\nEnter Search Value:\n");
 scanf("%d",&value);
 Double_hash = 7-(value %7);
 hkey=value%n;
 for(i=0;i<n; i++)
 {
    key=(hkey+(i*Double_hash))%n;
    if(arr[key]==value)
    {
      printf("Value is found at index %d",key);
      break;
    }
  }
  if(i == n)
    printf("\n value is not found\n");
}
void h_delete(int n)
{
    int value,key,i,hkey,Double_hash;
 printf("\nEnter Value to delete:\n");
 scanf("%d",&value);
 Double_hash = 7-(value %7);
 hkey=value%n;
 for(i=0;i<n; i++)
 {
    key=(hkey+(i*Double_hash))%n;
    if(arr[key]==value)
    {
      arr[key] = INT_MAX;
      no_of_Values = no_of_Values - 1;
      break;
    }
  }
  if(i == n)
    printf("\n value is not found\n");

}
void display(int n)
{

  int i;
  printf("\nElements in the Hash table are :\n");
  for(i=0;i< n; i++)
  printf("\nAt index %d \t value =  %d",i,arr[i]);

}

int main()
{

    int n,i,choice;
    float Loadfactor;


	 printf("Enter Size of an Array:");
    scanf("%d",&n);
    if(n<10)
    {
        printf("\nPlease Enter Atleast Size of an Array Greater than or Equal to 10: ");
        scanf("%d",&n);
    }
    if(n<10)
    {
        printf("\nPlease Enter Atleast Size of an Array Greater than or Equal to 10");
        exit(0);
    }
	arr=(int*)malloc(n*sizeof(int));
	for(int i=0;i<n;i++)
    {
        arr[i]= INT_MAX;
    }

    while(choice!=5)
    {
    printf("\n Using Collision Resolution Technique : -Double Hashing\n 1. Inserting elements in the hash table\n 2. Searching elements from the hash table\n 3. Deleting an element from the hash table\n 4. Calculate the load factor of the hash table\n 5. Exit\n Enter Your Choice: ");
    if(scanf("%d",&choice)==1)
    {
    if(choice==1)
    {
        insert(n);
        display(n);

    }
    else if(choice==2)
    {
        search(n);
    }
    else if(choice==3)
    {
        h_delete(n);
         display(n);

    }
    else if(choice==4)
    {
        Loadfactor = (float)no_of_Values/n;
        display(n);
        printf("\nno_of_Values:%d\n",no_of_Values);
        printf("\nLoad Factor of the Hash table : %f\n ",Loadfactor);
    }
    else if(choice==5)
    {
        exit(0);
    }
    else{
        printf("Invalid choice!");
    }

    }
    else{
        printf("Enter Numbers from 1 to 5");
        exit(0);
    }
    }

}

