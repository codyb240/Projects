#include<stdio.h>

int main(){
	int pid;
	pid = fork();
	
	if(pid == 0) //child process
	{
		printf("\n This is the child process.\n");
		printf("My PID is: %d: ", getpid());
		system("ls");
	}
	else // this is the parent process
	{	wait(); //wait for child process
	printf("\nThis is the parent process\n");
	printf("\nMy Child PID is: %d", pid);
	system("ps");
	}
}
return 0;
