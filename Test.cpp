/** 
 * AUTHORS: Matan Blaich
 * Date: 2021-03
 */
#include "Board.hpp"
#include "doctest.h"
#include <iostream>
#include <string>
#include <climits>
#define SIZE 10
using namespace std;



TEST_CASE("Corners"){
    ariel :: Board b; 
    //fail
    CHECK_THROWS(b.post(sizeof(b) - 1, sizeof(b) - 1, ariel::Direction::Horizontal, "South East"));
    //success
    b.post(sizeof(b) - 1, 0, ariel::Direction::Horizontal, "South West");
    CHECK(b.read(sizeof(b) - 1, 0, ariel::Direction::Horizontal, SIZE)==string("South West")); 
    //fail
    CHECK_THROWS(b.post(0, sizeof(b) - 1, ariel::Direction::Horizontal, "North East"));
    //success
    b.post(0, 0, ariel::Direction::Horizontal, "North West");
    CHECK(b.read(sizeof(b) - 1, 0, ariel::Direction::Horizontal, SIZE)==string("North West")); \

    //fail
    CHECK_THROWS(b.post(sizeof(b) - 1, sizeof(b) - 1, ariel::Direction::Vertical, "South East"));
    //fail
    CHECK_THROWS(b.post(sizeof(b) - 1, 0, ariel::Direction::Vertical, "South West"));
    //success
    CHECK_THROWS(b.post(0, sizeof(b) - 1, ariel::Direction::Vertical, "North East"));
    CHECK(b.read(0, sizeof(b) - 1, ariel::Direction::Vertical, SIZE)==string("North East")); 
    //success
    b.post(0, 0, ariel::Direction::Vertical, "North West");
    CHECK(b.read(sizeof(b) - 1, 0, ariel::Direction::Vertical, SIZE)==string("North West")); 
}



TEST_CASE("OVERRIDE") {
    ariel :: Board b;
    b.post(sizeof(b) - 1, 0, ariel::Direction::Horizontal, "South West");
    b.post(sizeof(b) - 1, 1, ariel::Direction::Horizontal, "West West");
    CHECK(b.read(sizeof(b) - 1, 0, ariel::Direction::Horizontal, SIZE) == string("SWest West"));
    b.post(0, 0, ariel::Direction::Vertical , "North West");
    b.post(1, 0, ariel::Direction::Vertical, "orth West");
    CHECK(b.read(0, 0, ariel::Direction::Vertical, SIZE) == string("North West"));
    b.post(0, 0, ariel::Direction::Vertical , "South West");
    CHECK_FALSE(b.read(0, 0, ariel::Direction::Vertical, SIZE) == string("North West"));
    b.post(0, 0, ariel::Direction::Vertical , "North West");
    CHECK(b.read(0, 0, ariel::Direction::Vertical, SIZE) == string("North West"));
}


TEST_CASE("Start On Right Feet") {
    ariel :: Board b;
    CHECK_THROWS(b.read(sizeof(b) - 1, sizeof(b) - 1, ariel::Direction::Vertical, SIZE));
    CHECK_THROWS(b.read(sizeof(b) - 1, sizeof(b) - 1, ariel::Direction::Horizontal, SIZE));
    CHECK_FALSE(b.read(0, 0, ariel::Direction::Horizontal, SIZE) == string("________"));
    CHECK_FALSE(b.read(0, 0, ariel::Direction::Vertical, SIZE) == string("_______"));



    CHECK(b.read(0, 0, ariel::Direction::Horizontal, SIZE) == string("__________"));
    b.post(sizeof(b) - 1, 0, ariel::Direction::Horizontal, "South West");
    CHECK(b.read(0, 0, ariel::Direction::Vertical, SIZE) == string("__________"));
    b.post(4, 0, ariel::Direction::Horizontal, "South West");//____S____
    CHECK_FALSE(b.read(0, 0, ariel::Direction::Vertical, SIZE) == string("__________"));

    CHECK(b.read(0, 0, ariel::Direction::Vertical, SIZE) == string("__________"));
    b.post(0, sizeof(b) - 1, ariel::Direction::Vertical, "North East");
    CHECK(b.read(0, sizeof(b) - 2, ariel::Direction::Vertical, SIZE) == string("__________"));
    b.post(4, sizeof(b) - 1, ariel::Direction::Vertical, "North East");//___North East
    CHECK_FALSE(b.read(0, 0, ariel::Direction::Vertical, SIZE) == string("__________"));
}





 