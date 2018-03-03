/*
 * main.cpp
 *
 *  Created on: Mar 2, 2018
 *      Author: Elijah
 */

#include <pthread.h>
#include "Foreman.h"
#include "Miner.h"

int main(int argc, char* argv[]) {
	pthread_t threadID;
	void (*functionPointer)(void*);
	Foreman *foreman = new Foreman();
	Miner *miner = new Miner();

	functionPointer = Foreman::init;
	pthread_create(&threadID, NULL, functionPointer, NULL);
	functionPointer = Miner::init;
	pthread_create(&threadID, NULL, functionPointer, NULL);

	pthread_exit(NULL);
}
