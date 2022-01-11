
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <math.h>

struct Stack
{
      int top;
      int *arr;
      int max;
};

struct Stack* Stack_create(int max)
{
      struct Stack* stackTOH = (struct Stack*)malloc(sizeof(struct Stack));
      stackTOH -> max = max;
      stackTOH -> top = -1;
      stackTOH -> arr = (int*)malloc(stackTOH -> max*sizeof(int));
      return stackTOH;
}

int isFull(struct Stack* stackTOH)
{
      return (stackTOH->top == stackTOH->max - 1);
}

int isEmpty(struct Stack* stackTOH)
{
      return (stackTOH->top == -1);
}

void display_shift(char fromPole, char toPole, int disk)
{
      printf("Move Disk %d from \'%c\' to \'%c\'\n", disk, fromPole, toPole);
}

void push_item(struct Stack *stackTOH, int item)
{
      if(isFull(stackTOH))
      {
            return;
      }
      stackTOH -> arr[++stackTOH -> top] = item;
}

int pop_item(struct Stack* stackTOH)
{
      if(isEmpty(stackTOH))
      {
            return INT_MIN;
      }
      return stackTOH -> arr[stackTOH -> top--];
}

void Disk_shift(struct Stack *sourcePole, struct Stack *destPole, char source, char dest)
{
      int pole1 = pop_item(sourcePole);
      int pole2 = pop_item(destPole);
      if(pole1 == INT_MIN)
      {
            push_item(sourcePole, pole2);
            display_shift(dest, source, pole2);
      }
      else if(pole2 == INT_MIN)
      {
            push_item(destPole, pole1 );
            display_shift(source, dest, pole1);
      }
      else if(pole1 > pole2)
      {
            push_item(sourcePole, pole1);
            push_item(sourcePole, pole2);
            display_shift(dest, source, pole2);
      }
      else
      {
           push_item(destPole, pole2);
            push_item(destPole, pole1);
            display_shift(source, dest, pole1);
      }
}

void  Tower_of_Hanoi(int limit, struct Stack *sourcePole, struct Stack *tempPole, struct Stack *destPole)
{
      int count, shift;
      char dest = 'D', source = 'S', temp = 'A';
      if(limit % 2 == 0)
      {
            char x = dest;
            dest = temp;
            temp  = x;
      }
      shift = pow(2, limit) - 1;
      for(count = limit; count >= 1; count--)
      {
            push_item(sourcePole, count);
      }
      for(count = 1; count <= shift; count++)
      {
            if(count%3 == 1)
            {
                  Disk_shift(sourcePole, destPole, source, dest);
            }
            else if(count%3 == 2)
            {
                  Disk_shift(sourcePole, tempPole, source, temp);
            }
            else if(count%3 == 0)
            {
                  Disk_shift(tempPole, destPole, temp, dest);
            }
      }
}

int main()
{
      int n;
      struct Stack *sourcePole, *destPole, *tempPole;
      printf("\nEnter the Number of Disks : ");
      scanf("%d", &n);
      if(n<=0)
      {
          printf("\nInvalid Input");
          return 0;
      }
      printf("\nSequence of Disk Moves:\n");
      sourcePole = Stack_create(n);
      tempPole = Stack_create(n);
      destPole = Stack_create(n);
      Tower_of_Hanoi(n, sourcePole, tempPole, destPole);
      printf("\n");
      return 0;
}

