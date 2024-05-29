#define CATCH_CONFIG_MAIN
#include "../../../catch2/catch.hpp"
#include "../CMyList/CMyList.h"
#include <iostream>

TEST_CASE("CMyList default constructor initializes an empty list", "[CMyList]") {
    CMyList<int> list;
    REQUIRE(list.GetSize() == 0);
}

TEST_CASE("CMyList copy constructor creates a correct copy", "[CMyList]") {
    CMyList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    CMyList<int> copy(list);
    REQUIRE(copy.GetSize() == 3);
    auto it = copy.begin();
    REQUIRE(*it == 1);
    ++it;
    REQUIRE(*it == 2);
    ++it;
    REQUIRE(*it == 3);
}

TEST_CASE("CMyList move constructor moves elements correctly", "[CMyList]") {
    CMyList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    CMyList<int> moved(std::move(list));
    REQUIRE(moved.GetSize() == 3);
    REQUIRE(list.GetSize() == 0);
    auto it = moved.begin();
    REQUIRE(*it == 1);
    ++it;
    REQUIRE(*it == 2);
    ++it;
    REQUIRE(*it == 3);
}

TEST_CASE("CMyList copy assignment operator copies elements correctly", "[CMyList]") {
    CMyList<int> list1;
    list1.push_back(1);
    list1.push_back(2);
    list1.push_back(3);

    CMyList<int> list2;
    list2 = list1;

    REQUIRE(list2.GetSize() == 3);
    auto it = list2.begin();
    REQUIRE(*it == 1);
    ++it;
    REQUIRE(*it == 2);
    ++it;
    REQUIRE(*it == 3);
}

TEST_CASE("CMyList move assignment operator moves elements correctly", "[CMyList]") {
    CMyList<int> list1;
    list1.push_back(1);
    list1.push_back(2);
    list1.push_back(3);

    CMyList<int> list2;
    list2 = std::move(list1);

    REQUIRE(list2.GetSize() == 3);
    REQUIRE(list1.GetSize() == 0);
    auto it = list2.begin();
    REQUIRE(*it == 1);
    ++it;
    REQUIRE(*it == 2);
    ++it;
    REQUIRE(*it == 3);
}

TEST_CASE("CMyList push_front and push_back work correctly", "[CMyList]") {
    CMyList<int> list;
    list.push_front(1);
    list.push_back(2);
    list.push_front(0);

    REQUIRE(list.GetSize() == 3);
    auto it = list.begin();
    REQUIRE(*it == 0);
    ++it;
    REQUIRE(*it == 1);
    ++it;
    REQUIRE(*it == 2);
}

TEST_CASE("CMyList clear empties the list", "[CMyList]") {
    CMyList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.Clear();

    REQUIRE(list.GetSize() == 0);
    REQUIRE(list.begin() == list.end());
}

TEST_CASE("CMyList insert works correctly", "[CMyList]") {
    CMyList<int> list;
    list.push_back(1);
    list.push_back(3);

    auto it = list.begin();
    ++it;
    list.insert(it, 2);

    REQUIRE(list.GetSize() == 3);
    it = list.begin();
    REQUIRE(*it == 1);
    ++it;
    REQUIRE(*it == 2);
    ++it;
    REQUIRE(*it == 3);
}

TEST_CASE("CMyList erase works correctly", "[CMyList]") {
    CMyList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    auto it = list.begin();
    ++it;
    list.erase(it);

    REQUIRE(list.GetSize() == 2);
    it = list.begin();
    REQUIRE(*it == 1);
    ++it;
    REQUIRE(*it == 3);
}

TEST_CASE("CMyList reverse iterators work correctly", "[CMyList]") {
    CMyList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    auto rit = list.rbegin();
    REQUIRE(*rit == 3);
    ++rit;
    REQUIRE(*rit == 2);
    ++rit;
    REQUIRE(*rit == 1);
    ++rit;
    REQUIRE(rit == list.rend());
}