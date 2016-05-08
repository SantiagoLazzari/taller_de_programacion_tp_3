/*
 * Mutex.h
 *
 *  Created on: Apr 26, 2016
 *      Author: santi
 */

#ifndef COMMON_MUTEX_H_
#define COMMON_MUTEX_H_

#include <pthread.h>

// Wrapper for pthread_mutex
class Mutex {
private:
	pthread_mutex_t myMutex;
public:
	// Constructor
	Mutex();
	// Destroyer
	virtual ~Mutex();
	// Lock the sensitive resources
	void enableLock();
	// Disbale the lock on sensitive resources
	void disableLock();
};
#endif /* COMMON_MUTEX_H_ */
