/* 
 * File:   Player.h
 * Author: std07078
 *
 * Created on October 9, 2010, 7:35 PM
 */

#include <string>

using namespace std;
 enum status_enum {Waiting , Playing};

class Player {

private:
      enum status_enum status;
    

    unsigned int id;
    unsigned int losses,ties,wins,games,rival_id;
    string my_ip,rival_ip;
    
public:
    Player(unsigned int id,string my_ip);
   // Player(const Player& orig);
  
    virtual ~Player();

    void assign_rival(unsigned int , string );
    void assign_win();
    void assign_loss();
    void assign_tie();
    int getWins();
    int getLosses();
    int getTies();
    int getGames();
    enum status_enum getStatus();
    double getPercentage();



};