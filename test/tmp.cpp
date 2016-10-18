//=======================================================================
// Copyright (c) 2014-2016 Baptiste Wicht
// Distributed under the terms of the MIT License.
// (See accompanying file LICENSE or copy at
//  http://opensource.org/licenses/MIT)
//=======================================================================

#include <list>
#include <vector>

#include "catch.hpp"

#include "cpp_utils/tmp.hpp"

TEST_CASE( "tmp/variadic_contains/1", "[tmp]" ) {
    REQUIRE((cpp::variadic_contains<double, std::string, int, double>::value));
    REQUIRE(!(cpp::variadic_contains<double, std::string, int, long double>::value));
    REQUIRE((cpp::variadic_contains<std::string, std::string>::value));
    REQUIRE(!(cpp::variadic_contains<std::string>::value));
    REQUIRE(!(cpp::variadic_contains<std::string, double>::value));
}

TEST_CASE( "tmp/type_list/1", "[tmp]" ) {
    REQUIRE((cpp::type_list<std::string, double, int>::contains<int>()));
    REQUIRE(!(cpp::type_list<std::string, double, int>::contains<long int>()));
    REQUIRE((cpp::type_list<std::string>::contains<std::string>()));
    REQUIRE(!(cpp::type_list<>::contains<std::string>()));
}

TEST_CASE( "tmp/is_homogeneous/1", "[tmp]" ) {
    REQUIRE((cpp::is_homogeneous<std::size_t, std::size_t, unsigned long>::value));
    REQUIRE((cpp::is_homogeneous<int, int>::value));
    REQUIRE(!(cpp::is_homogeneous<int, long>::value));
    REQUIRE(!(cpp::is_homogeneous<std::string, long>::value));
    REQUIRE((cpp::is_homogeneous<long>::value));
}

TEST_CASE( "tmp/is_sub_homogeneous/1", "[tmp]" ) {
    REQUIRE(!(cpp::is_sub_homogeneous<>::value));
    REQUIRE(!(cpp::is_sub_homogeneous<int>::value));
    REQUIRE(!(cpp::is_sub_homogeneous<int, int>::value));
    REQUIRE((cpp::is_sub_homogeneous<int, double>::value));
    REQUIRE(!(cpp::is_sub_homogeneous<int, double, double>::value));
    REQUIRE((cpp::is_sub_homogeneous<int, int, double>::value));
    REQUIRE((cpp::is_sub_homogeneous<int, int, int, double>::value));
    REQUIRE(!(cpp::is_sub_homogeneous<int, int, double, double>::value));
}

TEST_CASE( "tmp/first_value/1", "[tmp]" ) {
    REQUIRE(cpp::first_value(1,"str",true) == 1);
    REQUIRE(cpp::first_value(std::string("str"),1,true) == "str");
    REQUIRE(!cpp::first_value(false,"str",1,true));
}

TEST_CASE( "tmp/last_value/1", "[tmp]" ) {
    REQUIRE(cpp::last_value(1,"str",true));
    REQUIRE(cpp::last_value("str",1,1) == 1);
    REQUIRE(cpp::last_value(false,"str",1,std::string("str2")) == "str2");
}

TEST_CASE( "tmp/nth_value/1", "[tmp]" ) {
    REQUIRE(cpp::nth_value<0>(1,"str",true) == 1);
    REQUIRE(cpp::nth_value<1>(1,std::string("str"),true) == "str");
    REQUIRE(cpp::nth_value<2>(1,std::string("str"),true));
}

TEST_CASE( "tmp/first_type/1", "[tmp]" ) {
    REQUIRE((std::is_same<cpp::first_type<int, char*, bool>::type, int>::value));
    REQUIRE((std::is_same<cpp::first_type<char*, int, bool>::type, char*>::value));
    REQUIRE((std::is_same<cpp::first_type<bool, int, int*>::type, bool>::value));
    REQUIRE((std::is_same<cpp::first_type<bool>::type, bool>::value));
}

TEST_CASE( "tmp/first_type/2", "[tmp]" ) {
    REQUIRE((std::is_same<cpp::first_type_t<int, char*, bool>, int>::value));
    REQUIRE((std::is_same<cpp::first_type_t<char*, int, bool>, char*>::value));
    REQUIRE((std::is_same<cpp::first_type_t<bool, int, int*>, bool>::value));
    REQUIRE((std::is_same<cpp::first_type_t<bool>, bool>::value));
}

TEST_CASE( "tmp/last_type/1", "[tmp]" ) {
    REQUIRE((std::is_same<cpp::last_type<int, char*, bool>::type, bool>::value));
    REQUIRE((std::is_same<cpp::last_type<char*, int, int*>::type, int*>::value));
    REQUIRE((std::is_same<cpp::last_type<bool, int, std::string>::type, std::string>::value));
    REQUIRE((std::is_same<cpp::last_type<bool>::type, bool>::value));
}

TEST_CASE( "tmp/last_type/2", "[tmp]" ) {
    REQUIRE((std::is_same<cpp::last_type_t<int, char*, bool>, bool>::value));
    REQUIRE((std::is_same<cpp::last_type_t<char*, int, int*>, int*>::value));
    REQUIRE((std::is_same<cpp::last_type_t<bool, int, std::string>, std::string>::value));
    REQUIRE((std::is_same<cpp::last_type_t<bool>, bool>::value));
}

