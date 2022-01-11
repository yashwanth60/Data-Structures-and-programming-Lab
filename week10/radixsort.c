#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int getMax(int arr[], int n) {
  int max = arr[0];

  for (int i = 1; i < n; i++)
    if (arr[i] > max)
      max = arr[i];
  return max;
}

void countingSort(int array[], int n, int place) {
  int output[n + 1];
  int max = (array[0] / place) % 10;

  for (int i = 1; i < n; i++) {
    if (((array[i] / place) % 10) > max)
      max = array[i];
  }
  int count[max + 1];

  for (int i = 0; i < max; ++i)
    count[i] = 0;

  // Calculate count of elements
  for (int i = 0; i < n; i++)
    count[(array[i] / place) % 10]++;

  // Calculate cumulative count
  for (int i = 1; i < 10; i++)
    count[i] += count[i - 1];

  // Place the elements in sorted order
  for (int i = n - 1; i >= 0; i--) {
    output[count[(array[i] / place) % 10] - 1] = array[i];
    count[(array[i] / place) % 10]--;
  }

  for (int i = 0; i < n; i++)
    array[i] = output[i];
}

// Main function to implement radix sort
void radixsort(int array[], int n) {
  int max = getMax(array, n);

  // Apply counting sort to sort elements based on place value.
  for (int place = 1; max / place > 0; place *= 10)
    countingSort(array, n, place);
}


int main()
{
    int arr[30],n;

    printf("Enter the size of an Array:");
    scanf("%d",&n);
    printf("\nEnter numbers into an Array:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("\n List of numbers before Radix sort: \n");
    for(int i = 0; i<n; i++)
    {
        printf("%d\t", arr[i] );
    }
    radixsort(arr, n);

    printf("\n\nList of numbers after Radix sort: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n\n");
    return 0;
}
