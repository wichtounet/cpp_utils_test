//=======================================================================
// Copyright (c) 2014-2015 Baptiste Wicht
// Distributed under the terms of the MIT License.
// (See accompanying file LICENSE or copy at
//  http://opensource.org/licenses/MIT)
//=======================================================================

#undef NDEBUG
#define CPP_UTILS_ASSERT_EXCEPTION

#include "catch.hpp"

#include "cpp_utils/assert.hpp"

TEST_CASE( "assert/1", "[assert]" ) {
    REQUIRE_THROWS(cpp_assert(false, "message"));
    REQUIRE_NOT_THROWS(cpp_assert(true, "message"));
}
