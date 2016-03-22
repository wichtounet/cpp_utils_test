//=======================================================================
// Copyright (c) 2014-2016 Baptiste Wicht
// Distributed under the terms of the MIT License.
// (See accompanying file LICENSE or copy at
//  http://opensource.org/licenses/MIT)
//=======================================================================

#include <string>

#include "catch.hpp"

#include "cpp_utils/string.hpp"

TEST_CASE( "ltrim", "ltrim" ) {
    std::string a = "    asdf";
    std::string b = "    asdf    ";
    std::string c = "asdf";

    REQUIRE(cpp::ltrim(a) == "asdf");
    REQUIRE(cpp::ltrim(b) == "asdf    ");
    REQUIRE(cpp::ltrim(c) == "asdf");

    REQUIRE(a == "asdf");
    REQUIRE(b == "asdf    ");
    REQUIRE(c == "asdf");
}

TEST_CASE( "rtrim", "rtrim" ) {
    std::string a = "    asdf";
    std::string b = "    asdf    ";
    std::string c = "asdf";
    std::string d = "asdf         ";

    REQUIRE(cpp::rtrim(a) == "    asdf");
    REQUIRE(cpp::rtrim(b) == "    asdf");
    REQUIRE(cpp::rtrim(c) == "asdf");
    REQUIRE(cpp::rtrim(d) == "asdf");

    REQUIRE(a == "    asdf");
    REQUIRE(b == "    asdf");
    REQUIRE(c == "asdf");
    REQUIRE(d == "asdf");
}

TEST_CASE( "trim", "trim" ) {
    std::string a = "    asdf";
    std::string b = "    asdf    ";
    std::string c = "asdf";
    std::string d = "asdf         ";

    REQUIRE(cpp::trim(a) == "asdf");
    REQUIRE(cpp::trim(b) == "asdf");
    REQUIRE(cpp::trim(c) == "asdf");
    REQUIRE(cpp::trim(d) == "asdf");

    REQUIRE(a == "asdf");
    REQUIRE(b == "asdf");
    REQUIRE(c == "asdf");
    REQUIRE(d == "asdf");
}
