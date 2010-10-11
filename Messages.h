//
// File:   Messages.h
// Author: std07078
//
// Created on October 8, 2010, 1:09 PM
//




#define MAX 128; //kai poly tou paei
#define RCV_SUCCESS 100;
#define RCV_FAILURE -100;
#define RCV_PLAY 10;
#include <iostream>
#include<cstdio>
#include <cstdlib>
#include <cstring>
#include <cerrno>
#include <string>

using namespace std;

void send_play(int socket);
int parse_message(int socket);
bool is_play(string);
bool is_endgame(string);
void send_symbol(int socket, char symbol,int turn, string ip);
void read_sp_reply(int socket);
