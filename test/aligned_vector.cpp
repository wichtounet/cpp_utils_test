//=======================================================================
// Copyright (c) 2014-2016 Baptiste Wicht
// Distributed under the terms of the MIT License.
// (See accompanying file LICENSE or copy at
//  http://opensource.org/licenses/MIT)
//=======================================================================

#include <vector>

#include "catch.hpp"

#include "cpp_utils/aligned_vector.hpp"

TEST_CASE( "aligned_vector/1", "[array_wrapper]" ) {
    cpp::aligned_vector<float, 32> array(7);

    REQUIRE(array.size() == 7);
    REQUIRE((reinterpret_cast<size_t>(array.data()) % 32) == 0);

    for(std::size_t i = 0; i < 7; ++i){
        array[i] = i;
        REQUIRE(array[i] == float(i));
    }

    int i = 0;
    for(auto& value : array){
        REQUIRE(value == float(i));
        ++i;
    }

    i = 0;
    auto it = array.cbegin();
    auto end = array.cend();
    while(it != end){
        REQUIRE(*it == float(i));
        ++it;
        ++i;
    }

    i = 6;
    auto rit = array.crbegin();
    auto rend = array.crend();
    while(rit != rend){
        CHECK(*rit == float(i));
        ++rit;
        --i;
    }
}

TEST_CASE( "aligned_vector/2", "[array_wrapper]" ) {
    cpp::aligned_vector<double, 48> array(7);

    REQUIRE(array.size() == 7);
    REQUIRE((reinterpret_cast<size_t>(array.data()) % 48) == 0);

    for(std::size_t i = 0; i < 7; ++i){
        array[i] = i;
        REQUIRE(array[i] == double(i));
    }

    int i = 0;
    for(auto& value : array){
        REQUIRE(value == double(i));
        ++i;
    }

    i = 0;
    auto it = array.cbegin();
    auto end = array.cend();
    while(it != end){
        REQUIRE(*it == double(i));
        ++it;
        ++i;
    }

    i = 6;
    auto rit = array.crbegin();
    auto rend = array.crend();
    while(rit != rend){
        CHECK(*rit == double(i));
        ++rit;
        --i;
    }
}
