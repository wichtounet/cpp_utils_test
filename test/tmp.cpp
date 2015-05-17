//=======================================================================
// Copyright (c) 2015 Baptiste Wicht
// Distributed under the terms of the MIT License.
// (See accompanying file LICENSE or copy at
//  http://opensource.org/licenses/MIT)
//=======================================================================

#include "catch.hpp"

#include "cpp_utils/tmp.hpp"

TEST_CASE( "tmp/variadic_contains/1", "[tmp]" ) {
    REQUIRE((cpp::variadic_contains<double, std::string, int, double>::value));
    REQUIRE(!(cpp::variadic_contains<double, std::string, int, long double>::value));
    REQUIRE((cpp::variadic_contains<std::string, std::string>::value));
    REQUIRE(!(cpp::variadic_contains<std::string>::value));
    REQUIRE(!(cpp::variadic_contains<std::string, double>::value));
}

TEST_CASE( "tmp/type_list/1", "[tmp]" ) {
    REQUIRE((cpp::type_list<std::string, double, int>::contains<int>()));
    REQUIRE(!(cpp::type_list<std::string, double, int>::contains<long int>()));
    REQUIRE((cpp::type_list<std::string>::contains<std::string>()));
    REQUIRE(!(cpp::type_list<>::contains<std::string>()));
}

TEST_CASE( "tmp/is_homegeneous/1", "[tmp]" ) {
    REQUIRE((cpp::is_homogeneous<std::size_t, std::size_t, unsigned long>::value));
    REQUIRE((cpp::is_homogeneous<int, int>::value));
    REQUIRE(!(cpp::is_homogeneous<int, long>::value));
    REQUIRE(!(cpp::is_homogeneous<std::string, long>::value));
    REQUIRE((cpp::is_homogeneous<long>::value));
}
