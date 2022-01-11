#include <stdio.h>
#include <stdlib.h>
#include<time.h>

void swap(int *a, int *b) {
 int t = *a;
 *a = *b;
 *b = t;
}

int *swapFun(int *Array, int n, int swapCount)
{
    for(int i=0;i<swapCount && i < n-1 ;i++)
    {
        int temp = Array[i];
        Array[i] = Array[i+1];
        Array[i+1] = temp;
    }
    return Array;
}

int partition_pivot_last(int array[], int low, int high) {
 int pivot = array[high];
 int i = (low - 1);

 for (int j = low; j < high; j++) {
  if (array[j] < pivot) {
   swap(&array[++i], &array[j]);
  }
 }

 swap(&array[i + 1], &array[high]);
 return (i + 1);
}

int partition_pivot_first(int array[], int low, int high) {
 int pivot = array[low];
 int i = (low + 1);

 for (int j = low + 1; j <= high; j++) {
  if (array[j] < pivot) {
   if (j != i) {
    swap(&array[i], &array[j]);
   }
   i++;
  }
 }

 swap(&array[i - 1], &array[low]);
 return (i - 1);
}

int partition_pivot_random(int array[], int low, int high) {
 int pivot;
 int n = rand();
 pivot = low + n % (high - low + 1); // Randomizing the pivot
 return partition_pivot_last(array, low, high);
}

int partition_pivot_median(int array[], int low, int high) {

 int pivot;
 int mid = (low + high) / 2;
 if (array[mid] < array[low])
  swap(&array[mid], &array[low]);
 if (array[high] < array[low])
  swap(&array[high], &array[low]);
 if (array[high] < array[mid])
  swap(&array[high], &array[mid]);
 swap(&array[mid], &array[high-1]);

 pivot = array[high-1];

 return partition_pivot_last(array, low, high);
}

void quickSort_Pivot_First(int array[], int low, int high) {
 if (low < high) {
  int pi = partition_pivot_first(array, low, high);

  quickSort_Pivot_First(array, low, pi - 1);

  quickSort_Pivot_First(array, pi + 1, high);
 }
}

void quickSort_Pivot_Random(int array[], int low, int high) {
 if (low < high) {
  int pi = partition_pivot_random(array, low, high);

  quickSort_Pivot_Random(array, low, pi - 1);

  quickSort_Pivot_Random(array, pi + 1, high);
 }
}

void quickSort_Pivot_Median(int array[], int low, int high) {
 if (low < high) {
  int pi = partition_pivot_median(array, low, high);

  quickSort_Pivot_Median(array, low, pi - 1);

  quickSort_Pivot_Median(array, pi + 1, high);
 }
}
int medianThree(int a, int b, int c) {
    if ((a > b) ^ (a > c))
        return a;
    else if ((b < a) ^ (b < c))
        return b;
    else
        return c;
}

int partition_pivot_median_nby4(int array[], int low, int high) {

 int pivot;
 int i = low + 1;
int mid = (low+high-1)/2;
int nleft = (high-low)/4 + low;
int nright = (3*(high-low))/4+ low;
 pivot = medianThree(array[nleft],array[pivot],array[nright]);
 if (array[mid] < array[low])
  swap(&array[mid], &array[low]);
 if (array[high] < array[low])
  swap(&array[high], &array[low]);
 if (array[high] < array[mid])
  swap(&array[high], &array[mid]);
 swap(&array[mid], &array[high-1]);
 pivot = array[high-1];

 return partition_pivot_last(array, low, high);
}

void quickSort_Pivot_Median_nby4(int array[], int low, int high) {
 if (low < high) {
  int pi = partition_pivot_median_nby4(array, low, high);

  quickSort_Pivot_Median_nby4(array, low, pi - 1);

  quickSort_Pivot_Median_nby4(array, pi + 1, high);
 }
}


int *Rarray(int n, int *Array)
{
    int j;
    for(j=0;j<n;j++)
       Array[j]=rand()%1000000;

    printf("\n Elements of the array::");
    for(int i=0;i<n;i++)
    {
     printf("\t %d",Array[i]);
    }

    return Array;
}

int *bubble_sort(int *Arr, int n)
{
    int i,j,temp;
    for (i = 0; i < n; i++){
        for (j = i + 1; j < n; j++){
            if (Arr[i] > Arr[j])
            { temp =  Arr[i];
              Arr[i] = Arr[j];
              Arr[j] = temp;
      }
     }
    }
    return Arr;
}


