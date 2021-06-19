/*
**********  Thirteen task on  Algorithm course                               ****
**********  Filename >main.cpp                                               ****
**********  IDE > QT Creator 4.13.2||CodeBlocks 20.03 + GCC 10.2.0           ****
**********  Created by > "~ORDA~" , Anton Bondarenko                         ****
**********  Date 16.05.2021                                                  ****
*/
#include <iostream>
#include"sources/geek.h"
#include"sources/geek.c"
//*************************************************
//*****Graphs 1st part*****************************
//*****\/\/\/\/\/\/\/\/****************************
const int n=6;
int matrix[n][n]=
{
 {0,1,1,0,0,0},
 {0,0,0,1,1,1},
 {0,0,0,0,0,1},
 {1,0,0,0,0,0},
 {0,0,0,0,0,0},
 {0,0,0,0,1,0},
};
int visited[n]={0};

void depthTravers(int st)
{
  int r;
printf("%d",st);
visited[st]=1;
for(r=0;r<n;++r)
    {
     if (matrix[st][r]==1&&!visited[r])
        {
         depthTravers(r);
        }
    }
}
void resetArr()
 {
    for(int i=0;i<n;++i)
    {
        visited[i]=0;
    }
 }
void clearVisited(int*arr,int size)
{
    for(int i=0;i<size;++i)
    {
        arr[i]=0;
    }
}
void widthTravers(int** matrix, int start, const int size)
{
    TwoLinkList* queue=(TwoLinkList*)malloc(sizeof(TwoLinkList));
    initTwoLinkList(queue);
    int visited[size];
    clearVisited(visited,size);
    TwoLinkEnqueue(queue,start);
    while(queue->size>0)
        {
           int indx=TwoLinkDequeue(queue);
           if(visited[indx]==1)
              {
               continue;
              }
           visited[indx]=1;
           printf("%d",indx);
           for(int i=0;i<size;++i)
              {
               if(get2dInt(matrix,indx,i)==1&&visited[i]==0)
                {
                  TwoLinkEnqueue(queue,i);
                }
              }
         }

}
//*****/\/\/\/\/\/\/\/\****************************
//*****Graphs 1st part*****************************
//*************************************************

//*************************************************
//*****Graphs 2nd part*****************************
//*****\/\/\/\/\/\/\/\/****************************
const int WIDTH = 10;
const int HEIGHT = 8;
const int OBSTACLE = -1;
const int BLANK = -2;

int pointX[HEIGHT*WIDTH];
int pointY[HEIGHT*WIDTH];

int len;

int lee(int** grid,int sx,int sy, int ex, int ey)
    {
    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};

    int x;
    int y;
    int vector;
    int distance =0;
    int stop;

    if(grid[sy][sx]==OBSTACLE||grid[ey][ex]==OBSTACLE)
        {
           return 0;
        }
      grid [sy][sx]=0;
      do
        {
          stop=true;
          for( y=0; y<HEIGHT; ++y )
            {
             for( x=0; x<WIDTH; ++x )
                {
                  if(grid[y][x]==distance)
                    {
                      for(vector=0;vector<4;++vector)
                        {
                            int nextX=x+dx[vector];
                            int nextY=y+dy[vector];
                            if(nextX>=0&&nextX<WIDTH&&
                               nextY>=0&&nextY<HEIGHT&&
                               grid[nextY][nextX]==BLANK)
                                {
                                  stop =false;
                                  grid[nextY][nextX]=distance+1;
                                }
                         }
                    }
                 }
             }
             distance++;
       }while(!stop&&grid[ey][ex]==BLANK);

      if(grid[ey][ex]==BLANK)
        {
          return 0;
        }
       len=grid[ey][ex];
       x=ex;
       y=ey;
       while (distance>0)
            {
             pointX[distance] = x;
             pointY[distance] = y;
             distance--;
             for(vector=0;vector<4;++vector)
                {
                 int nextX=x+dx[vector];
                 int nextY=y+dy[vector];
                 if(nextX>=0&&nextX<WIDTH&&
                    nextY>=0&&nextY<HEIGHT&&
                    grid[nextY][nextX]==distance)
                    {
                      x=nextX;
                      y=nextY;
                    }
                 }
            }
       return len;
    }
