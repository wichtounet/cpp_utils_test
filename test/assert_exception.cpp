//=======================================================================
// Copyright (c) 2014-2016 Baptiste Wicht
// Distributed under the terms of the MIT License.
// (See accompanying file LICENSE or copy at
//  http://opensource.org/licenses/MIT)
//=======================================================================

#undef NDEBUG
#define CPP_UTILS_ASSERT_EXCEPTION

#include "catch.hpp"

#include "cpp_utils/assert.hpp"

namespace {

int assert_wrapper(bool value){
    cpp_assert(value, "message");
    return 0;
}

} //end of namespace

TEST_CASE( "assert/exception/1", "[assert]" ) {
    REQUIRE_THROWS(assert_wrapper(false));
    REQUIRE_NOTHROW(assert_wrapper(true));
}
