




#include "Messages.h"

using namespace std;


void read_sp_reply(int socket){ //Read reply from super peer
    //containing data for game

   int max=MAX;
   int characters_read=0;
   char buf[max];

   while(characters_read<=max ){
       if (read(socket, buf + characters_read, 1) < 0){
           perror("Player Read from Coordinator");
           //kai edw ti kanoume? mallon kleinoume to socket

       }
       cout<<"Buffer :"<<buf[characters_read]<<endl;
       if(buf[characters_read]=='\n'){

//           //cout<<"Reached end of message."<<endl;
           // cout<<characters_read;
            buf[characters_read+1]='\0';
            break;
       }

  characters_read++;

 }

 cout<<"Received message from coordinator "<<buf<<endl;





}





void send_symbol(int socket, char symbol, int turn, string rival_ip){

    int max=MAX;
    char buf[max];
    cout<<"before sprintf"<<endl;
   // int n=sprintf(buf, "shgkjdtrlgjrkh");
int n=sprintf(buf, "%c %s %d",symbol,rival_ip.c_str(),turn);
cout<<"after sprintf"<<endl;

buf[n]='\n';
int i;
//Send message to coordinator bit by bit :D
    	for(i=0; buf[i] != '\0'; i++) { /* For every char */
    	    /* Send i-th character */
        	if (write(socket, buf + i, 1) < 0)
        	   perror("Coordinator to Player Socket Write");

}
cout<<"Game rival data sent."<<endl;





}
void send_play(int socket){

char buf[8];

int n=sprintf(buf, "play");
buf[4]='\n';
int i;
//Send message to coordinator bit by bit :D
    	for(i=0; buf[i] != '\0'; i++) { /* For every char */
    	    /* Send i-th character */
        	if (write(socket, buf + i, 1) < 0)
        	   perror("Player to Coordinator Socket Write");

}
cout<<"Play Request sent."<<endl;

}

int parse_message(int socket){

    int max=MAX;
   int characters_read=0;
   char buf[max];

   while(characters_read<=max ){
       if (read(socket, buf + characters_read, 1) < 0){
           perror("Coordinator Read from Player");
           //kai edw ti kanoume? mallon kleinoume to socket

       }
       cout<<"Buffer :"<<buf[characters_read]<<endl;
       if(buf[characters_read]=='\n'){

//           //cout<<"Reached end of message."<<endl;
           // cout<<characters_read;
            buf[characters_read+1]='\0';
            break;
       }

  characters_read++;

 }

 cout<<"Received message "<<buf<<endl;

 string msg;
 msg=buf;
 if(is_play(msg)){

 //cout<<"Play request received"<<endl;
 return RCV_PLAY;
 }

  else if(is_endgame(msg)){

  cout<<"Game ended"<<endl;
  //should update statistics
  return RCV_SUCCESS;
  }

   else{
     cout<<"Message format not recognized. Message Ignored"<<endl;
    return RCV_FAILURE;}


}

bool is_play(string msg){
if(msg.compare("play\n")!=0)
    return false;
return true;}

bool is_endgame(string msg){ //not quite done


if(msg.compare("Win\n")==0)
    return true;

return false;}

