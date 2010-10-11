/* 
 * File:   Game.h
 * Author: caroline
 *
 * Created on October 10, 2010, 5:20 PM
 */
#include <string>
using namespace std;

/* This is a class for storing data for ongoing games */
/* so that the coordinator can generate statistics */

class Game {
public:
    Game(unsigned int,unsigned int,unsigned int);
    
    virtual ~Game();
    unsigned int get_Game_id(){return game_id;}
    unsigned int get_Player1_id(){return player1_id;}
    unsigned int get_Player2_id(){return player2_id;}
private:
    unsigned int game_id;
    unsigned int player1_id;
    unsigned int player2_id;
    string player1_ip;
    string player2_ip;

};


