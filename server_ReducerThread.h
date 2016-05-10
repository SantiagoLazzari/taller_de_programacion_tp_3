/*
 * ReducerThread.h
 *
 *  Created on: May 8, 2016
 *      Author: santi
 */

#ifndef SERVER_REDUCERTHREAD_H_
#define SERVER_REDUCERTHREAD_H_

#include "common_Thread.h"
#include "common_Socket.h"
#include "server_ThreadSafeHashMap.h"

class ReducerThread : public Thread {
public:
	ReducerThread(Socket *socket, ThreadSafeHashMap *threadSafeMap);
	ReducerThread();
	virtual ~ReducerThread();
	void run();

private:
	void receiveDataFromClient(std::string& incomingData);

	Socket *socket;
	ThreadSafeHashMap *threadSafeMap;
};

#endif /* SERVER_REDUCERTHREAD_H_ */
