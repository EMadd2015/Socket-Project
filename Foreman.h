/*
 * Foreman.h
 *
 *  Created on: Feb 7, 2018
 *      Author: Elijah
 */

#ifndef FOREMAN_H_
#define FOREMAN_H_

#include <tcp-server.c>

class Foreman {
public:
	Foreman(); // should start server on default
	virtual ~Foreman();
	int query();
	int reg(std::string username, std::string address, int port, int coins);
	int dereg(std::string username);
	int save();
};

#endif /* FOREMAN_H_ */
