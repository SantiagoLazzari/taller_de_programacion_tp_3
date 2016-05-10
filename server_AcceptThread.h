/*
 * AcceptThread.h
 *
 *  Created on: May 8, 2016
 *      Author: santi
 */

#ifndef SERVER_ACCEPTTHREAD_H_
#define SERVER_ACCEPTTHREAD_H_

#include "common_Thread.h"

#include "common_Socket.h"
#include <vector>
#include "server_ReducerThread.h"
#include "server_ThreadSafeHashMap.h"

class AcceptThread : public Thread {
public:
	AcceptThread(Socket *acceptSocket, ThreadSafeHashMap *aThreadSafeMap);
	AcceptThread();
	virtual ~AcceptThread();
	void run();
	void endAccepting();

private:
	void joinReducers();

	Socket *socket;
	ThreadSafeHashMap *threadSafeMap;
	bool endAcceptingClients;
	std::vector<Socket *> *clients;
	std::vector<ReducerThread *> *reducers;

};

#endif /* SERVER_ACCEPTTHREAD_H_ */
