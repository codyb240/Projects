/***********************************************************

File name: Client/Server talk

Author: Cody Bruehl

Date: 10/25/21

Class: CS3013

Purpose: To have a server and a client talk to each other.
***********************************************************/
#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#define MAX 80
#define PORT 8080
#define SA struct sockaddr

void conversation(int sock) 											//function to talk between server and client
{
	char buff[MAX];
	int x;
	
	for(;;){													//service loop
		bzero(buff, MAX);

		read(sock, buff, sizeof(buff)); 						// read message from client and copy it
		printf("From client: %s\t To client : ", buff); 		//print message
		bzero(buff, MAX);
		x = 0;
		while ((buff[x++] = getchar()) != '\n');				//copy server message

		write(sock, buff, sizeof(buff));						//send message to client

		if (strncmp("exit", buff, 4) == 0) {					//end if has word "exit"
			printf("Server Exit...\n");
			break;
		}
	}
}
int main()
{
	int sock, conn, len;
	struct sockaddr_in servaddr, cli;

	sock = socket(AF_INET, SOCK_STREAM, 0);					//create socket
	if(sock == -1){
		printf("Failed to create socket!\n");
		exit(0);
	}else
		printf("Success!\n");
	bzero(&servaddr, sizeof(servaddr));

	servaddr.sin_family = AF_INET;								//assign ip and port
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(PORT);

	if((bind(sock, (SA*)&servaddr, sizeof(servaddr))) != 0){	//bind and verify
		printf("socket Bound Failed :( )\n");
		exit(0);
	}else
		printf("Socket Bound :) \n");

	if((listen(sock, 5)) != 0){								//listen mode
		printf("Server no hear....\n");
		exit(0);
	}else
		printf("Server hear!! :D \n");
	len = sizeof(cli);

	conn = accept(sock, (SA*)&cli, &len);					//accept from client
	if(conn < 0){
		printf("Server cant accept :(\n");
		exit(0);
	}else
		printf("Server Accepts!! :D\n");

	conversation(conn);												//begin conversation

	close(sock);												//close socket
}

