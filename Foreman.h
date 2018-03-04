/*
 * Foreman.h
 *
 *  Created on: Feb 7, 2018
 *      Author: Elijah
 */

#ifndef FOREMAN_H_
#define FOREMAN_H_

//#include <string.h>
#include "TCPServer.h"

class Foreman {
public:
	Foreman();
	virtual ~Foreman();
	static void *init_server(void*);
	int query();
	int reg(char* username, char* address, int port, int coins);
	int dereg(char* username);
	int save();
};

#endif /* FOREMAN_H_ */
