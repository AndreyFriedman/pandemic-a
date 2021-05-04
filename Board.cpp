#include "Board.hpp"


namespace pandemic{


        int& Board::operator [] (City c){
            return this -> diseaseNum[c];
        }
        bool Board::is_clean(){
            return false;
        }
        std::ostream& operator << (std::ostream& bap, const Board& b){
            return bap;
        }

}