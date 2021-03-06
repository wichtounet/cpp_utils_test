//=======================================================================
// Copyright (c) 2014-2016 Baptiste Wicht
// Distributed under the terms of the MIT License.
// (See accompanying file LICENSE or copy at
//  http://opensource.org/licenses/MIT)
//=======================================================================

#include <string>
#include <sstream>

#include "doctest/doctest.h"

#include "cpp_utils/streams.hpp"

TEST_CASE( "streams/1" ) {
    std::vector<std::string> strings{"asdf","","pop","123"};

    std::stringstream stream;

    using cpp::operator<<;
    stream << strings;

    REQUIRE(stream.str() == "[asdf, , pop, 123]");
}

TEST_CASE( "streams/2" ) {
    std::vector<int> ints{1,2,3,99,0,-1,1};

    std::stringstream stream;

    using cpp::operator<<;
    stream << ints;

    REQUIRE(stream.str() == "[1, 2, 3, 99, 0, -1, 1]");
}

TEST_CASE( "streams/3" ) {
    std::vector<int> ints;

    std::stringstream stream;

    using cpp::operator<<;
    stream << ints;

    REQUIRE(stream.str() == "[]");
}
