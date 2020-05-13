//=======================================================================
// Copyright (c) 2014-2016 Baptiste Wicht
// Distributed under the terms of the MIT License.
// (See accompanying file LICENSE or copy at
//  http://opensource.org/licenses/MIT)
//=======================================================================

#include <string>
#include <iostream>

#include "doctest/doctest.h"

#include "cpp_utils/soft_aligned_array.hpp"

TEST_CASE( "soft_aligned_array/1" ) {
    cpp::soft_aligned_array<float, 7, 32> array;

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

TEST_CASE( "soft_aligned_array/2" ) {
    cpp::soft_aligned_array<double, 7, 64> array;

    REQUIRE(array.size() == 7);
    REQUIRE((reinterpret_cast<size_t>(array.data()) % 64) == 0);

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

TEST_CASE( "soft_aligned_array/3" ) {
    alignas(32) cpp::soft_aligned_array<float, 7, 32> array;

    REQUIRE(array.size() == 7);
    REQUIRE((reinterpret_cast<size_t>(array.data()) % 32) == 0);
    REQUIRE((reinterpret_cast<size_t>(&array) % 32) == 0);
    REQUIRE(reinterpret_cast<size_t>(array.data()) == reinterpret_cast<size_t>(&array));

    for(std::size_t i = 0; i < 7; ++i){
        array[i] = i;
        REQUIRE(array[i] == float(i));
    }
}

// Aligned dynamic allocation for over-aligned type is only guaranteed starting
// from C++17

#if __cpp_aligned_new >= 201606

TEST_CASE( "soft_aligned_array/4" ) {
    using type = cpp::soft_aligned_array<float, 7, 32>;
    auto* array = new type;

    REQUIRE(array->size() == 7);
    REQUIRE((reinterpret_cast<size_t>(array->data()) % 32) == 0);

    for(std::size_t i = 0; i < 7; ++i){
        (*array)[i] = i;
        REQUIRE((*array)[i] == float(i));
    }

    int i = 0;
    for(auto& value : *array){
        REQUIRE(value == float(i));
        ++i;
    }

    i = 0;
    auto it = array->cbegin();
    auto end = array->cend();
    while(it != end){
        REQUIRE(*it == float(i));
        ++it;
        ++i;
    }

    i = 6;
    auto rit = array->crbegin();
    auto rend = array->crend();
    while(rit != rend){
        CHECK(*rit == float(i));
        ++rit;
        --i;
    }

    std::cout << "shoudl2" << std::endl;
}

#endif
