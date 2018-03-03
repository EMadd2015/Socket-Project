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
	Foreman *foreman = new Foreman();
	Miner *miner = new Miner();

	pthread_create(&threadID, NULL, (void*)&Foreman::init, NULL);
	pthread_create(&threadID, NULL, (void*)&Miner::init, NULL);

	pthread_exit(NULL);
}
