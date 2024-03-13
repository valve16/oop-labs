#define CATCH_CONFIG_MAIN
#include <..\..\catch2\catch.hpp>

#include "pch.h"
#include <DecodeString\StringProcess.h>

TEST_CASE("divide_vector_on_half_of_max_element")
{
	CHECK(2 + 2 == 4);
	CHECK(2 + 4 == 6);
	REQUIRE(2 + 2 == 4);
	CHECK(Test(2, 4) == 6);
}