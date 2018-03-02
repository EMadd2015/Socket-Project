/*
 * Foreman.cpp
 *
 *  Created on: Feb 7, 2018
 *      Author: Elijah
 */

#include "Foreman.h"

Foreman::Foreman() {
	start_server(1080);
}

Foreman::~Foreman() {
	// TODO Auto-generated destructor stub
}

int query() {}
int reg(char* username, char* address, int port, int coins) {}
int dereg(char* username) {}
int save() {}
