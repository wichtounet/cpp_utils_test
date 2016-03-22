//=======================================================================
// Copyright (c) 2014-2016 Baptiste Wicht
// Distributed under the terms of the MIT License.
// (See accompanying file LICENSE or copy at
//  http://opensource.org/licenses/MIT)
//=======================================================================

#include <string>
#include <sstream>

#include "catch.hpp"

#include "cpp_utils/static_if.hpp"

TEST_CASE( "static_if/1", "[static_if]" ) {
    int value = 42;

    cpp::static_if<true>([&value](auto){
        value = 1;
    });

    REQUIRE(value == 1);
}

TEST_CASE( "static_if/2", "[static_if]" ) {
    int value = 42;

    cpp::static_if<false>([&value](auto){
        value = 1;
    });

    REQUIRE(value == 42);
}

TEST_CASE( "static_if/3", "[static_if]" ) {
    int value = 42;

    cpp::static_if<false>([&value](auto){
        value = 1;
    }).else_([&value](auto){
        value = 2;
    });

    REQUIRE(value == 2);
}

TEST_CASE( "static_if/4", "[static_if]" ) {
    int value = 42;

    cpp::static_if<true>([&value](auto f){
        f(value) = 1;
    }).else_([&value](auto f){
        f(value) = 2;
    });

    REQUIRE(value == 1);
}
