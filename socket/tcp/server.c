#include <stdio.h>
#include <string.h>
//--------------
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
//--------------
#include <unistd.h>

#define BUFFERSIZE 1024

void main(){
	int server , newsocket;
	char buffer[BUFFERSIZE];

	struct sockaddr_in serv_addr;
	struct sockaddr_storage store;

	socklen_t addr_size;

	server = socket(AF_INET,SOCK_STREAM,0);
	
	serv_addr.sin_family = AF_INET;
       	serv_addr.sin_port = htons(6266);
	serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
		

	bind(server,(struct sockaddr*)&serv_addr,sizeof(serv_addr));

	if(listen(server,5) == 0){
		printf("[info]\tlistening to connections...\n");
	}else{
		printf("[error]\tunable to listen \n");
	}
	
	newsocket = accept(server , (struct sockaddr*)&store ,&addr_size);
	recv(newsocket , buffer  , BUFFERSIZE,0);
	printf("[recieved]\t%s\n",buffer);
	strcpy(buffer,"Hi,Client\n");
	printf("[info]\tSending data to client\n");
	send(newsocket,buffer,11,0);
	close(newsocket);
	close(server);
	
	return;
}
