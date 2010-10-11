


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

#include "Game.h"
#include "Player.h"


using namespace std;



void print_statistics(vector<Player> players, vector<Game> games);
