#include "TCPClient.h"

void ClientDieWithError(const char* errorMessage)
{
  perror(errorMessage);
  exit(1);
}

int start_client(char* ip, char* string, int port)
{
    int sock;
    struct sockaddr_in echoServAddr;
    unsigned short echoServPort;
    char echoBuffer[RCVBUFSIZE];
    unsigned int echoStringLen;
    int bytesRcv;
    int totalBytesRcv;
    char* servIP;
    char* echoString;
    
    servIP = ip;
    echoString = string;
    echoServPort = port;
    
    /*
    if(argc == 4)
    {
      echoServPort = port;
    }
    else
    {
      echoServPort = 7;
    }
    */

    if((sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
    {
      ClientDieWithError("socket() failed");
    }

    memset(&echoServAddr, 0, sizeof(echoServAddr));
    echoServAddr.sin_family = AF_INET;
    echoServAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    echoServAddr.sin_port = htons(echoServPort);

    if(connect(sock, (struct sockaddr*) &echoServAddr, sizeof(echoServAddr)) < 0)
    {
        ClientDieWithError("recvfrom() failed");
    }

    echoStringLen = strlen(echoString);
    
    if(send(sock, echoString, echoStringLen, 0) != echoStringLen)
    {
        ClientDieWithError("sendto() sent a different umber of bytes than expected");
    }

    totalBytesRcv = 0;
    
    printf("Recieved: ");
    
    while(totalBytesRcv < echoStringLen)
    {
        if((bytesRcv = recv(sock, echoBuffer, RCVBUFSIZE - 1, 0)) <= 0)
        {
            ClientDieWithError("recv() failed or connection closed prematurely");
        }
        totalBytesRcv += bytesRcv;
        
        echoBuffer[echoStringLen] = '\0';
        printf("Received: %s\n", echoBuffer);       
    }
    printf("\n");

    close(sock);
    exit(0);
}
