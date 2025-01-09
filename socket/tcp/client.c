#include <stdio.h>
//--------------
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
//--------------
#include <unistd.h>
#include <string.h>

#define BUFFERSIZE 1024

void main(){
	int client , newsocket;
	char buffer[BUFFERSIZE];

	struct sockaddr_in serv_addr;
	struct sockaddr_storage store;

	socklen_t addr_size;

	client = socket(AF_INET,SOCK_STREAM,0);
	
	serv_addr.sin_family = AF_INET;
       	serv_addr.sin_port = htons(6266);
	serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	
	connect(client,(struct sockaddr *)&serv_addr ,sizeof(serv_addr));
	
	strcpy(buffer , "Hi,Server\n");
	send(client , buffer , 11 , 0);
	recv(client , buffer , BUFFERSIZE , 0);
	printf("[recieved]\t%s\n",buffer);
	
	close(client);
}
