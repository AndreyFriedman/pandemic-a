#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"

#include "Researcher.hpp"
#include "Scientist.hpp"
#include "FieldDoctor.hpp"
#include "GeneSplicer.hpp"
#include "OperationsExpert.hpp"
#include "Dispatcher.hpp"
#include "Medic.hpp"
#include "Virologist.hpp"

#include "doctest.h"
#include <string>
#include <iostream>

using namespace std;
using namespace pandemic;
Board b;

TEST_CASE("Board") {
    
    CHECK(b.is_clean() == true);
    b[City::Kinshasa] = 3;
    CHECK(b.is_clean() == false);

    Medic m {b, City::Kinshasa};
    m.treat(City::Kinshasa);
    CHECK(b.is_clean() == true);

    b[City::Kinshasa] = 3;
    Dispatcher d {b, City::Kinshasa};
    d.treat(City::Kinshasa);
    d.treat(City::Kinshasa);
    d.treat(City::Kinshasa);
    CHECK(b.is_clean() == true);
    CHECK_THROWS(d.treat(City::Kinshasa));

    CHECK_NOTHROW(d.drive(City::Washington));
    CHECK_NOTHROW(d.drive(City::Atlanta));
    CHECK_NOTHROW(d.drive(City::Atlanta));

    CHECK_THROWS(d.drive(City::Bangkok));

    d.take_card(City::Moscow);
    CHECK_NOTHROW(d.fly_direct(City::Moscow));

    d.drive(City::Istanbul);
    d.take_card(City::Istanbul);
    CHECK_NOTHROW(d.fly_charter(City::Atlanta));


    CHECK_NOTHROW(d.build());
    CHECK_NOTHROW(d.drive(City::Miami));
    CHECK_NOTHROW(d.build());

    CHECK_NOTHROW(d.fly_shuttle(City::Atlanta));
}
TEST_CASE("Roles") {
    Dispatcher d {b, City::Atlanta};
    CHECK(d.role() == "Dispatcher");
    
    FieldDoctor f {b, City::Atlanta};
    CHECK(f.role() == "FieldDoctor");
    
    GeneSplicer g {b, City::Atlanta};
    CHECK(g.role() == "GeneSplicer");
    
    Medic m {b, City::Atlanta};
    CHECK(m.role() == "Medic");
    
    OperationsExpert o {b, City::Atlanta};
    CHECK(o.role() == "OperationsExpert");
    
    Researcher r {b, City::Atlanta};
    CHECK(r.role() == "Researcher");
    
    Scientist s {b, City::Atlanta};
    CHECK(s.role() == "Scientist");
    
    Virologist v {b, City::Atlanta};
    CHECK(v.role() == "Virologist");


}



