//=======================================================================
// Copyright (c) 2014-2016 Baptiste Wicht
// Distributed under the terms of the MIT License.
// (See accompanying file LICENSE or copy at
//  http://opensource.org/licenses/MIT)
//=======================================================================

#include <string>

#include "catch.hpp"

#include "cpp_utils/tuple_utils.hpp"

TEST_CASE( "tuple/for_each/1", "[tuple]" ) {
    auto tuple = std::make_tuple(std::string("asdf"), 42, std::string("false"), true, 1.0f, 'z');

    std::size_t string_cnt = 0;
    std::size_t int_cnt = 0;
    std::size_t bool_cnt = 0;
    std::size_t float_cnt = 0;
    std::size_t char_cnt = 0;

    cpp::for_each(tuple, [&](auto& a){
        if(std::is_same<std::string, std::decay_t<decltype(a)>>::value){
            ++string_cnt;
        }

        if(std::is_same<int, std::decay_t<decltype(a)>>::value){
            ++int_cnt;
        }

        if(std::is_same<bool, std::decay_t<decltype(a)>>::value){
            ++bool_cnt;
        }

        if(std::is_same<float, std::decay_t<decltype(a)>>::value){
            ++float_cnt;
        }

        if(std::is_same<char, std::decay_t<decltype(a)>>::value){
            ++char_cnt;
        }
    });

    REQUIRE(string_cnt == 2);
    REQUIRE(int_cnt == 1);
    REQUIRE(bool_cnt == 1);
    REQUIRE(float_cnt == 1);
    REQUIRE(char_cnt == 1);
}

TEST_CASE( "tuple/for_each_i/1", "[tuple]" ) {
    auto tuple = std::make_tuple(std::string("asdf"), 42, std::string("false"), true, 1.0f, 'z');

    std::size_t string_cnt = 0;
    std::size_t int_cnt = 0;
    std::size_t bool_cnt = 0;
    std::size_t float_cnt = 0;
    std::size_t char_cnt = 0;

    cpp::for_each_i(tuple, [&](std::size_t i, auto& a){
        if(std::is_same<std::string, std::decay_t<decltype(a)>>::value){
            string_cnt += i;
        }

        if(std::is_same<int, std::decay_t<decltype(a)>>::value){
            int_cnt += i;
        }

        if(std::is_same<bool, std::decay_t<decltype(a)>>::value){
            bool_cnt += i;
        }

        if(std::is_same<float, std::decay_t<decltype(a)>>::value){
            float_cnt += i;
        }

        if(std::is_same<char, std::decay_t<decltype(a)>>::value){
            char_cnt += i;
        }
    });

    REQUIRE(string_cnt == 2);
    REQUIRE(int_cnt == 1);
    REQUIRE(bool_cnt == 3);
    REQUIRE(float_cnt == 4);
    REQUIRE(char_cnt == 5);
}

TEST_CASE( "tuple/for_each_ix/1", "[tuple]" ) {
    auto tuple = std::make_tuple(std::string("asdf"), 42, std::string("false"), true, 1.0f, 'z');

    std::size_t string_cnt = 0;
    std::size_t int_cnt = 0;
    std::size_t bool_cnt = 0;
    std::size_t float_cnt = 0;
    std::size_t char_cnt = 0;

    cpp::for_each_ix(tuple, [&](auto ix, auto& a){
        static constexpr size_t i = decltype(ix)::value;

        if(std::is_same<std::string, std::decay_t<decltype(a)>>::value){
            string_cnt += i;
        }

        if(std::is_same<int, std::decay_t<decltype(a)>>::value){
            int_cnt += i;
        }

        if(std::is_same<bool, std::decay_t<decltype(a)>>::value){
            bool_cnt += i;
        }

        if(std::is_same<float, std::decay_t<decltype(a)>>::value){
            float_cnt += i;
        }

        if(std::is_same<char, std::decay_t<decltype(a)>>::value){
            char_cnt += i;
        }
    });

    REQUIRE(string_cnt == 2);
    REQUIRE(int_cnt == 1);
    REQUIRE(bool_cnt == 3);
    REQUIRE(float_cnt == 4);
    REQUIRE(char_cnt == 5);
}

