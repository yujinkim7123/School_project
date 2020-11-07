#include <stdio.h> 
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h> 
#include <stdlib.h>
#include <unistd.h> 
#include <ctype.h>

#define BUFFER_SIZE 1024
void main(int argc, char *argv[]) {
	int sock;
	struct sockaddr_in srvAddr;
	struct sockaddr_in cliAddr;
	char *srvIp = NULL;
	unsigned short srvPort;
	char buffer[BUFFER_SIZE];
	int sentSize, rcvSize, srvAddrLen, cliAddrLen;
	int ret, i;
	if (argc != 2) {
		printf("Usage: %s Port\n", argv[0]);
		exit(0);
	}
	srvPort = atoi(argv[1]);

	sock = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (sock < 0) {
		printf("socket() failed\n");
		exit(0);
	}
	memset(&srvAddr, 0, sizeof(srvAddr));
	srvAddr.sin_family = AF_INET;
	srvAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	srvAddr.sin_port = htons(srvPort);
	ret = bind(sock, (struct sockaddr *) &srvAddr, sizeof(srvAddr));
	if (ret < 0) {
		printf("bind() failed\n");
		exit(0);
	}
	printf("Server is running.\n");

	while (1) {
		cliAddrLen = sizeof(cliAddr);
		rcvSize = recvfrom(sock, buffer, BUFFER_SIZE, 0,
				(struct sockaddr *) &cliAddr, &cliAddrLen);
		if (rcvSize < 0) {
			printf("Error in recvfrom()\n");
			exit(0);
		}
		buffer[rcvSize] = '\0';
		printf("[Client/%s:%d] %s\n", inet_ntoa(cliAddr.sin_addr),
				ntohs(cliAddr.sin_port), buffer);
		if (!strcmp(buffer, "quit"))
			break;
		for (i = 0; buffer[i] != '\0'; i++)
			buffer[i] = toupper(buffer[i]);
		sentSize = sendto(sock, buffer, strlen(buffer), 0,
				(struct sockaddr *) &cliAddr, sizeof(cliAddr));
		if (sentSize != strlen(buffer)) {
			printf("sendto() sent a different number of bytes than expected");
			exit(0);
		}
	}
	close(sock);
	printf("UDP Server is Closed.\n");
}