int main(void) {
 int size,choice,l=0,choose;
 double Time;
 while(1){
    printf("Enter the size of Array : ");
    scanf("%d",&size);
    printf("\n1. Random number of Integers in the range of 10^k(k=4,5,6,7)\n2. Sorted array of (1)\n3. Almost sorted array of (1)\n4.Quit\n");
   printf("\n Enter your choice (between 1 to 4) : ");
   scanf("%d", &choice);

   int *ArrayPointer;
   int Array[size];

   if(choice ==1)
   {
    ArrayPointer = Rarray(size, Array);
    printf("\n1. Quicksort pivot as first \n2. quicksort pivot as random\n3. quicksort pivot as Median\n4. quicksort pivot as Median of {n/4th element, middle element, 3n/4th element}\n");
    printf("Enter your choice: ");
    scanf("%d",&choose);
     if(choose == 1)
   {
   clock_t start,end;
   start = clock();

   quickSort_Pivot_First(ArrayPointer, l, size - 1);

   end = clock();
   Time = ((double)(end - start))/CLOCKS_PER_SEC;
   }

   else if(choose == 2)
   {
   clock_t start,end;
   start = clock();

   quickSort_Pivot_Random(ArrayPointer, l, size - 1);

   end = clock();
   Time = ((double)(end - start))/CLOCKS_PER_SEC;
   }

   else if(choose == 3)
   {
   clock_t start,end;
   start = clock();

   quickSort_Pivot_Median(ArrayPointer, l, size - 1);

   end = clock();
   Time = ((double)(end - start))/CLOCKS_PER_SEC;
   }

    else if(choose == 4)
   {
   clock_t start,end;
   start = clock();

   quickSort_Pivot_Median(ArrayPointer, l, size - 1);

   end = clock();
   Time = ((double)(end - start))/CLOCKS_PER_SEC;
   }
}


    else if (choice ==2)
   {
      ArrayPointer = Rarray(size, Array);

      ArrayPointer =  bubble_sort(ArrayPointer, size);

      printf("\n1. Quicksort pivot as first \n2. quicksort pivot as random\n3. quicksort pivot as Median\n4. quicksort pivot as Median of {n/4th element, middle element, 3n/4th element} \n");
    printf("Enter your choice: ");
    scanf("%d",&choose);
     if(choose == 1)
   {
   clock_t start,end;
   start = clock();

   quickSort_Pivot_First(ArrayPointer, l, size - 1);

   end = clock();
   Time = ((double)(end - start))/CLOCKS_PER_SEC;
   }

   else if(choose == 2)
   {
   clock_t start,end;
   start = clock();

   quickSort_Pivot_Random(ArrayPointer, l, size - 1);

   end = clock();
   Time = ((double)(end - start))/CLOCKS_PER_SEC;
   }

   else if(choose == 3)
   {
   clock_t start,end;
   start = clock();

   quickSort_Pivot_Median(ArrayPointer, l, size - 1);

   end = clock();
   Time = ((double)(end - start))/CLOCKS_PER_SEC;
   }

    else if(choose == 4)
   {
   clock_t start,end;
   start = clock();

   quickSort_Pivot_Median(ArrayPointer, l, size - 1);

   end = clock();
   Time = ((double)(end - start))/CLOCKS_PER_SEC;
   }
}

    else if (choice ==3)
   {
      ArrayPointer = Rarray(size, Array);

      ArrayPointer =  bubble_sort(ArrayPointer, size);
      int pairCount = (size*(size-1))/2;
      int swapCount =(int)( 0.01 * (float)pairCount);
      ArrayPointer = swapFun(ArrayPointer, size,swapCount);

      printf("\n1. Quicksort pivot as first \n2. quicksort pivot as random\n3. quicksort pivot as Median\n4. quicksort pivot as Median of {n/4th element, middle element, 3n/4th element} \n");
    printf("choose Any one ");
    scanf("%d",&choose);
     if(choose == 1)
   {
   clock_t start,end;
   start = clock();

   quickSort_Pivot_First(ArrayPointer, l, size - 1);

   end = clock();
   Time = ((double)(end - start))/CLOCKS_PER_SEC;
   }

   else if(choose == 2)
   {
   clock_t start,end;
   start = clock();

   quickSort_Pivot_Random(ArrayPointer, l, size - 1);

   end = clock();
   Time = ((double)(end - start))/CLOCKS_PER_SEC;
   }

   else if(choose == 3)
   {
   clock_t start,end;
   start = clock();

   quickSort_Pivot_Median(ArrayPointer, l, size - 1);

   end = clock();
   Time = ((double)(end - start))/CLOCKS_PER_SEC;
   }

    else if(choose == 4)
   {
   clock_t start,end;
   start = clock();

   quickSort_Pivot_Median(ArrayPointer, l, size - 1);

   end = clock();
   Time = ((double)(end - start))/CLOCKS_PER_SEC;
   }
}

   else if(choice == 4)
   {
       break;
   }

 printf("\nsorted list is : \n");
 for (int i = 0; i < size; i++)
  printf("%d  ", ArrayPointer[i]);
  printf("\n");

  printf("\n Quick_sort() took %f seconds to execute \n",Time);

 }
}