TEST_CASE( "tuple/for_each_pair/1", "[tuple]" ) {
    auto tuple = std::make_tuple(std::string("asdf"), 42, true, 1.0f, 'z');

    bool string_int = false;
    bool int_bool = false;
    bool bool_float = false;
    bool float_char = false;

    cpp::for_each_pair(tuple, [&](auto& a, auto& b){
        if(std::is_same<std::string, std::decay_t<decltype(a)>>::value && std::is_same<int, std::decay_t<decltype(b)>>::value){
            string_int = true;
        }

        if(std::is_same<int, std::decay_t<decltype(a)>>::value && std::is_same<bool, std::decay_t<decltype(b)>>::value){
            int_bool = true;
        }

        if(std::is_same<bool, std::decay_t<decltype(a)>>::value && std::is_same<float, std::decay_t<decltype(b)>>::value){
            bool_float = true;
        }

        if(std::is_same<float, std::decay_t<decltype(a)>>::value && std::is_same<char, std::decay_t<decltype(b)>>::value){
            float_char = true;
        }
    });

    REQUIRE(string_int);
    REQUIRE(int_bool);
    REQUIRE(bool_float);
    REQUIRE(float_char);
}

TEST_CASE( "tuple/for_each_pair_i/1", "[tuple]" ) {
    auto tuple = std::make_tuple(std::string("asdf"), 42, true, 1.0f, 'z');

    bool string_int = false;
    bool int_bool = false;
    bool bool_float = false;
    bool float_char = false;

    cpp::for_each_pair_i(tuple, [&](std::size_t i, auto& a, auto& b){
        if(i == 0 && std::is_same<std::string, std::decay_t<decltype(a)>>::value && std::is_same<int, std::decay_t<decltype(b)>>::value){
            string_int = true;
        }

        if(i == 1 && std::is_same<int, std::decay_t<decltype(a)>>::value && std::is_same<bool, std::decay_t<decltype(b)>>::value){
            int_bool = true;
        }

        if(i == 2 && std::is_same<bool, std::decay_t<decltype(a)>>::value && std::is_same<float, std::decay_t<decltype(b)>>::value){
            bool_float = true;
        }

        if(i == 3 && std::is_same<float, std::decay_t<decltype(a)>>::value && std::is_same<char, std::decay_t<decltype(b)>>::value){
            float_char = true;
        }
    });

    REQUIRE(string_int);
    REQUIRE(int_bool);
    REQUIRE(bool_float);
    REQUIRE(float_char);
}

TEST_CASE( "tuple/for_each_pair_ix/1", "[tuple]" ) {
    auto tuple = std::make_tuple(std::string("asdf"), 42, true, 1.0f, 'z');

    bool string_int = false;
    bool int_bool = false;
    bool bool_float = false;
    bool float_char = false;

    cpp::for_each_pair_ix(tuple, [&](auto ix, auto& a, auto& b){
        static constexpr size_t i = decltype(ix)::value;

        if(i == 0 && std::is_same<std::string, std::decay_t<decltype(a)>>::value && std::is_same<int, std::decay_t<decltype(b)>>::value){
            string_int = true;
        }

        if(i == 1 && std::is_same<int, std::decay_t<decltype(a)>>::value && std::is_same<bool, std::decay_t<decltype(b)>>::value){
            int_bool = true;
        }

        if(i == 2 && std::is_same<bool, std::decay_t<decltype(a)>>::value && std::is_same<float, std::decay_t<decltype(b)>>::value){
            bool_float = true;
        }

        if(i == 3 && std::is_same<float, std::decay_t<decltype(a)>>::value && std::is_same<char, std::decay_t<decltype(b)>>::value){
            float_char = true;
        }
    });

    REQUIRE(string_int);
    REQUIRE(int_bool);
    REQUIRE(bool_float);
    REQUIRE(float_char);
}

TEST_CASE( "tuple/for_each_rpair/1", "[tuple]" ) {
    auto tuple = std::make_tuple(std::string("asdf"), 42, true, 1.0f, 'z');

    bool string_int = false;
    bool int_bool = false;
    bool bool_float = false;
    bool float_char = false;
    std::size_t cnt = 0;

    cpp::for_each_rpair(tuple, [&](auto& a, auto& b){
        if(cnt == 3 && std::is_same<std::string, std::decay_t<decltype(a)>>::value && std::is_same<int, std::decay_t<decltype(b)>>::value){
            string_int = true;
        }

        if(cnt == 2 && std::is_same<int, std::decay_t<decltype(a)>>::value && std::is_same<bool, std::decay_t<decltype(b)>>::value){
            int_bool = true;
        }

        if(cnt == 1 && std::is_same<bool, std::decay_t<decltype(a)>>::value && std::is_same<float, std::decay_t<decltype(b)>>::value){
            bool_float = true;
        }

        if(cnt == 0 && std::is_same<float, std::decay_t<decltype(a)>>::value && std::is_same<char, std::decay_t<decltype(b)>>::value){
            float_char = true;
        }

        ++cnt;
    });

    REQUIRE(string_int);
    REQUIRE(int_bool);
    REQUIRE(bool_float);
    REQUIRE(float_char);
}

