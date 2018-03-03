/*
 * TCPClient.h
 *
 *  Created on: Mar 2, 2018
 *      Author: Elijah
 */

#ifndef TCPCLIENT_H_
#define TCPCLIENT_H_

#include  <stdio.h>
#include  <sys/socket.h>
#include  <arpa/inet.h>
#include  <stdlib.h>
#include  <string.h>
#include  <unistd.h>

#define RCVBUFSIZE 32

void ClientDieWithError(const char* errorMessage);
int start_client(char* ip, char* string, int port);

#endif /* TCPCLIENT_H_ */
