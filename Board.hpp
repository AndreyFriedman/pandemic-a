#pragma once
#include <unordered_map>
#include <ostream>

#include "City.hpp"
#include "Color.hpp"


namespace pandemic{

    class Board{
        public:
        std::unordered_map<City, int> diseaseNum;
        std::unordered_map<City, bool> station;
        
        int& operator [] (City c);
        bool is_clean();
        friend std::ostream& operator << (std::ostream& bap, const Board& b);
    };
}
