/*
 * Client.h
 *
 *  Created on: May 7, 2016
 *      Author: santi
 */

#ifndef CLIENT_CLIENT_H_
#define CLIENT_CLIENT_H_

#include <string>
#include "common_Socket.h"

class Client {
public:
	Client(const std::string& ip, const std::string& port);
	Client();
	virtual ~Client();
	void begin();

private:
	Socket *socket;
};

#endif /* CLIENT_CLIENT_H_ */
