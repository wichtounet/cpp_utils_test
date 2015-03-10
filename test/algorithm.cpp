//=======================================================================
// Copyright (c) 2014-2015 Baptiste Wicht
// Distributed under the terms of the MIT License.
// (See accompanying file LICENSE or copy at
//  http://opensource.org/licenses/MIT)
//=======================================================================

#include <vector>
#include <list>

#include "catch.hpp"

#include "cpp_utils/algorithm.hpp"

TEST_CASE( "foreach/container", "foreach_1" ) {
    std::vector<int> a{1,2,3,4,5};

    int sum = 0;

    cpp::foreach(a, [&sum](auto& v){ sum += v; });

    REQUIRE(sum == 15);
}

TEST_CASE( "foreach/range", "foreach_2" ) {
    std::vector<int> a{1,2,3,4,5};

    int sum = 0;
    cpp::foreach(a.begin(), a.end(), [&sum](auto& v){ sum += v; });

    REQUIRE(sum == 15);
}

TEST_CASE( "foreach/references", "foreach_3" ) {
    std::vector<int> a{1,2,3,4,5};

    int sum = 0;
    cpp::foreach(a.begin(), a.end(), [&sum](auto& v){ v += 1; });

    REQUIRE(a[0] == 2);
    REQUIRE(a[1] == 3);
    REQUIRE(a[2] == 4);
    REQUIRE(a[3] == 5);
    REQUIRE(a[4] == 6);
}

TEST_CASE( "foreach_it/container", "foreach_it_1" ) {
    std::vector<int> a{1,2,3,4,5};

    int sum = 0;

    cpp::foreach_it(a, [&sum](auto it){ sum += *it; });

    REQUIRE(sum == 15);
}

TEST_CASE( "foreach_it/range", "foreach_it_2" ) {
    std::vector<int> a{1,2,3,4,5};

    int sum = 0;
    cpp::foreach_it(a.begin(), a.end(), [&sum](auto it){ sum += *it; });

    REQUIRE(sum == 15);
}

TEST_CASE( "foreach_it/references", "foreach_it_3" ) {
    std::vector<int> a{1,2,3,4,5};

    int sum = 0;
    cpp::foreach_it(a.begin(), a.end(), [&sum](auto v){ *v += 1; });

    REQUIRE(a[0] == 2);
    REQUIRE(a[1] == 3);
    REQUIRE(a[2] == 4);
    REQUIRE(a[3] == 5);
    REQUIRE(a[4] == 6);
}

TEST_CASE( "foreach_i/container", "foreach_i_1" ) {
    std::vector<int> a{1,2,3,4,5};

    int sum_1 = 0;
    int sum_2 = 0;

    cpp::foreach_i(a,
        [&sum_1,&sum_2,&a](auto& v, std::size_t i){ REQUIRE(a[i] == v); sum_1 += v; sum_2 += a[i];});

    REQUIRE(sum_1 == 15);
    REQUIRE(sum_2 == 15);
}

TEST_CASE( "foreach_i/range", "foreach_i_2" ) {
    std::vector<int> a{1,2,3,4,5};

    int sum_1 = 0;
    int sum_2 = 0;

    cpp::foreach_i(a.begin(), a.end(),
        [&sum_1,&sum_2,&a](auto& v, std::size_t i){ REQUIRE(a[i] == v); sum_1 += v; sum_2 += a[i];});

    REQUIRE(sum_1 == 15);
    REQUIRE(sum_2 == 15);
}

TEST_CASE( "foreach_i/references", "foreach_i_3" ) {
    std::vector<int> a{1,2,3,4,5};

    cpp::foreach_i(a.begin(), a.end(),
        [&a](auto& v, std::size_t i){ v += 1; a[i] += 1; });

    REQUIRE(a[0] == 3);
    REQUIRE(a[1] == 4);
    REQUIRE(a[2] == 5);
    REQUIRE(a[3] == 6);
    REQUIRE(a[4] == 7);
}

TEST_CASE( "foreach_i/list", "foreach_i_4" ) {
    std::list<int> a{1,2,3,4,5};

    int sum = 0;
    cpp::foreach_i(a.begin(), a.end(),
        [&sum](auto& v, std::size_t i){ v += 1; sum += i; });

    REQUIRE(sum == 10);

    auto it = a.begin();
    REQUIRE(*it++ == 2);
    REQUIRE(*it++ == 3);
    REQUIRE(*it++ == 4);
    REQUIRE(*it++ == 5);
    REQUIRE(*it++ == 6);
}

TEST_CASE( "foreach_pair/container", "foreach_pair_1" ) {
    std::vector<int> a{1,2,3,4,5};

    int i = 0;

    cpp::foreach_pair(a,
        [&i](auto& v1, auto& v2){ REQUIRE(v1 != v2); ++i;});

    REQUIRE(i == 10);
}

TEST_CASE( "foreach_pair/range", "foreach_pair_2" ) {
    std::vector<int> a{1,2,3,4,5};

    int i = 0;

    cpp::foreach_pair(a.begin(), a.end(),
        [&i](auto& v1, auto& v2){ REQUIRE(v1 != v2); ++i;});

    REQUIRE(i == 10);
}

TEST_CASE( "foreach_pair_it/container", "foreach_pair_it_1" ) {
    std::vector<int> a{1,2,3,4,5};

    int i = 0;

    cpp::foreach_pair_it(a,
        [&i](auto i1, auto i2){ REQUIRE(*i1 != *i2); ++i;});

    REQUIRE(i == 10);
}

TEST_CASE( "foreach_pair_it/range", "foreach_pair_it_2" ) {
    std::vector<int> a{1,2,3,4,5};

    int i = 0;

    cpp::foreach_pair_it(a.begin(), a.end(),
        [&i](auto i1, auto i2){ REQUIRE(*i1 != *i2); ++i;});

    REQUIRE(i == 10);
}
