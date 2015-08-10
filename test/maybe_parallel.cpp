//=======================================================================
// Copyright (c) 2014-2015 Baptiste Wicht
// Distributed under the terms of the MIT License.
// (See accompanying file LICENSE or copy at
//  http://opensource.org/licenses/MIT)
//=======================================================================

#include <string>

#include "catch.hpp"

#include "cpp_utils/parallel.hpp"
#include "cpp_utils/maybe_parallel.hpp"

TEST_CASE( "thread_pool<true>/parallel_foreach/1", "[parallel]" ) {
    std::vector<int> ints{0, 1, 2, 3, 4, 5, 6};

    cpp::thread_pool<true> tp;

    cpp::maybe_parallel_foreach(tp, ints.begin(), ints.end(), [&ints](int a){
        ++ints[a];
    });

    REQUIRE(ints[0] == 1);
    REQUIRE(ints[1] == 2);
    REQUIRE(ints[2] == 3);
    REQUIRE(ints[3] == 4);
    REQUIRE(ints[4] == 5);
    REQUIRE(ints[5] == 6);
    REQUIRE(ints[6] == 7);
}

TEST_CASE( "thread_pool<true>/parallel_foreach/2", "[parallel]" ) {
    std::vector<int> ints{0, 1, 2, 3, 4, 5, 6};

    cpp::thread_pool<true> tp;

    cpp::maybe_parallel_foreach(tp, ints, [&ints](int a){
        ++ints[a];
    });

    REQUIRE(ints[0] == 1);
    REQUIRE(ints[1] == 2);
    REQUIRE(ints[2] == 3);
    REQUIRE(ints[3] == 4);
    REQUIRE(ints[4] == 5);
    REQUIRE(ints[5] == 6);
    REQUIRE(ints[6] == 7);
}

TEST_CASE( "thread_pool<true>/parallel_foreach_i/1", "[parallel]" ) {
    std::vector<int> ints{-1,2,0,3,4,1};

    cpp::thread_pool<true> tp;

    cpp::maybe_parallel_foreach_i(tp, ints.begin(), ints.end(), [&ints](int /*a*/, std::size_t i){
        ints[i] = i;
    });

    REQUIRE(ints[0] == 0);
    REQUIRE(ints[1] == 1);
    REQUIRE(ints[2] == 2);
    REQUIRE(ints[3] == 3);
    REQUIRE(ints[4] == 4);
    REQUIRE(ints[5] == 5);
}

TEST_CASE( "thread_pool<true>/parallel_foreach_i/2", "[parallel]" ) {
    std::vector<int> ints{-1,2,0,3,4,1};

    cpp::thread_pool<true> tp;

    cpp::maybe_parallel_foreach_i(tp, ints, [&ints](int /*a*/, std::size_t i){
        ints[i] = i;
    });

    REQUIRE(ints[0] == 0);
    REQUIRE(ints[1] == 1);
    REQUIRE(ints[2] == 2);
    REQUIRE(ints[3] == 3);
    REQUIRE(ints[4] == 4); REQUIRE(ints[5] == 5);
}

TEST_CASE( "thread_pool<true>/parallel_foreach_n/1", "[parallel]" ) {
    std::vector<int> ints{0, 1, 2, 3, 4, 5, 6};

    cpp::thread_pool<true> tp;

    cpp::maybe_parallel_foreach_n(tp, 0, 7, [&ints](std::size_t a){
        ++ints[a];
    });

    REQUIRE(ints[0] == 1);
    REQUIRE(ints[1] == 2);
    REQUIRE(ints[2] == 3);
    REQUIRE(ints[3] == 4);
    REQUIRE(ints[4] == 5);
    REQUIRE(ints[5] == 6);
    REQUIRE(ints[6] == 7);
}

TEST_CASE( "thread_pool<false>/parallel_foreach/1", "[parallel]" ) {
    std::vector<int> ints{0, 1, 2, 3, 4, 5, 6};

    cpp::thread_pool<false> tp;

    cpp::maybe_parallel_foreach(tp, ints.begin(), ints.end(), [&ints](int a){
        ++ints[a];
    });

    REQUIRE(ints[0] == 1);
    REQUIRE(ints[1] == 2);
    REQUIRE(ints[2] == 3);
    REQUIRE(ints[3] == 4);
    REQUIRE(ints[4] == 5);
    REQUIRE(ints[5] == 6);
    REQUIRE(ints[6] == 7);
}

TEST_CASE( "thread_pool<false>/parallel_foreach/2", "[parallel]" ) {
    std::vector<int> ints{0, 1, 2, 3, 4, 5, 6};

    cpp::thread_pool<false> tp;

    cpp::maybe_parallel_foreach(tp, ints, [&ints](int a){
        ++ints[a];
    });

    REQUIRE(ints[0] == 1);
    REQUIRE(ints[1] == 2);
    REQUIRE(ints[2] == 3);
    REQUIRE(ints[3] == 4);
    REQUIRE(ints[4] == 5);
    REQUIRE(ints[5] == 6);
    REQUIRE(ints[6] == 7);
}

TEST_CASE( "thread_pool<false>/parallel_foreach_i/1", "[parallel]" ) {
    std::vector<int> ints{-1,2,0,3,4,1};

    cpp::thread_pool<false> tp;

    cpp::maybe_parallel_foreach_i(tp, ints.begin(), ints.end(), [&ints](int /*a*/, std::size_t i){
        ints[i] = i;
    });

    REQUIRE(ints[0] == 0);
    REQUIRE(ints[1] == 1);
    REQUIRE(ints[2] == 2);
    REQUIRE(ints[3] == 3);
    REQUIRE(ints[4] == 4);
    REQUIRE(ints[5] == 5);
}

TEST_CASE( "thread_pool<false>/parallel_foreach_i/2", "[parallel]" ) {
    std::vector<int> ints{-1,2,0,3,4,1};

    cpp::thread_pool<false> tp;

    cpp::maybe_parallel_foreach_i(tp, ints, [&ints](int /*a*/, std::size_t i){
        ints[i] = i;
    });

    REQUIRE(ints[0] == 0);
    REQUIRE(ints[1] == 1);
    REQUIRE(ints[2] == 2);
    REQUIRE(ints[3] == 3);
    REQUIRE(ints[4] == 4); REQUIRE(ints[5] == 5);
}

TEST_CASE( "thread_pool<false>/parallel_foreach_n/1", "[parallel]" ) {
    std::vector<int> ints{0, 1, 2, 3, 4, 5, 6};

    cpp::thread_pool<false> tp;

    cpp::maybe_parallel_foreach_n(tp, 0, 7, [&ints](std::size_t a){
        ++ints[a];
    });

    REQUIRE(ints[0] == 1);
    REQUIRE(ints[1] == 2);
    REQUIRE(ints[2] == 3);
    REQUIRE(ints[3] == 4);
    REQUIRE(ints[4] == 5);
    REQUIRE(ints[5] == 6);
    REQUIRE(ints[6] == 7);
}
