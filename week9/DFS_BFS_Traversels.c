#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int adjMatrix[15][15], dfs_visited[15], bfs_visited[15] , queue[15], front = 0, rear = -1, n;


//Depth First Search
void Depth_First_Search(int v)
{
 int i;
 dfs_visited[v]=1;

 for(i=1;i<=n;i++)
  if(adjMatrix[v][i] && !dfs_visited[i])
  {
   printf("\n %d",i);
   Depth_First_Search(i);
  }
}


//Breadth First Search
void Breadth_First_Search(int v)
{
 for(int i = 1; i <= n; i++)
 if(adjMatrix[v][i] && !bfs_visited[i])
 queue[++rear] = i;
   if(front <= rear)
     {
     bfs_visited[queue[front]] = 1;
     Breadth_First_Search(queue[front++]);
     }
}

void main()
{
 int i,j,count=0,choice,v;

 while(1)
 {
printf("\n\n 1. Breadth First Search \n 2. Depth First Search \n 3. Exit \n Enter your choice :\n");
 scanf("%d",&choice);
   if(choice == 1)
     {
        printf(" Enter number of vertices :");
        scanf("%d",&n);
         for(int i=1; i <= n; i++)
         {
             queue[i] = 0;
             bfs_visited[i] = 0;
         }

         printf("\n Enter the adjacent matrix: \n");
         for(i=1; i<=n; i++)
         {
             for(j=1;j<=n;j++)
             {
             scanf("%d", &adjMatrix[i][j]);
             }
         }


         Breadth_First_Search(1);
         printf("\n The nodes which are reachable are:\n");
            printf(" %d",1);
         for(i=1; i <= n; i++)
         {
             if(bfs_visited[i])
             printf("\n %d", i);
             else
                 {
                 printf("\n Breadth First Search is not possible");
                 break;
                 }
         }
     }

     else if(choice == 2)
     {
         printf(" Enter number of vertices :");
        scanf("%d",&n);
          for(int i=1;i<=n;i++)
          {
          dfs_visited[i]=0;
          for(int j=1;j<=n;j++)
           adjMatrix[i][j]=0;
          }

         printf("\n Enter the adjacency matrix: ");
         for(i=1;i<=n;i++)
         {
             for(j=1;j<=n;j++)
             {
             scanf("%d",&adjMatrix[i][j]);
             }
        }


         printf("\n The nodes which are reachable are: \n");
         printf(" %d",1);
         Depth_First_Search(1);
         printf("\n");
         for(int i=1;i<=n;i++)
         {
          if(dfs_visited[i])
           count++;
           else
                 {
                 printf("\n Depth First Search is not possible");
                 break;
                 }
         }


     }

    else
     {
         exit(1);
     }


  }


 }
