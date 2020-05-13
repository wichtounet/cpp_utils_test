//=======================================================================
// Copyright (c) 2014-2016 Baptiste Wicht
// Distributed under the terms of the MIT License.
// (See accompanying file LICENSE or copy at
//  http://opensource.org/licenses/MIT)
//=======================================================================

#include <string>

#include "doctest/doctest.h"

#include "cpp_utils/array_wrapper.hpp"

TEST_CASE( "array_wrapper/1" ) {
    auto* mem = static_cast<float*>(malloc(sizeof(float) * 8));

    cpp::array_wrapper<float> array(mem, 7);
    const auto& array_c = array;

    REQUIRE(array.size() == 7);
    REQUIRE(array_c.size() == 7);

    for(std::size_t i = 0; i < 7; ++i){
        array[i] = i;
        REQUIRE(array[i] == float(i));
        REQUIRE(array_c[i] == float(i));
        REQUIRE(mem[i] == float(i));
    }

    int i = 0;
    for(auto& value : array){
        REQUIRE(value == float(i));
        ++i;
    }


    i = 0;
    for(auto& value : array_c){
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


    free(mem);
}
