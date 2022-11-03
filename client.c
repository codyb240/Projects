/***********************************************************

File name: Client/Server talk

Author: Cody Bruehl

Date: 10/25/21

Class: CS3013

Purpose: To have a client and a server talk to each other.
***********************************************************/
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#define MAX 80
#define PORT 8080
#define SA struct sockaddr

void conversation(int sock)												//function to talk between server and client
{
	char buff[MAX];
	int x;
	for(;;){
		bzero(buff, sizeof(buff));
		
		printf("Enter the string : ");								//ask for string
		x = 0;
		
		while((buff[x++] = getchar()) != '\n');

		write(sock, buff, sizeof(buff));							//send to server
		bzero(buff, sizeof(buff));
		
		read(sock, buff, sizeof(buff));							//read server reply
		printf("From Server : %s", buff);
		
		if((strncmp(buff, "exit", 4)) == 0){						//if "exit", terminate
			printf("Client Exit...\n");
			break;
		}
	}
}

int main()														
{
	int sock, conn;
	struct sockaddr_in servaddr, cli;

	sock = socket(AF_INET, SOCK_STREAM, 0);						//create socket
	if(sock == -1){
		printf("Failed to create socket!\n");
		exit(0);
	}else
		printf("Success!\n");
	bzero(&servaddr, sizeof(servaddr));

	servaddr.sin_family = AF_INET;									//assign ip 
	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	servaddr.sin_port = htons(PORT);

	if(connect(sock, (SA*)&servaddr, sizeof(servaddr)) != 0){		//connect sockets between client and server
		printf("Server cant connect :(\n");
		exit(0);
	}
	else
		printf("Server connects!! :D\n");

	conversation(sock);													//function call

	close(sock);													//close socket
}