TEST_CASE( "tmp/nth_type/1", "[tmp]" ) {
    REQUIRE((std::is_same<cpp::nth_type<0, int, char*, bool>::type, int>::value));
    REQUIRE((std::is_same<cpp::nth_type<1, int, char*, bool>::type, char*>::value));
    REQUIRE((std::is_same<cpp::nth_type<2, int, char*, bool>::type, bool>::value));
}

TEST_CASE( "tmp/nth_type/2", "[tmp]" ) {
    REQUIRE((std::is_same<cpp::nth_type_t<0, int, char*, bool>, int>::value));
    REQUIRE((std::is_same<cpp::nth_type_t<1, int, char*, bool>, char*>::value));
    REQUIRE((std::is_same<cpp::nth_type_t<2, int, char*, bool>, bool>::value));
}

TEST_CASE( "tmp/is_specialization/1", "[tmp]" ) {
    REQUIRE((cpp::is_specialization_of<std::vector,std::vector<double>>::value));
    REQUIRE((cpp::is_specialization_of<std::vector,std::vector<std::string>>::value));
    REQUIRE((cpp::is_specialization_of<std::list,std::list<std::string>>::value));
}

TEST_CASE( "tmp/add_const_lvalue_t/1", "[tmp]" ) {
    REQUIRE((std::is_same<cpp::add_const_lvalue_t<int>, const int&>::value));
    REQUIRE((std::is_same<cpp::add_const_lvalue_t<char>, const char&>::value));
    REQUIRE((std::is_same<cpp::add_const_lvalue_t<std::string>, const std::string&>::value));
    REQUIRE((std::is_same<cpp::add_const_lvalue_t<const int>, const int&>::value));
    REQUIRE((std::is_same<cpp::add_const_lvalue_t<const int&>, const int&>::value));
}

TEST_CASE( "tmp/add_const_rvalue_t/1", "[tmp]" ) {
    REQUIRE((std::is_same<cpp::add_const_rvalue_t<int>, const int&&>::value));
    REQUIRE((std::is_same<cpp::add_const_rvalue_t<char>, const char&&>::value));
    REQUIRE((std::is_same<cpp::add_const_rvalue_t<std::string>, const std::string&&>::value));
    REQUIRE((std::is_same<cpp::add_const_rvalue_t<const int>, const int&&>::value));
    REQUIRE((std::is_same<cpp::add_const_rvalue_t<const int&>, const int&>::value));
    REQUIRE((std::is_same<cpp::add_const_rvalue_t<const int&&>, const int&&>::value));
}

struct test_op {
    std::size_t int_op = 0;
    std::size_t double_op = 0;
    std::size_t string_op = 0;

    template<typename O>
    void operator()(){
        if(std::is_same<int, O>::value){
            ++int_op;
        }

        if(std::is_same<double, O>::value){
            ++double_op;
        }

        if(std::is_same<std::string, O>::value){
            ++string_op;
        }
    }
};

TEST_CASE( "tmp/for_each_tuple_t/1", "[tmp]" ) {
    test_op oo;

    using tuple_t_1 = std::tuple<int, std::string, int, char, char, double, double, std::string, std::string>;
    using tuple_t_2 = std::tuple<int, double>;
    using tuple_t_3 = std::tuple<>;

    cpp::for_each_tuple_t<tuple_t_1>(oo);

    REQUIRE(oo.int_op == 2);
    REQUIRE(oo.double_op == 2);
    REQUIRE(oo.string_op == 3);

    cpp::for_each_tuple_t<tuple_t_2>(oo);

    REQUIRE(oo.int_op == 3);
    REQUIRE(oo.double_op == 3);
    REQUIRE(oo.string_op == 3);

    cpp::for_each_tuple_t<tuple_t_3>(oo);

    REQUIRE(oo.int_op == 3);
    REQUIRE(oo.double_op == 3);
    REQUIRE(oo.string_op == 3);
}

TEST_CASE ("tmp/and_u/1", "[tmp]"){
    REQUIRE((!cpp::and_u<false, false>::value));
    REQUIRE((!cpp::and_u<true, true, true, false, true>::value));
    REQUIRE((cpp::and_u<true, true>::value));
    REQUIRE((!cpp::and_u<false, true>::value));
    REQUIRE((!cpp::and_u<false>::value));
    REQUIRE((cpp::and_u<true>::value));
}

TEST_CASE ("tmp/and_c/1", "[tmp]"){
    REQUIRE((!cpp::and_c<std::is_same<float, double>, std::is_same<double, double>>::value));
    REQUIRE((cpp::and_c<std::is_same<float, float>, std::is_same<void, void>>::value));
    REQUIRE((!cpp::and_c<std::is_same<float, double>, std::is_same<void, void>>::value));
    REQUIRE((!cpp::and_c<std::is_same<float, double>>::value));
    REQUIRE((cpp::and_c<std::is_same<void, void>>::value));
}
