#include  <stdio.h>
#include  <sys/socket.h>
#include  <arpa/inet.h>
#include  <stdlib.h>
#include  <string.h>
#include  <unistd.h>

#define RCVBUFSIZE 32

void DieWithError(const char* errorMessage)
{
  perror(errorMessage);
  exit(1);
}

int main(int argc, char** argv)
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
    
    servIP = argv[1];
    echoString = argv[2];
    
    if(argc == 4)
    {
      echoServPort = atoi(argv[3]);
    }
    else
    {
      echoServPort = 7;
    }

    if((sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
    {
      DieWithError("socket() failed");
    }

    memset(&echoServAddr, 0, sizeof(echoServAddr));
    echoServAddr.sin_family = AF_INET;
    echoServAddr.sin_addr.s_addr = inet_addr(servIP);
    echoServAddr.sin_port = htons(echoServPort);

    if(connect(sock, (struct sockaddr*) &echoServAddr, sizeof(echoServAddr)) < 0)
    {
        DieWithError("recvfrom() failed");
    }

    echoStringLen = strlen(echoString);
    
    if(send(sock, echoString, echoStringLen, 0) != echoStringLen)
    {
        DieWithError("sendto() sent a different umber of bytes than expected");      
    }

    totalBytesRcv = 0;
    
    printf("Recieved: ");
    
    while(totalBytesRcv < echoStringLen)
    {
        if((bytesRcv = recv(sock, echoBuffer, RCVBUFSIZE - 1, 0)) <= 0)
        {
            DieWithError("recv() failed or connection closed prematurely");
        }
        totalBytesRcv += bytesRcv;
        
        echoBuffer[echoStringLen] = '\0';
        printf("Received: %s\n", echoBuffer);       
    }
    printf("\n");

    close(sock);
    exit(0);
}
