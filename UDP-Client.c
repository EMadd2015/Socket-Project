#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define ECHOMAX 255

void DieWithError(const char* errorMessage)
{
  perror(errorMessage);
  exit(1);
}

int start_client(char* serverIP, char* string, char* port)
{
  int sock;
  struct sockaddr_in echoServAddr;
  struct sockaddr_in fromAddr;
  unsigned int fromSize;
  char echoBuffer[ECHOMAX + 1];
  unsigned short echoServPort;
  int echoStringLen;
  int respStringLen;
  char* servIP;
  char* echoString;
  
  /**
  if((argc < 3) || (argc > 4))
  {
    fprintf(stderr, "Usage: %s <Server IP> <Echo Word> [<Echo Port>]\n", argv[0]);
    exit(1);
  }
  *//
  
  servIP = serverIP;
  echoString = string;
  
  if((echoStringLen = strlen(echoString)) > ECHOMAX)
  {
    DieWithError("Echo word too long");
  }
  
  if(argc == 4)
  {
    echoServPort = atoi(port);
  }
  else
  {
    echoServPort = 7;
  }
  
  if((sock = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0)
  {
    DieWithError("socket() failed");
  }
  
  memset(&echoServAddr, 0, sizeof(echoServAddr));
  echoServAddr.sin_family = AF_INET;
  echoServAddr.sin_addr.s_addr = inet_addr(servIP);
  echoServAddr.sin_port = htons(echoServPort);
  
  if(sendto(sock, echoString, echoStringLen, 0, (struct sockaddr*) &echoServAddr, sizeof(echoServAddr)) != echoStringLen)
  {
    DieWithError("sendto() sent a different umber of bytes than expected");
  }
  
  fromSize = sizeof(fromAddr);
  if((respStringLen = recvfrom(sock, echoBuffer, ECHOMAX, 0, (struct sockaddr*) &fromAddr, &fromSize)) != echoStringLen)
  {
    DieWithError("recvfrom() failed");
  }
  
  if(echoServAddr.sin_addr.s_addr != fromAddr.sin_addr.s_addr)
  {
    fprintf(stderr, "Error: received a packet from unknown source.\n");
    exit(1);
  }
  
  echoBuffer[respStringLen] = '\0';
  printf("Received: %s\n", echoBuffer);
  
  close(sock);
  exit(0);
}