TEST_CASE( "tuple/for_each_rpair_i/1", "[tuple]" ) {
    auto tuple = std::make_tuple(std::string("asdf"), 42, true, 1.0f, 'z');

    bool string_int = false;
    bool int_bool = false;
    bool bool_float = false;
    bool float_char = false;
    std::size_t cnt = 0;

    cpp::for_each_rpair_i(tuple, [&](std::size_t i, auto& a, auto& b){
        if(cnt == 3 && i == 0 && std::is_same<std::string, std::decay_t<decltype(a)>>::value && std::is_same<int, std::decay_t<decltype(b)>>::value){
            string_int = true;
        }

        if(cnt == 2 && i == 1 && std::is_same<int, std::decay_t<decltype(a)>>::value && std::is_same<bool, std::decay_t<decltype(b)>>::value){
            int_bool = true;
        }

        if(cnt == 1 && i == 2 && std::is_same<bool, std::decay_t<decltype(a)>>::value && std::is_same<float, std::decay_t<decltype(b)>>::value){
            bool_float = true;
        }

        if(cnt == 0 && i == 3 && std::is_same<float, std::decay_t<decltype(a)>>::value && std::is_same<char, std::decay_t<decltype(b)>>::value){
            float_char = true;
        }

        ++cnt;
    });

    REQUIRE(string_int);
    REQUIRE(int_bool);
    REQUIRE(bool_float);
    REQUIRE(float_char);
}

TEST_CASE( "tuple/for_each_rpair_ix/1", "[tuple]" ) {
    auto tuple = std::make_tuple(std::string("asdf"), 42, true, 1.0f, 'z');

    bool string_int = false;
    bool int_bool = false;
    bool bool_float = false;
    bool float_char = false;
    std::size_t cnt = 0;

    cpp::for_each_rpair_ix(tuple, [&](auto ix, auto& a, auto& b){
        static constexpr size_t i = decltype(ix)::value;

        if(cnt == 3 && i == 0 && std::is_same<std::string, std::decay_t<decltype(a)>>::value && std::is_same<int, std::decay_t<decltype(b)>>::value){
            string_int = true;
        }

        if(cnt == 2 && i == 1 && std::is_same<int, std::decay_t<decltype(a)>>::value && std::is_same<bool, std::decay_t<decltype(b)>>::value){
            int_bool = true;
        }

        if(cnt == 1 && i == 2 && std::is_same<bool, std::decay_t<decltype(a)>>::value && std::is_same<float, std::decay_t<decltype(b)>>::value){
            bool_float = true;
        }

        if(cnt == 0 && i == 3 && std::is_same<float, std::decay_t<decltype(a)>>::value && std::is_same<char, std::decay_t<decltype(b)>>::value){
            float_char = true;
        }

        ++cnt;
    });

    REQUIRE(string_int);
    REQUIRE(int_bool);
    REQUIRE(bool_float);
    REQUIRE(float_char);
}

TEST_CASE( "tuple/dual_for_each/1", "[tuple]" ) {
    auto t1 = std::make_tuple(std::string("asdf"), 42, true, 1.0f, 'z');
    auto t2 = std::make_tuple('z',               1.0f, true, 42, std::string("asdf"));

    bool string_char = false;
    bool int_float = false;
    bool bool_bool = false;
    bool float_int = false;
    bool char_string = false;
    std::size_t cnt = 0;

    cpp::for_each(t1, t2, [&](auto& a, auto& b){
        if(cnt == 0 && std::is_same<std::string, std::decay_t<decltype(a)>>::value && std::is_same<char, std::decay_t<decltype(b)>>::value){
            string_char = true;
        }

        if(cnt == 1 && std::is_same<int, std::decay_t<decltype(a)>>::value && std::is_same<float, std::decay_t<decltype(b)>>::value){
            int_float = true;
        }

        if(cnt == 2 && std::is_same<bool, std::decay_t<decltype(a)>>::value && std::is_same<bool, std::decay_t<decltype(b)>>::value){
            bool_bool = true;
        }

        if(cnt == 3 && std::is_same<float, std::decay_t<decltype(a)>>::value && std::is_same<int, std::decay_t<decltype(b)>>::value){
            float_int = true;
        }

        if(cnt == 4 && std::is_same<char, std::decay_t<decltype(a)>>::value && std::is_same<std::string, std::decay_t<decltype(b)>>::value){
            char_string = true;
        }

        ++cnt;
    });

    REQUIRE(string_char);
    REQUIRE(int_float);
    REQUIRE(bool_bool);
    REQUIRE(float_int);
    REQUIRE(char_string);
}

