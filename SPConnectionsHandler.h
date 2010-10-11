/* 
 * File:   SPConnectionsHandler.h
 * Author: std07078
 *
 * Created on October 9, 2010, 2:23 PM
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include <pthread.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <vector>       //STL vector

//custon includes//
#include "Messages.h"


using namespace std;


int manage_connections(int );
int thread_accept_connection();
void *manage_player(void* );