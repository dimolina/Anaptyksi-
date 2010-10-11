/* 
 * File:   Player.cpp
 * Author: std07078
 * 
 * Created on October 9, 2010, 7:35 PM
 */

#include "Player.h"



Player::Player(unsigned int id,string my_ip) {
    this->id= id;
    this->my_ip=my_ip;
    this->status=Waiting;



}

void Player::assign_rival(unsigned int id, string ip){
    this->rival_id=id;
    this->rival_ip=ip;

}


void Player::assign_win(){

    this->games++;
    this->wins++;
}

void Player::assign_loss(){

    this->games++;
    this->losses++;
}

void Player::assign_tie(){

    this->games++;
    this->ties++;
}

int Player::getWins(){return wins;}
int Player::getLosses(){return losses;}
int Player::getTies(){return ties;}
int Player::getGames(){return games;}
enum status_enum Player::getStatus(){return status;}

double Player::getPercentage(){
    if(games==0) return 0;

    else return  100 * (double)wins/(double) games;


}



Player::~Player() {
}

