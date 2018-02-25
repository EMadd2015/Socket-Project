/*
 * Message.h
 *
 *  Created on: Feb 14, 2018
 *      Author: Elijah
 */

#ifndef MESSAGE_H_
#define MESSAGE_H_

#include <iostream>

class Message {
public:
	Message();
	virtual ~Message();
private:
	int type; // a number indicating what kind of message is being sent
	int ip; // ip address of the machine to which the message is being sent
	int port; // port on the machine to which the message is being sent
	int id; // id for the client to use. May be null
	int request; // payload size for response from server or coins in a transaction
	string message; // misc field (further testing required)

};

#endif /* MESSAGE_H_ */
