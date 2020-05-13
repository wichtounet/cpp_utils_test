//=======================================================================
// Copyright (c) 2014-2016 Baptiste Wicht
// Distributed under the terms of the MIT License.
// (See accompanying file LICENSE or copy at
//  http://opensource.org/licenses/MIT)
//=======================================================================

#include <string>

#include "doctest/doctest.h"

#include "cpp_utils/likely.hpp"

TEST_CASE( "likely" ) {
    std::string a = "asdf";
    std::string b = "asdf";

    bool ok = false;
    if(cpp_likely(a == b)){
        ok = true;
    } else {
        ok = false;
    }

    REQUIRE(ok);
}

TEST_CASE( "unlikely" ) {
    std::string a = "asdf";
    std::string b = "asdf";

    bool ok = false;
    if(cpp_unlikely(a == b)){
        ok = true;
    } else {
        ok = false;
    }

    REQUIRE(ok);
}
