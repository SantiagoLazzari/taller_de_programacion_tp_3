/*
 * Lock.h
 *
 *  Created on: Apr 26, 2016
 *      Author: santi
 */

#ifndef COMMON_LOCK_H_
#define COMMON_LOCK_H_

// Forward declaration
class Mutex;

class Lock {
private:
        Mutex &aMutex;
public:
        // Constructor, reserves the current scope for the working thread
        explicit Lock(Mutex &aMutex);
        // Destroyer, enables scope for other threads to run
        ~Lock();
};
#endif /* COMMON_LOCK_H_ */
