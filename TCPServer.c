#include  <stdio.h>
#include  <sys/socket.h>
#include  <arpa/inet.h>
#include  <stdlib.h>
#include  <string.h>
#include  <unistd.h>

#define MAX 5

void DieWithError(const char *errorMessage)
{
  perror(errorMessage);
  exit(1);
}

void HandleTCPClient(int clntSocket) {
    ssize_t n;
    char line[MAX];

    for ( ; ; ) {
	    if ( (n = read(clntSocket, line, MAX)) == 0 )
   	    	return; /* connection closed by other end */

        write(clntSocket, line, n );
    }
}

int main(int argc, char** argv)
{
    int servSock;
    int clntSock;
    struct sockaddr_in echoServAddr;
    struct sockaddr_in echoClntAddr;
    unsigned short echoServPort;
    unsigned int clntLen;
    
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <SERVER PORT>\n", argv[0]);
        exit(1);
    }
    
    echoServPort = atoi(argv[1]);
    
    if ((servSock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
    {
        DieWithError("socket() failed");
    }
    
      memset(&echoServAddr, 0, sizeof(echoServAddr));   // Zero out structure 
      echoServAddr.sin_family = AF_INET;                // Internet address family 
      echoServAddr.sin_addr.s_addr = htonl(INADDR_ANY); // Any incoming interface 
      echoServAddr.sin_port = htons(echoServPort);      // Local port  

      //bind to the local address
      if(bind(servSock, (struct sockaddr*) &echoServAddr, sizeof(echoServAddr)) < 0)
      {
          DieWithError("bind() failed");
      }
      
      //mark the socket to listen for incoming connections
      if(listen(servSock, MAX) < 0)
      {
        DieWithError("listen() failed");
      }
      
      while(1)
      {
          clntLen = sizeof(echoClntAddr);
          
          if((clntSock = accept(servSock, (struct sockaddr*) &echoClntAddr, &clntLen)) < 0)
          {
              DieWithError("accept() failed");
          }
          
          printf("Handling client %s\n", inet_ntoa(echoClntAddr.sin_addr));
          
          HandleTCPClient(clntSock);
      }
  
}
