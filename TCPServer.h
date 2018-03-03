/*
 * TCPServer.h
 *
 *  Created on: Mar 2, 2018
 *      Author: Elijah
 */

#ifndef TCPSERVER_H_
#define TCPSERVER_H_

#include  <stdio.h>
#include  <sys/socket.h>
#include  <arpa/inet.h>
#include  <stdlib.h>
#include  <string.h>
#include  <unistd.h>

#define MAX 5 // maximum outstanding connection requests

void ServerDieWithError(const char *errorMessage);
void HandleTCPClient(int clntSocket);
int start_server(int port);

#endif /* TCPSERVER_H_ */
