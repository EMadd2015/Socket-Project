/*
 * Miner.cpp
 *
 *  Created on: Feb 7, 2018
 *      Author: Elijah
 */

#include "Miner.h"

Miner::Miner() {
	// init_client();
	// Miner.reg();
}

Miner::~Miner() {
	// TODO Auto-generated destructor stub
}

void *Miner::init_client(void* unused) {
	// test
	start_client("127.0.0.1", "hello world!", 1080);
}

/* PSEUDO
 * register() {
 * 	new Message();
 * 	Message.type = REG // REG defined as int
 * 	Message.src = clientIpAddress;
 * 	Message.dest = serverIpAddress;
 * 	Message.msg = "{ ... }" // formatted string containing username and coins
 * 	client_send(Message);
 * 	Message = client_read(Message); // reads a message from client and stores it in message object
 * 	int numOfPeers = Message.msg.readLine(); // reads message from server for number of peers in network
 * 	for (numOfPeers) {
 * 		int address = Message.msg.readLine(); // reads each line containing peers' addresses
 * 		Message.type = ADD // ADD defined as an int.
 * 		Message.dest = address;
 * 		Message.msg = "{ ... }" // formatted string containing username and coins
 * 	}
 * }
 */
