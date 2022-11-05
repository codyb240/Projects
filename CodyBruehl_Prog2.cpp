/*------------------------------------------------
Programmer:		Cody Bruehl
Professor:		Dr. Zhao
Due Date:		10/27/21
Purpose:
This program uses pthreads and dynamic memory
allocation to compute the size of a matrices
input by a user.
------------------------------------------------*/
#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>

void *mult(void* arg)	//one thread computes one element 
{
	int *data = (int *)arg;
	int a = 0, b = 0;
	
	int c = data[0];
	for (b = 1; b <= c; b++)
		a += data[b]*data[b+c];
	
	int *p = (int*)malloc(sizeof(int));
		*p = a;
		
	pthread_exit(p);
}

int main()
{
	int X, Y, Z;
	
	printf("Enter number of rows for Matrix A: ");	//inputs rows and columns
	scanf("%d", &X);
	
	printf("Enter number of Columns for Matrix A: ");
	scanf("%d", &Y);
	
	printf("Enter number of Columns for Matrix B: ");
	scanf("%d", &Z);
	
	int a[X][Y];
	int b[X][Z];
	int c[Y][Z];
	
	
	printf("Matrix A size: %d x %d \n", X, Y);	//confirm dimensions
	printf("Matrix B size: %d x %d \n", Y, Z);
	
	int r1=X, c1=Y, r2=Y, c2=Z;
	int i, j, k;
	
	printf("Input matrix A:\n");	//user enters matrix elements
		for(i=0;i<r1;i++)
		{
  			for(j=0;j<c1;j++)
  			{  
    			scanf("%d",&a[i][j]);  
  			}
		}
	printf("Input matrix B:\n");  
		for(i=0;i<r2;i++)
		{
  			for(j=0;j<c2;j++)
  			{  
    			scanf("%d",&b[i][j]);  
  			}
		}

	printf("Matrix A:\n");	//print matrices
		for(i=0;i<r1;i++)
		{
  			for(j=0;j<c1;j++)
  			{  
    			printf("%d\t", a[i][j]);  
  			}
  			printf("\n");
		}
	printf("Matrix B:\n");  
		for(i=0;i<r2;i++)
		{
  			for(j=0;j<c2;j++)
  			{  
    			printf("%d\t", b[i][j]);  
  			}
  			printf("\n");
		}
	
	int max = r1*c2;
	
	pthread_t *threads;	//create array 
	threads = (pthread_t*)malloc(max*sizeof(pthread_t));
	
	int count = 0;
	int* data = NULL;
	for(i=0; i<r1; i++)
		for(j=0; j<c2; j++)
			{
			data = (int *)malloc((20)*sizeof(int));	//store row and column data
			data[0] = c1;
	
			for (k = 0; k < c1; k++)
				data[k+1] = a[i][k];
	
			for (k = 0; k < r2; k++)
				data[k+c1+1] = b[k][j];
				
				pthread_create(&threads[count++], NULL,	//create threads
							mult, (void*)(data));			
			}
			
	printf("The Product Matrix is: \n");
	for(i=0; i<max; i++)
	{
	void *k;
	
	pthread_join(threads[i], &k);									//join threads and collect return value
			
		
		int *p = (int *)k;
	printf("%d ",*p);
	if((i + 1) % c2 == 0)
		printf("\n");
	free(p);														//deallocate memeory for p
	}
	free(data);														//deallocate memory for data
	return 0;														//end of program
}

