
#include "SPConnectionsHandler.h"
#include "Player.h"


using namespace std;


vector<pthread_t*> peerthreads;
vector<Player> players;
uint established_connections=0;

int manage_connections(int port){

    
      int lsock;
      //START LISTENING FOR CONNECTIONS :)
      if ((lsock = socket(PF_INET, SOCK_STREAM, 0)) < 0) {
      perror("Listening socket"); exit(1); }
      socklen_t clientlen ;
      socklen_t serverlen;
      struct sockaddr *serverptr;
      struct sockaddr_in client, server;
      struct sockaddr * clientptr;
      server.sin_family = PF_INET;
      server.sin_addr.s_addr=htonl(INADDR_ANY);
      server.sin_port = htons(port); //port needs configuration
      serverptr = (struct sockaddr *) &server;
      serverlen = sizeof server;
      if ( bind (lsock,serverptr,sizeof(server) ) < 0){
        perror("Listening socket bind " );
        exit(1);   }
      if (listen(lsock,SOMAXCONN) < 0){
        perror("Listening connections");
        exit(1);}

      cout<<"Organiser "<<"Initialized and waits for connections on port "<<port<<endl;



      while(1){
        int newsock;
        clientptr = (struct sockaddr *) &client;
        clientlen = sizeof client;
        if((  (newsock = accept (lsock,clientptr, &clientlen))< 0) ) {
            perror("Client Connection Accept");
            exit(1);
        }
        cout<<"New incoming connection"<<endl;
        int err;
        pthread_t *tempthread = new pthread_t;

        peerthreads.push_back(tempthread);
        if (err = pthread_create(tempthread, NULL, manage_player,(void *) &newsock )) { /* New thread */
            perror("pthread_create");
            exit(1);
        }

        
        //parse_message(newsock);

        sleep(5);
      }
}


void *manage_player(void* arg){

    if (int err = pthread_detach(pthread_self())) {/* Detach thread */
       perror("pthread_detach");
       exit(1);
    } //should do it outside?
   
    int * sockptr = (int*) arg;
    int sock =*sockptr;

    struct sockaddr_in newaddress;
    socklen_t newaddress_len;
    getpeername(sock,(struct sockaddr*) &newaddress,&newaddress_len);
    established_connections++;
    uint newid = established_connections;

    //ids.push_back(newid);

    cout<<"Received connection from peer "<<inet_ntoa(newaddress.sin_addr)<<" Attributed id "<<newid<<endl;
    int bla=RCV_PLAY;
    if(parse_message(sock)==bla){

        
        
        Player *newplayer = new Player(newid,inet_ntoa(newaddress.sin_addr));
        players.push_back(*newplayer);
        cout<<"I am sending"<<endl;
        send_symbol(sock,'o',1,"fagshfgskj");
        sleep(5);
     /*  while(newplayer->getStatus()==Waiting){
            sleep(5);



            break;

       }


      */




    }
    
    //thread terminate
    pthread_exit(NULL);
}