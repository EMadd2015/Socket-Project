#include <std.io>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define ECHOMAX 255

//error handling function
void DieWithError(const char *errorMessage)
{
  perror(errorMessage);
  exit(1);
}

int main(int argc, char** argv)
{
  int sock;                             //Socket
  struct sockaddr_in echoServAddr;     //local address
  struct sockaddr_in echoClntAddr;     //client address
  unsigned int cliAddrLen;              //length of incoming message
  char echoBuffer[ECHOMAX];             //buffer for echo string
  unsigned short echoServPort;          //server port
  int recvMsgSize;                      //size of recieved message
  
  if (argc != 2)      //test for correct number of parameters
  {
      fprintf(stderr, "Usage: %s <UDP SERVER PORT>\n", argv[0]);
      exit(1);
  }
  
  echoServPort = atoi(argv[1]); //First argument: local port
  
  //create socket for sending/recieving message
  if((sock = socket(PF_INET, SCOK_DGRAM, IPPROTO_UDP)) < 0)
  {
      DieWithError("socket() failed");
  }
  
  memset(&echoServAddr, 0, sizeof(echoServAddr));   // Zero out structure 
  echoServAddr.sin_family = AF_INET;                // Internet address family 
  echoServAddr.sin_addr.s_addr = htonl(INADDR_ANY); // Any incoming interface 
  echoServAddr.sin_port = htons(echoServPort);      // Local port  
  
  //bind to the local address
  if(bind(sock, (struct sockaddr*) &echoServAddr, sizeof(echoServAddr)) < 0)
  {
      DieWithError("bind() failed");
  }
  
  while(true)   //should loop forever
  {
      //set size of the in-out parameter
      cliAddrLen = sizeOf(echoClntAddr);
      
      //block until receive message from client
      if((recvMsgSize = recvfrom(sock, echoBuffer, ECHOMAX, 0, (struct sockaddr*) &echoClntAddr, &cliAddrLen)) < 0)
      {
          DieWithError("recvfrom() failed");
      }
      
      printf("Handling client %s\n", inet_ntoa(echoClntAddr.sin_addr));
      
      //send recived datagram back to the client
      if(sendto(sock, echoBuffer, recvMsgSize, 0, (struct sockaddr*) &echoClntAddr, sizeOf(echoClntAddr)) != recvMsgSize)
      {
          DieWithError("sendto() sent a different number of bytes than expected");
      }
      
     }
  } 

}
