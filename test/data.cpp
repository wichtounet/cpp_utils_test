//=======================================================================
// Copyright (c) 2014-2016 Baptiste Wicht
// Distributed under the terms of the MIT License.
// (See accompanying file LICENSE or copy at
//  http://opensource.org/licenses/MIT)
//=======================================================================

#include <vector>
#include <list>

#include "doctest/doctest.h"

#include "cpp_utils/data.hpp"

#define Approx doctest::Approx

TEST_CASE( "mean/1" ) {
    std::vector<int> a{1,2,3,4,5};

    REQUIRE(cpp::mean(a) == 3);
    REQUIRE(cpp::mean(a.begin(), a.end()) == 3);
}

TEST_CASE( "mean/2" ) {
    std::vector<int> a{-5,1,4,3,4,5};

    REQUIRE(cpp::mean(a) == 2);
    REQUIRE(cpp::mean(a.begin(), a.end()) == 2);
}

TEST_CASE( "mean/3" ) {
    std::vector<double> a{-5.3,1.5,-2.3,3.93,4.23,5.25};

    REQUIRE(cpp::mean(a) == Approx(1.218333));
    REQUIRE(cpp::mean(a.begin(), a.end()) == Approx(1.218333));
}

TEST_CASE( "stddev/1" ) {
    std::vector<int> a{1,2,3,4,5};

    REQUIRE(cpp::stddev(a, 3) == Approx(1.41421));
    REQUIRE(cpp::stddev(a.begin(), a.end(), 3) == Approx(1.41421));
}

TEST_CASE( "stddev/2" ) {
    std::vector<int> a{-5,1,4,3,4,5};

    REQUIRE(cpp::stddev(a, 2) == Approx(3.366501));
    REQUIRE(cpp::stddev(a.begin(), a.end(), 2) == Approx(3.366501));
}

TEST_CASE( "stddev/3" ) {
    std::vector<double> a{-5.3,1.5,-2.3,3.93,4.23,5.25};

    REQUIRE(cpp::stddev(a, 1.218333) == Approx(3.82152));
    REQUIRE(cpp::stddev(a.begin(), a.end(), 1.218333) == Approx(3.82152));
}

TEST_CASE( "normalize/1" ) {
    std::vector<double> a{1,2,3,4,5};

    cpp::normalize(a);

    REQUIRE(cpp::mean(a) == Approx(0.0));
    REQUIRE(cpp::mean(a.begin(), a.end()) == Approx(0.0));
    REQUIRE(cpp::stddev(a, 0.0) == Approx(1.0));
    REQUIRE(cpp::stddev(a.begin(), a.end(), 0.0) == Approx(1.0));
}

TEST_CASE( "normalize/2" ) {
    std::vector<double> a{-5,1,4,3,4,5};

    cpp::normalize(a);

    REQUIRE(cpp::mean(a) == Approx(0.0));
    REQUIRE(cpp::mean(a.begin(), a.end()) == Approx(0.0));
    REQUIRE(cpp::stddev(a, 0.0) == Approx(1.0));
    REQUIRE(cpp::stddev(a.begin(), a.end(), 0.0) == Approx(1.0));
}

TEST_CASE( "normalize/3" ) {
    std::vector<double> a{-5.3,1.5,-2.3,3.93,4.23,5.25};

    cpp::normalize(a);

    REQUIRE(cpp::mean(a) == Approx(0.0));
    REQUIRE(cpp::mean(a.begin(), a.end()) == Approx(0.0));
    REQUIRE(cpp::stddev(a, 0.0) == Approx(1.0));
    REQUIRE(cpp::stddev(a.begin(), a.end(), 0.0) == Approx(1.0));
}
