#pragma once

#include "Player.hpp"

namespace pandemic{

    class Scientist : public Player{
        public:
        Scientist (Board& b, City c, int n): Player(b,c){

        }
        using Player::Player;
    };
}