/*
 * Thread.cpp
 *
 *  Created on: Apr 26, 2016
 *      Author: santi
 */

#include "common_Thread.h"

#include <stddef.h>

Thread::~Thread() {
}

void Thread::start() {
	pthread_create(&myThread, NULL, Thread::runner, this);
}

void Thread::join() {
	pthread_join(myThread, NULL);
}

void* Thread::runner(void *data) {
	// Self receive me and run me, then return self
    Thread *self = (Thread*)data;
    self->run();
    return data;
}

