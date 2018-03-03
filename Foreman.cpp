/*
 * Foreman.cpp
 *
 *  Created on: Feb 7, 2018
 *      Author: Elijah
 */

#include "Foreman.h"

Foreman::Foreman() {

}

Foreman::~Foreman() {
	// TODO Auto-generated destructor stub
}

int init() {
	start_server(1080);
}
int query() {}
int reg(char* username, char* address, int port, int coins) {}
int dereg(char* username) {}
int save() {}
