//=======================================================================
// Copyright (c) 2014-2016 Baptiste Wicht
// Distributed under the terms of the MIT License.
// (See accompanying file LICENSE or copy at
//  http://opensource.org/licenses/MIT)
//=======================================================================

#undef NDEBUG

#include <iostream>
#include "catch.hpp"

namespace std {

void redefined_abort(){
    throw 1;
}

} //end of namespace std

#define abort redefined_abort

#include "cpp_utils/assert.hpp"

namespace {

int assert_wrapper(bool value){
    cpp_assert(value, "message");
    return 0;
}

} //end of namespace

TEST_CASE( "assert/message/1", "[assert]" ) {
    std::stringstream stream;
    auto out = std::cerr.rdbuf();
    std::cerr.rdbuf(stream.rdbuf());

    REQUIRE_THROWS(assert_wrapper(false));
    auto message = stream.str();


#ifdef __clang__
    REQUIRE(message == "***** Internal Program Error - assertion (value) failed in int (anonymous namespace)::assert_wrapper(bool):\ntest/assert.cpp(28): message\n");
#else
    REQUIRE(message == "***** Internal Program Error - assertion (value) failed in int {anonymous}::assert_wrapper(bool):\ntest/assert.cpp(28): message\n");
#endif

    std::cerr.rdbuf(out);

    REQUIRE_NOTHROW(assert_wrapper(true));
}
