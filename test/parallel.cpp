//=======================================================================
// Copyright (c) 2014-2016 Baptiste Wicht
// Distributed under the terms of the MIT License.
// (See accompanying file LICENSE or copy at
//  http://opensource.org/licenses/MIT)
//=======================================================================

#include <string>
#include <numeric>

#include "catch.hpp"

#include "cpp_utils/parallel.hpp"

TEST_CASE( "parallel_foreach_n/1", "[parallel]" ) {
    std::vector<int> ints{0, 1, 2, 3, 4, 5, 6};

    cpp::parallel_foreach_n(0, 7, [&ints](std::size_t a){
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

TEST_CASE( "parallel_foreach/1", "[parallel]" ) {
    std::vector<int> ints{0, 1, 2, 3, 4, 5, 6};

    cpp::parallel_foreach(ints.begin(), ints.end(), [&ints](int a){
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

TEST_CASE( "parallel_foreach/2", "[parallel]" ) {
    std::vector<int> ints{0, 1, 2, 3, 4, 5, 6};

    cpp::parallel_foreach(ints, [&ints](int a){
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

TEST_CASE( "parallel_foreach_i/1", "[parallel]" ) {
    std::vector<int> ints{-1,2,0,3,4,1};

    cpp::parallel_foreach_i(ints.begin(), ints.end(), [&ints](int /*a*/, std::size_t i){
        ints[i] = i;
    });

    REQUIRE(ints[0] == 0);
    REQUIRE(ints[1] == 1);
    REQUIRE(ints[2] == 2);
    REQUIRE(ints[3] == 3);
    REQUIRE(ints[4] == 4);
    REQUIRE(ints[5] == 5);
}

TEST_CASE( "parallel_foreach_i/2", "[parallel]" ) {
    std::vector<int> ints{-1,2,0,3,4,1};

    cpp::parallel_foreach_i(ints, [&ints](int /*a*/, std::size_t i){
        ints[i] = i;
    });

    REQUIRE(ints[0] == 0);
    REQUIRE(ints[1] == 1);
    REQUIRE(ints[2] == 2);
    REQUIRE(ints[3] == 3);
    REQUIRE(ints[4] == 4);
    REQUIRE(ints[5] == 5);
}

TEST_CASE( "parallel_foreach_i_only/1", "[parallel]" ) {
    std::vector<int> ints{-1,2,0,3,4,1};

    cpp::parallel_foreach_i_only(ints.begin(), ints.end(), [&ints](std::size_t i){
        ints[i] = i;
    });

    REQUIRE(ints[0] == 0);
    REQUIRE(ints[1] == 1);
    REQUIRE(ints[2] == 2);
    REQUIRE(ints[3] == 3);
    REQUIRE(ints[4] == 4);
    REQUIRE(ints[5] == 5);
}

TEST_CASE( "parallel_foreach_i_only/2", "[parallel]" ) {
    std::vector<int> ints{-1,2,0,3,4,1};

    cpp::parallel_foreach_i_only(ints, [&ints](std::size_t i){
        ints[i] = i;
    });

    REQUIRE(ints[0] == 0);
    REQUIRE(ints[1] == 1);
    REQUIRE(ints[2] == 2);
    REQUIRE(ints[3] == 3);
    REQUIRE(ints[4] == 4);
    REQUIRE(ints[5] == 5);
}

TEST_CASE( "tp/parallel_foreach_n/1", "[parallel]" ) {
    std::vector<int> ints{0, 1, 2, 3, 4, 5, 6};

    cpp::default_thread_pool<> pool;
    cpp::parallel_foreach_n(pool, 0, 7, [&ints](std::size_t a){
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

TEST_CASE( "tp/parallel_foreach/1", "[parallel]" ) {
    std::vector<int> ints{0, 1, 2, 3, 4, 5, 6};

    cpp::default_thread_pool<> pool;
    cpp::parallel_foreach(pool, ints.begin(), ints.end(), [&ints](int a){
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

TEST_CASE( "tp/parallel_foreach/2", "[parallel]" ) {
    std::vector<int> ints{0, 1, 2, 3, 4, 5, 6};

    cpp::default_thread_pool<> pool;
    cpp::parallel_foreach(pool, ints, [&ints](int a){
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

TEST_CASE( "tp/parallel_foreach_i/1", "[parallel]" ) {
    std::vector<int> ints{-1,2,0,3,4,1};

    cpp::default_thread_pool<> pool;
    cpp::parallel_foreach_i(pool, ints.begin(), ints.end(), [&ints](int /*a*/, std::size_t i){
        ints[i] = i;
    });

    REQUIRE(ints[0] == 0);
    REQUIRE(ints[1] == 1);
    REQUIRE(ints[2] == 2);
    REQUIRE(ints[3] == 3);
    REQUIRE(ints[4] == 4);
    REQUIRE(ints[5] == 5);
}

TEST_CASE( "tp/parallel_foreach_i/2", "[parallel]" ) {
    std::vector<int> ints{-1,2,0,3,4,1};

    cpp::default_thread_pool<> pool;
    cpp::parallel_foreach_i(pool, ints, [&ints](int /*a*/, std::size_t i){
        ints[i] = i;
    });

    REQUIRE(ints[0] == 0);
    REQUIRE(ints[1] == 1);
    REQUIRE(ints[2] == 2);
    REQUIRE(ints[3] == 3);
    REQUIRE(ints[4] == 4);
    REQUIRE(ints[5] == 5);
}

TEST_CASE( "tp/parallel_foreach_i/3", "[parallel]" ) {
    std::vector<int> ints(109);

    std::iota(ints.begin(), ints.end(), 0);

    cpp::default_thread_pool<> pool;
    cpp::parallel_foreach_i(pool, ints, [&ints](int /*a*/, std::size_t i){
        ints[i] = i;
    });

    for(std::size_t i = 0; i < ints.size(); ++i){
        REQUIRE(ints[i] == i);
    }
}

TEST_CASE( "tp/parallel_foreach_i_only/1", "[parallel]" ) {
    std::vector<int> ints{-1,2,0,3,4,1};

    cpp::default_thread_pool<> pool;
    cpp::parallel_foreach_i_only(pool, ints.begin(), ints.end(), [&ints](std::size_t i){
        ints[i] = i;
    });

    REQUIRE(ints[0] == 0);
    REQUIRE(ints[1] == 1);
    REQUIRE(ints[2] == 2);
    REQUIRE(ints[3] == 3);
    REQUIRE(ints[4] == 4);
    REQUIRE(ints[5] == 5);
}

TEST_CASE( "tp/parallel_foreach_i_only/2", "[parallel]" ) {
    std::vector<int> ints{-1,2,0,3,4,1};

    cpp::default_thread_pool<> pool;
    cpp::parallel_foreach_i_only(pool, ints, [&ints](std::size_t i){
        ints[i] = i;
    });

    REQUIRE(ints[0] == 0);
    REQUIRE(ints[1] == 1);
    REQUIRE(ints[2] == 2);
    REQUIRE(ints[3] == 3);
    REQUIRE(ints[4] == 4);
    REQUIRE(ints[5] == 5);
}

TEST_CASE( "tp/parallel_foreach_it/1", "[parallel]" ) {
    std::vector<int> ints{-1,2,0,3,4,1};

    cpp::default_thread_pool<> pool;
    cpp::parallel_foreach_it(pool, ints, [](auto it){
        ++(*it);
    });

    REQUIRE(ints[0] == 0);
    REQUIRE(ints[1] == 3);
    REQUIRE(ints[2] == 1);
    REQUIRE(ints[3] == 4);
    REQUIRE(ints[4] == 5);
    REQUIRE(ints[5] == 2);
}

TEST_CASE( "tp/parallel_foreach_it/2", "[parallel]" ) {
    std::vector<int> ints(109);

    std::iota(ints.begin(), ints.end(), -5);

    cpp::default_thread_pool<> pool;
    cpp::parallel_foreach_it(pool, ints, [](auto it){
        ++(*it);
    });

    for(std::size_t i = 0; i < ints.size(); ++i){
        REQUIRE(ints[i] == -5 + int(i) + 1);
    }
}
