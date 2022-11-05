#include libraries
int main()
{
	Declare necessary variables;
	Get path data;
Parse path data into a 2-d character array so that each entry of the array is a path.  Hint: you may use strtok function to complete this task.

	for(; ;)  //accept user's command until the user quits
	{
		Print shell prompt
		Read input 
		Compare the input with "quit" or "exit"
		if yes, and then 
terminate the program
		else {
			Call fork to create a child process
			if (child process)
			{
				for(path 1 to path n)
				{
					Make arguments for execl using strcpy and strcat 
					Call execl(path/cmd, cmd, argu1, …, 0);
				}
				No success, print no such a command
			else (parent process)
			         Call wait function to wait the child process' termination
	}//end of infinite loop

	exit(0);
}

