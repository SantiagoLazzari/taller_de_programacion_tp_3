/*
 * Server.h
 *
 *  Created on: May 7, 2016
 *      Author: santi
 */

#ifndef SERVER_SERVER_H_
#define SERVER_SERVER_H_

#include <string>
#include "common_Socket.h"
#include "server_ThreadSafeHashMap.h"

class Server {
public:
	Server(const std::string& port);
	Server();
	virtual ~Server();
	void begin();

private:
	ThreadSafeHashMap *threadSafeMap;
	Socket *socket;
	void beginAccepting();
};

#endif /* SERVER_SERVER_H_ */
