/*
 * Thread.h
 *
 *  Created on: Apr 26, 2016
 *      Author: santi
 */

#ifndef COMMON_THREAD_H_
#define COMMON_THREAD_H_

#include <pthread.h>

// Wrapper for pthread
class Thread {
private:
	pthread_t myThread;
	static void *runner(void *data);
protected:
	virtual void run() = 0;
public:
	// Constructor
	Thread() : myThread() {}
	// Destroyer
	virtual ~Thread();
	// Start the thread
	void start();
	// Join the thread to the main one (or another one but thats ugly)
	void join();
};
#endif /* COMMON_THREAD_H_ */
