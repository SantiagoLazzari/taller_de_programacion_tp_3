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

class AcceptThread : public Thread {
public:
	AcceptThread(Socket *acceptSocket);
	AcceptThread();
	virtual ~AcceptThread();
	void run();
	void endAccepting();

private:
	Socket *socket;
	bool endAcceptingClients;
	std::vector<Socket *> *clients;

};

#endif /* SERVER_ACCEPTTHREAD_H_ */
