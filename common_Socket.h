/*
 * Socket.h
 *
 *  Created on: May 7, 2016
 *      Author: santi
 */

#ifndef COMMON_SOCKET_H_
#define COMMON_SOCKET_H_

#include <string>

struct addrinfo;

#ifndef _POSIX_C_SOURCE
#define _POSIX_C_SOURCE 1
#endif

class Socket {
private:
	int fd;
	struct addrinfo* result;
public:
	// Simple constructor
	Socket();
	// Initiates 	with given parameters
	Socket(const char* ip, const char* port);
	// Free's socket resources
	virtual ~Socket();
	// Binds the socket to a connection
	int bind();
	// Listens for new connections, up to max queue size (blocker)
	int listen(int maxQueueSize);
	// Accepts new connection
	int accept(Socket* client) const;
	// Connects to server (blocker)
	int connect();
	// Receives size bytes from the net
	int receive(char* buffer, int size);
	// Sends size bytes over the net
	int send(char* buffer, int size);
	// Fetches available connections
	int select();
};

#endif /* COMMON_SOCKET_H_ */
