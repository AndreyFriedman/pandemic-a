#include <string>
#include <iostream>

#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"

namespace pandemic{

        Player&  Player::drive(City c){
            return *this;
        }
        Player&  Player::fly_direct(City c){
            return *this;
        }
        Player&  Player::fly_charter(City c){
            return *this;
        }
        Player&  Player::fly_shuttle(City c){
            return *this;
        }
        Player&  Player::build(){
            return *this;
        }
        Player&  Player::discover_cure(Color c){
            return *this;
        }
        Player&  Player::treat(City c){
            return *this;
        }

        std::string Player::role(){
            string s;
            return s;
        }
        Player& Player::take_card(City c){
            return *(this);
        }
        
    
}