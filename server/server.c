#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>

int main(){
	int servsock = socket(AF_INET, SOCK_STREAM, 0);

	char message[1024] = "Message from tge server to the client \'Hey\' ";

	struct sockaddr_in servAddr;
	
	servAddr.sin_family = AF_INET;
	servAddr.sin_port = htons(9001);
	servAddr.sin_addr.s_addr = INADDR_ANY;

	bind(servsock, (struct sockaddr*)&servAddr, sizeof(servAddr));
	
	listen(servsock,1);
	
	int clientSocket = accept(servsock, NULL, NULL);

	send(clientSocket, message, sizeof(message), 0);
	
	return 0;







}
