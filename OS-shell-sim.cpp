/********************************************************
*	File name:	OS-shell-sim.cpp
*	Author:		Cody Bruehl
*	Date:		9/24/21
*	Class:		CS3513
*	Purpose:	Execute a command
********************************************************/

#include <stdio.h> //for printf() and scanf()
#include <string.h>//strlen(), strcpy(), strcmp()
#include <unistd.h>//execl()
#include <stdlib.h>//exit()
using namespace std;
#define SIZE 80
int main()
{
	char cmd[SIZE]; //store cmd
	char diff[SIZE]; //store diff
	diff[0] = 'B';
	int a;
	int verification;
	pid_t pid;
	char* p; //points to path 
	char *paths[SIZE];
	char* temp;//stores one temporary path
	p = getenv("PATH");
	printf("\nPath info is %s\n", p);
	//print path information
	temp = strtok(p, ":");
	a = 0;
	while(temp)//creates 2d array of path
	{
		paths[a] = temp;//stores temporary to the path
		printf("\n%s\n", temp);
		a++;
		temp = strtok(NULL, ":");
	}
	
	for(;;) //loop until user stops it
	{
		printf("\nMy Shell %s >>> ", getenv("HOME"));
		scanf("%s %s", cmd, diff);
		printf("\n Cmd is: %s", cmd);
		printf("\t length is %d\n", strlen(cmd));

		verification = 1;

		if(strcmp(diff, "B")== 0)
                {
			verification = 0;
                }

		if(strcmp(cmd, "exit")== 0)
		{
			printf("\n Goodbye \n");
			exit(0);
		}
		
		pid = fork();
		if(pid == 0)//child process
	
		{
			int k;
            for(k = 0; k < a; k++)
            //go through all paths
            {
                char path[SIZE];
                strcpy(path, paths[k]);
                strcat(path, "/");
                strcat(path, cmd);
                execl(path, cmd, 0);
            }
            printf("\nCmd NOT FOUND\n");
            exit(1);//stop child process
		}
		else
			wait();
		
	}
	
	exit(0);
} 
