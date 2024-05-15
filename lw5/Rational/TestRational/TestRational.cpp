#include <iostream>
#include "..\..\..\catch2\catch.hpp"
#include "..\Rational\CRational.h"


SCENARIO("ReverseLines")
{
	std::ostringstream output;
	WHEN("input stream is empty")
	{
		std::istringstream input("");
		THEN("output stream is also empty")
		{
			ReverseLines(input, output);
			CHECK(output.str().empty());
			CHECK(input.eof());
		}
	}
}