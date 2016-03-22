//=======================================================================
// Copyright (c) 2014-2016 Baptiste Wicht
// Distributed under the terms of the MIT License.
// (See accompanying file LICENSE or copy at
//  http://opensource.org/licenses/MIT)
//=======================================================================

#include <list>
#include <vector>
#include <thread>
#include <sstream>

#include "catch.hpp"

#include "cpp_utils/stop_watch.hpp"

TEST_CASE( "watch/1", "[watch]" ) {
    cpp::stop_watch<> watch;
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    REQUIRE(watch.elapsed() > 0);
}

TEST_CASE( "watch/2", "[watch]" ) {
    std::stringstream stream;

    auto backup = std::cout.rdbuf();

    auto psbuf = stream.rdbuf();

    std::cout.rdbuf(psbuf);

    {
        cpp::auto_stop_watch<> watch("title");
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
    }

    std::cout.rdbuf(backup);

    REQUIRE(stream.str().size() == 14);
}
