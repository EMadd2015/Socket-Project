/*
 * Miner.h
 *
 *  Created on: Feb 7, 2018
 *      Author: Elijah
 */

#ifndef MINER_H_
#define MINER_H_

#include "TCPClient.h"

class Miner {
public:
	Miner();
	virtual ~Miner();
	void *init();
};

#endif /* MINER_H_ */
