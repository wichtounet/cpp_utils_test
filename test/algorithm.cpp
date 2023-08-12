//=======================================================================
// Copyright (c) 2014-2016 Baptiste Wicht
// Distributed under the terms of the MIT License.
// (See accompanying file LICENSE or copy at
//  http://opensource.org/licenses/MIT)
//=======================================================================

#include <vector>
#include <list>

#include "doctest/doctest.h"

#include "cpp_utils/algorithm.hpp"

TEST_CASE( "foreach/container" ) {
    std::vector<int> a{1,2,3,4,5};

    int sum = 0;

    cpp::foreach(a, [&sum](auto& v){
        sum += v;
    });

    REQUIRE(sum == 15);
}

TEST_CASE( "foreach/range" ) {
    std::vector<int> a{1,2,3,4,5};

    int sum = 0;
    cpp::foreach(a.begin(), a.end(), [&sum](auto& v){
        sum += v;
    });

    REQUIRE(sum == 15);
}

TEST_CASE( "foreach/references" ) {
    std::vector<int> a{1,2,3,4,5};

    cpp::foreach(a.begin(), a.end(), [](auto& v){
        v += 1;
    });

    REQUIRE(a[0] == 2);
    REQUIRE(a[1] == 3);
    REQUIRE(a[2] == 4);
    REQUIRE(a[3] == 5);
    REQUIRE(a[4] == 6);
}

TEST_CASE( "foreach_it/container" ) {
    std::vector<int> a{1,2,3,4,5};

    int sum = 0;

    cpp::foreach_it(a, [&sum](auto it){
        sum += *it;
    });

    REQUIRE(sum == 15);
}

TEST_CASE( "foreach_it/range" ) {
    std::vector<int> a{1,2,3,4,5};

    int sum = 0;
    cpp::foreach_it(a.begin(), a.end(), [&sum](auto it){
        sum += *it;
    });

    REQUIRE(sum == 15);
}

TEST_CASE( "foreach_it/references" ) {
    std::vector<int> a{1,2,3,4,5};

    int sum = 0;
    cpp::foreach_it(a.begin(), a.end(), [&sum](auto v){
        *v += 1;
    });

    REQUIRE(a[0] == 2);
    REQUIRE(a[1] == 3);
    REQUIRE(a[2] == 4);
    REQUIRE(a[3] == 5);
    REQUIRE(a[4] == 6);
}

TEST_CASE( "foreach_i/container" ) {
    std::vector<int> a{1,2,3,4,5};

    int sum_1 = 0;
    int sum_2 = 0;

    cpp::foreach_i(a, [&sum_1,&sum_2,&a](auto& v, std::size_t i){
        REQUIRE(a[i] == v);
        sum_1 += v;
        sum_2 += a[i];
    });

    REQUIRE(sum_1 == 15);
    REQUIRE(sum_2 == 15);
}

TEST_CASE( "foreach_i/range" ) {
    std::vector<int> a{1,2,3,4,5};

    int sum_1 = 0;
    int sum_2 = 0;

    cpp::foreach_i(a.begin(), a.end(), [&sum_1,&sum_2,&a](auto& v, std::size_t i){
        REQUIRE(a[i] == v);
        sum_1 += v;
        sum_2 += a[i];
    });

    REQUIRE(sum_1 == 15);
    REQUIRE(sum_2 == 15);
}

TEST_CASE( "foreach_i/references" ) {
    std::vector<int> a{1,2,3,4,5};

    cpp::foreach_i(a.begin(), a.end(), [&a](auto& v, std::size_t i){
        v += 1;
        a[i] += 1;
    });

    REQUIRE(a[0] == 3);
    REQUIRE(a[1] == 4);
    REQUIRE(a[2] == 5);
    REQUIRE(a[3] == 6);
    REQUIRE(a[4] == 7);
}

TEST_CASE( "foreach_i/list" ) {
    std::list<int> a{1,2,3,4,5};

    int sum = 0;
    cpp::foreach_i(a.begin(), a.end(), [&sum](auto& v, std::size_t i){
        v += 1;
        sum += i;
    });

    REQUIRE(sum == 10);

    auto it = a.begin();
    REQUIRE(*it++ == 2);
    REQUIRE(*it++ == 3);
    REQUIRE(*it++ == 4);
    REQUIRE(*it++ == 5);
    REQUIRE(*it++ == 6);
}