TEST_CASE( "tuple/dual_for_each_i/1", "[tuple]" ) {
    auto t1 = std::make_tuple(std::string("asdf"), 42, true, 1.0f, 'z');
    auto t2 = std::make_tuple('z',               1.0f, true, 42, std::string("asdf"));

    bool string_char = false;
    bool int_float = false;
    bool bool_bool = false;
    bool float_int = false;
    bool char_string = false;
    std::size_t cnt = 0;

    cpp::for_each_i(t1, t2, [&](std::size_t i, auto& a, auto& b){
        if(cnt == 0 && i == 0 && std::is_same<std::string, std::decay_t<decltype(a)>>::value && std::is_same<char, std::decay_t<decltype(b)>>::value){
            string_char = true;
        }

        if(cnt == 1 && i == 1 && std::is_same<int, std::decay_t<decltype(a)>>::value && std::is_same<float, std::decay_t<decltype(b)>>::value){
            int_float = true;
        }

        if(cnt == 2 && i == 2 && std::is_same<bool, std::decay_t<decltype(a)>>::value && std::is_same<bool, std::decay_t<decltype(b)>>::value){
            bool_bool = true;
        }

        if(cnt == 3 && i == 3 && std::is_same<float, std::decay_t<decltype(a)>>::value && std::is_same<int, std::decay_t<decltype(b)>>::value){
            float_int = true;
        }

        if(cnt == 4 && i == 4 && std::is_same<char, std::decay_t<decltype(a)>>::value && std::is_same<std::string, std::decay_t<decltype(b)>>::value){
            char_string = true;
        }

        ++cnt;
    });

    REQUIRE(string_char);
    REQUIRE(int_float);
    REQUIRE(bool_bool);
    REQUIRE(float_int);
    REQUIRE(char_string);
}

TEST_CASE( "tuple/dual_for_each_ix/1", "[tuple]" ) {
    auto t1 = std::make_tuple(std::string("asdf"), 42, true, 1.0f, 'z');
    auto t2 = std::make_tuple('z',               1.0f, true, 42, std::string("asdf"));

    bool string_char = false;
    bool int_float = false;
    bool bool_bool = false;
    bool float_int = false;
    bool char_string = false;
    std::size_t cnt = 0;

    cpp::for_each_ix(t1, t2, [&](auto ix, auto& a, auto& b){
        static constexpr size_t i = decltype(ix)::value;

        if(cnt == 0 && i == 0 && std::is_same<std::string, std::decay_t<decltype(a)>>::value && std::is_same<char, std::decay_t<decltype(b)>>::value){
            string_char = true;
        }

        if(cnt == 1 && i == 1 && std::is_same<int, std::decay_t<decltype(a)>>::value && std::is_same<float, std::decay_t<decltype(b)>>::value){
            int_float = true;
        }

        if(cnt == 2 && i == 2 && std::is_same<bool, std::decay_t<decltype(a)>>::value && std::is_same<bool, std::decay_t<decltype(b)>>::value){
            bool_bool = true;
        }

        if(cnt == 3 && i == 3 && std::is_same<float, std::decay_t<decltype(a)>>::value && std::is_same<int, std::decay_t<decltype(b)>>::value){
            float_int = true;
        }

        if(cnt == 4 && i == 4 && std::is_same<char, std::decay_t<decltype(a)>>::value && std::is_same<std::string, std::decay_t<decltype(b)>>::value){
            char_string = true;
        }

        ++cnt;
    });

    REQUIRE(string_char);
    REQUIRE(int_float);
    REQUIRE(bool_bool);
    REQUIRE(float_int);
    REQUIRE(char_string);
}
