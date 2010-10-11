//
// File:   main.cc
// Author: std07078
//
// Created on October 8, 2010, 12:20 PM
//
#include <iostream>
//#include <cstdlib.h>
#include <cstdio>
#include <cstring>
//#include <cerrno.h>

//sockets & networking libs
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
////
//Threads//
#include <pthread.h>
//custom includes //

#include "SPConnectionsHandler.h"
#include "Messages.h"

#define MIN_ARGS 2
#define BAD_ARGS -99
#define NETWORK_UNREACHABLE -97





//
//
//
using namespace std;

int main(int argc, char** argv) {
  srandom((unsigned int) time(NULL));
  bool super_peer=false;
  int port = 8089; //listening port
  int current_id=0;

  if(argc<MIN_ARGS){
        cout<<"Insufficient arguments."<<endl;
      return BAD_ARGS;}
    if(!strcmp(argv[1],"SP"))
    {   cout<<"Super Peer started."<<endl;
        super_peer=true;}
    else if( !strcmp(argv[1],"P")){
        cout<<"Peer started."<<endl;
        super_peer=false;}
    else
    {   cout<<"Invalid arguments."<<endl;
        return BAD_ARGS;}

  if(super_peer==true){ //SUPER PEER CODE
      
      manage_connections(port);
      
      //a while should be here

      
      

      //connection management code was here//
      return 1;











  }






  else{ //PLAYER CODE

     /// CONNECT TO SUPER PEER/ COORDINATOR

    int sock1;
    unsigned int serverlen;
    struct sockaddr_in server2;
    struct sockaddr *serverptr2;
    struct hostent *rem;


    if ((sock1 = socket(PF_INET, SOCK_STREAM, 0)) < 0) { /* Create socket */
      perror("Create socket"); exit(1); }

   server2.sin_family = PF_INET;                      /* Internet domain */
   server2.sin_addr.s_addr = inet_addr("127.0.0.1");
   cout<<"I created a connx - player"<<endl;
   server2.sin_port = htons(port);
   serverptr2 = (struct sockaddr *) &server2;
   serverlen = sizeof server2;

   if (connect(sock1, serverptr2, serverlen) < 0) { /* Request connection */
        perror("Socket connection error");
        cout<<"Host not responding."<<endl;
        close(sock1);
        return NETWORK_UNREACHABLE; //should attempt to retry, really
 }


    ///CONNECTION ESTABLISHED ///
   cout<<"Connection established"<<endl;
   send_play(sock1);
      sleep(10);
   read_sp_reply(sock1);














   close(sock1);
   return 1;







  }









    return (EXIT_SUCCESS);
}