TEST_CASE( "foreach_pair/container" ) {
    std::vector<int> a{1,2,3,4,5};

    int i = 0;

    cpp::foreach_pair(a, [&i](auto& v1, auto& v2){
        REQUIRE(v1 != v2);
        ++i;
    });

    REQUIRE(i == 10);
}

TEST_CASE( "foreach_pair/range" ) {
    std::vector<int> a{1,2,3,4,5};

    int i = 0;

    cpp::foreach_pair(a.begin(), a.end(), [&i](auto& v1, auto& v2){
        REQUIRE(v1 != v2);
        ++i;
    });

    REQUIRE(i == 10);
}

TEST_CASE( "foreach_pair_it/container" ) {
    std::vector<int> a{1,2,3,4,5};

    int i = 0;

    cpp::foreach_pair_it(a, [&i](auto i1, auto i2){
        REQUIRE(*i1 != *i2);
        ++i;
    });

    REQUIRE(i == 10);
}

TEST_CASE( "foreach_pair_it/range" ) {
    std::vector<int> a{1,2,3,4,5};

    int i = 0;

    cpp::foreach_pair_it(a.begin(), a.end(), [&i](auto i1, auto i2){
        REQUIRE(*i1 != *i2);
        ++i;
    });

    REQUIRE(i == 10);
}

TEST_CASE( "foreach_dual/container" ) {
    std::vector<int> a{1,2,3,4,5};
    std::vector<int> b{-1,-2,-3,-4,-5};

    int i = 0;

    cpp::foreach_dual(a, b, [&i](auto& v1, auto& v2){
        auto sum = v1 + v2;
        REQUIRE(sum == 0);
        ++i;
    });

    REQUIRE(i == 5);
}

TEST_CASE( "foreach_dual/iterators" ) {
    std::vector<int> a{1,2,3,4,5};
    std::vector<int> b{-1,-2,-3,-4,-5};

    int i = 0;

    cpp::foreach_dual(a.begin(), a.end(), b.begin(), [&i](auto& v1, auto& v2){
        auto sum = v1 + v2;
        REQUIRE(sum == 0);
        ++i;
    });

    REQUIRE(i == 5);
}

TEST_CASE( "foreach_dual_it/container" ) {
    std::vector<int> a{1,2,3,4,5};
    std::vector<int> b{-1,-2,-3,-4,-5};

    int i = 0;

    cpp::foreach_dual_it(a, b, [&i](auto v1, auto v2){
        auto sum = *v1 + *v2;
        REQUIRE(sum == 0);
        ++i;
    });

    REQUIRE(i == 5);
}

TEST_CASE( "foreach_dual_it/iterators" ) {
    std::vector<int> a{1,2,3,4,5};
    std::vector<int> b{-1,-2,-3,-4,-5};

    int i = 0;

    cpp::foreach_dual_it(a.begin(), a.end(), b.begin(), [&i](auto v1, auto v2){
        auto sum = *v1 + *v2;
        REQUIRE(sum == 0);
        ++i;
    });

    REQUIRE(i == 5);
}

TEST_CASE( "foreach_dual_i/container" ) {
    std::vector<int> a{1,2,3,4,5};
    std::vector<int> b{-1,-2,-3,-4,-5};

    int i = 0;
    int cc = 0;

    cpp::foreach_dual_i(a, b, [&i,&cc,&a,&b](auto& v1, auto& v2, std::size_t c){
        auto sum = v1 + v2;
        REQUIRE(sum == 0);
        REQUIRE(a[c] == v1);
        REQUIRE(b[c] == v2);
        ++i;
        cc += c;
    });

    REQUIRE(i == 5);
    REQUIRE(cc == 10);
}

TEST_CASE( "foreach_dual_i/iterators" ) {
    std::vector<int> a{1,2,3,4,5};
    std::vector<int> b{-1,-2,-3,-4,-5};

    int i = 0;
    int cc = 0;

    cpp::foreach_dual_i(a.begin(), a.end(), b.begin(), [&i,&cc,&a,&b](auto& v1, auto& v2, std::size_t c){
        auto sum = v1 + v2;
        REQUIRE(sum == 0);
        REQUIRE(a[c] == v1);
        REQUIRE(b[c] == v2);
        ++i;
        cc += c;
    });

    REQUIRE(i == 5);
    REQUIRE(cc == 10);
}

TEST_CASE( "foreach_n/1" ) {
    int i = 0;
    int cc = 0;

    cpp::foreach_n(0, 10, [&i, &cc](std::size_t value){
        ++i;
        cc += value;
    });

    REQUIRE(i == 10);
    REQUIRE(cc == 45);
}
