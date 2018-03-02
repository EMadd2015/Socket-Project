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
int reg(std::string username, std::string address, int port, int coins) {}
int dereg(std::string username) {}
int save() {}
