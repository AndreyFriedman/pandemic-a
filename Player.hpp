#pragma once
#include <string>
#include <iostream>

#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"

using namespace std;

namespace pandemic{

    class Player{
        public:
        Board b;
        City c;
        Player(const Board& b,City c){}
        Player&  drive(City c);
        Player&  fly_direct(City c);
        Player&  fly_charter(City c);
        Player&  fly_shuttle(City c);
        Player&  build();
        Player&  discover_cure(Color c);
        Player&  treat(City c);

        std::string role();
        Player& take_card(City c);
    };
}