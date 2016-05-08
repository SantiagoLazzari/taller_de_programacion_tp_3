/*
 * Lock.cpp
 *
 *  Created on: Apr 26, 2016
 *      Author: santi
 */

#include "common_Lock.h"

#include "common_Mutex.h"

Lock::Lock(Mutex &mutex) : aMutex(mutex) {
    aMutex.enableLock();
}

Lock::~Lock() {
	// Upon destruction of lock, mutex is disabled
    aMutex.disableLock();
}
