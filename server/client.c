#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>

int main(){
	int sock = socket(AF_INET, SOCK_STREAM, 0);
	
	struct sockaddr_in servAddr;
	servAddr.sin_family = AF_INET;
	servAddr.sin_port = htons(9001);
	servAddr.sin_addr.s_addr = INADDR_ANY;
	
	int connectStatus = connect(sock, (struct sockaddr*)&servAddr, sizeof(servAddr));
	if (connectStatus==-1){
		perror("Erro to create a server\n");
		exit(EXIT_FAILURE);
	} else {
		char strData[1024];
		recv(sock, strData, sizeof(strData), 0);
		printf("Message: %s\n", strData);
	}
	return 0;
}