//*****/\/\/\/\/\/\/\/\****************************
//*****Graphs 2nd part*****************************
//*************************************************

//*************************************************
//*****grid algorythm part*****************************
//*****\/\/\/\/\/\/\/\/****************************
int profitCalculation(int* deadline, int* task, const int TASKS,const int DAYS)
{
   int used [DAYS];
   int arr  [DAYS];

   clearIntArray(used,DAYS);
   clearIntArray(arr,DAYS);

   int sum =0;
   for(int i=0;i<TASKS;++i)
        {
         int k=deadline[i];
         while(k>=1&&used[k]==1)
            {
             k--;
            }
         if(k==0) continue;

         used[k]=1;
         arr[k]=task[i];
         sum +=task[i];
         }
   printIntArray(arr,DAYS,0);
   return sum;

}
//*****/\/\/\/\/\/\/\/\****************************
//*****grid algorythm part*****************************
//*************************************************

int main()
{
  //*************************************************
  //*****Graphs 1st part*****************************
  //*****\/\/\/\/\/\/\/\/****************************
  for(int z=0; z<1;z++)// this cycle only for hide part text
  {
  depthTravers(0);
  resetArr();
  printf("\n");
  depthTravers(2);
  resetArr();
  printf("\n");
  depthTravers(1);
  resetArr();
  printf("\n");
  const int SZ=6;
  int** adjacency=init2dIntArray(adjacency,SZ,SZ);
  set2dInt(adjacency,0,1,1);
  set2dInt(adjacency,0,2,1);
  set2dInt(adjacency,1,3,1);
  set2dInt(adjacency,1,4,1);
  set2dInt(adjacency,1,5,1);
  set2dInt(adjacency,2,5,1);
  set2dInt(adjacency,3,0,1);
  set2dInt(adjacency,5,4,1);

  widthTravers(adjacency,0,SZ);
  printf("\n");
  widthTravers(adjacency,3,SZ);
  printf("\n");
  widthTravers(adjacency,1,SZ);
  printf("\n");
  }
  //*****/\/\/\/\/\/\/\/\****************************
  //*****Graphs 1st part*****************************
  //*************************************************

  //*************************************************
  //*****Graphs 2nd part*****************************
  //*****\/\/\/\/\/\/\/\/****************************
 for(int z=0; z<1;z++)
  {
  int **matrix1 =init2dIntArray(matrix1,HEIGHT,WIDTH);
  for (int i=0; i<HEIGHT; ++i )
      {
         for( int j=0; j<WIDTH; ++j )
            {
               set2dInt(matrix1,i,j,BLANK);
            }
      }
  set2dInt(matrix1,4,3,OBSTACLE);
  set2dInt(matrix1,4,4,OBSTACLE);
  set2dInt(matrix1,4,5,OBSTACLE);
  set2dInt(matrix1,4,6,OBSTACLE);

  print2dIntArray(matrix1,HEIGHT,WIDTH,3);
  printf("\n");

  int lenght=lee(matrix1,2,2,7,5);
  print2dIntArray(matrix1,HEIGHT,WIDTH,3);
  printf("\n");
  printIntArray(pointX,lenght,0);
  printIntArray(pointY,lenght,0);
 }
  //*****/\/\/\/\/\/\/\/\****************************
  //*****Graphs 2nd part*****************************
  //*************************************************

  //*************************************************
  //*****grid algorythm part*****************************
  //*****\/\/\/\/\/\/\/\/****************************
  const int DMAX =10;
  const int N=12;
  int task[]=    {1000,900,800,700,600,500,400,300,300,100,75,50};
  int deadline[]={2,   8,  9,  3,  5,  4,  7,  2,  1,  6,  9, 10};
  printf("%d\n", profitCalculation(deadline,task,N,DMAX));
  //*****/\/\/\/\/\/\/\/\****************************
  //*****grid algorythm part*****************************
  //*************************************************
  return 0;
}
