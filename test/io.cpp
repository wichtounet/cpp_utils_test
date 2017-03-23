//=======================================================================
// Copyright (c) 2014-2016 Baptiste Wicht
// Distributed under the terms of the MIT License.
// (See accompanying file LICENSE or copy at
//  http://opensource.org/licenses/MIT)
//=======================================================================

#include <string>
#include <fstream>

#include "catch.hpp"

#include "cpp_utils/io.hpp"

TEST_CASE( "binary/rw", "[binary]" ) {
    {
        std::ofstream os("test1.tmp.etl", std::ios::out | std::ios::binary);

        cpp::binary_write(os, static_cast<double>(2.2));
        cpp::binary_write(os, static_cast<char>('i'));
        cpp::binary_write(os, static_cast<float>(4.5f));
        cpp::binary_write(os, static_cast<int64_t>(1e8));
    }

    double a;
    char b;
    float c;
    int64_t d;

    std::ifstream is("test1.tmp.etl", std::ios::in | std::ios::binary);

    cpp::binary_load(is, a);
    cpp::binary_load(is, b);
    cpp::binary_load(is, c);
    cpp::binary_load(is, d);

    REQUIRE(a == 2.2);
    REQUIRE(b == 'i');
    REQUIRE(c == 4.5f);
    REQUIRE(d == 1e8);
}

TEST_CASE( "binary/rw_all", "[binary]" ) {
    {
        std::ofstream os("test2.tmp.etl", std::ios::out | std::ios::binary);

        std::vector<double> a{1.1, 2.2};
        std::vector<char> b{'c', 'd'};
        std::vector<float> c{4.5f, 6.0f};
        std::vector<int64_t> d{1000, 2};

        cpp::binary_write_all(os, a);
        cpp::binary_write_all(os, b);
        cpp::binary_write_all(os, c);
        cpp::binary_write_all(os, d);
    }


    std::vector<double> a(2);
    std::vector<char> b(2);
    std::vector<float> c(2);
    std::vector<int64_t> d(2);

    std::ifstream is("test2.tmp.etl", std::ios::in | std::ios::binary);

    cpp::binary_load_all(is, a);
    cpp::binary_load_all(is, b);
    cpp::binary_load_all(is, c);
    cpp::binary_load_all(is, d);

    REQUIRE(a[0] == 1.1);
    REQUIRE(a[1] == 2.2);
    REQUIRE(b[0] == 'c');
    REQUIRE(b[1] == 'd');
    REQUIRE(c[0] == 4.5f);
    REQUIRE(c[1] == 6.0f);
    REQUIRE(d[0] == 1000);
    REQUIRE(d[1] == 2);
}
