/*
 * Miner.cpp
 *
 *  Created on: Feb 7, 2018
 *      Author: Elijah
 */

#include "Miner.h"

Miner::Miner() {

}

Miner::~Miner() {
	// TODO Auto-generated destructor stub
}

void *init() {
	// test
	start_client("127.0.0.1", "hello world!", 1080);
}
