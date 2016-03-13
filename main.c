#include"head.h"
//#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>

int main()
{	
	//int sockfd;
	struct sockaddr_in servaddr;
	//char sendline[MAXLINE], recvline[MAXLINE];
	//struct client_data client;//for the client data
	sockfd=socket(AF_INET, SOCK_STREAM, 0); //AF_INET for ipv4; SOCK_STREAM for byte stream 
	memset(&servaddr, 0, sizeof(struct sockaddr_in));
	servaddr.sin_family=AF_INET;
	servaddr.sin_addr.s_addr=inet_addr("114.212.191.33");
	servaddr.sin_port=htons(SERV_PORT);
	//connect to the server
	connect(sockfd, (struct sockaddr* )&servaddr, sizeof(servaddr));
	if(link_to_server())
	{
		system("clear");
		printf("Welcome to NJUCE Weather Forecast Demo Program!\n");
		main_function();

	}
	else
	{
		system("clear");
		printf("Link Wrong!\n");
	}
	return 0;
}

