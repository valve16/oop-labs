#define CATCH_CONFIG_MAIN
#include "../../../catch2/catch.hpp"
#include "..\Rational\CRational.h"
#include <iostream>


SCENARIO("Construct numbers")
{	
	WHEN("number 0")
	{
		CRational num;
		THEN("num = 0 denom = 1")
		{
			REQUIRE(num.GetNumerator() == 0);
			REQUIRE(num.GetDenominator() == 1);

		}
	}
	WHEN("number 5")
	{
		CRational num(5);
		THEN("num = 5 denom = 1")
		{
			REQUIRE(num.GetNumerator() == 5);
			REQUIRE(num.GetDenominator() == 1);

		}
	}
	WHEN("number(5, 1)")
	{
		CRational num(5, 1);
		THEN("num = 5 denom = 1")
		{
			REQUIRE(num.GetNumerator() == 5);
			REQUIRE(num.GetDenominator() == 1);
			REQUIRE(num.ToDouble() == 5.0);
		}
	}
	WHEN("number(2, 4)")
	{
		CRational num(2, 4);
		THEN("number will normilize to num = 1 denom = 2")
		{
			REQUIRE(num.GetNumerator() == 1);
			REQUIRE(num.GetDenominator() == 2);
			REQUIRE(num.ToDouble() == 0.5);
		}
	}
	WHEN("number(-2, 4)")
	{
		CRational num(-2, 4);
		THEN("number will normilize to num = -1 denom = 2")
		{
			REQUIRE(num.GetNumerator() == -1);
			REQUIRE(num.GetDenominator() == 2);
			REQUIRE(num.ToDouble() == -0.5);
		}
	}
	WHEN("number(2, -4)")
	{
		CRational num(2, -4);
		THEN("number will normilize to num = -1 denom = 2")
		{
			REQUIRE(num.GetNumerator() == -1);
			REQUIRE(num.GetDenominator() == 2);
			REQUIRE(num.ToDouble() == -0.5);
		}
	}
}

SCENARIO("check unary")
{
	WHEN("+")
	{
		CRational num(1, 4), checkUn;
		THEN("without change")
		{
			checkUn = +num;
			REQUIRE(checkUn.GetNumerator() == 1);
			REQUIRE(checkUn.GetDenominator() == 4);

		}
	}
	WHEN("-")
	{
		CRational num(1, 4), checkUn;
		THEN("opp sign")
		{
			checkUn = -num;
			REQUIRE(checkUn.GetNumerator() == -1);
			REQUIRE(checkUn.GetDenominator() == 4);

		}
	}
}

SCENARIO("check binary +")
{
	WHEN("two CRational(1/2 + 1/6)")
	{
		CRational first(1, 2), second(1, 6), checkBin;
		THEN("must be 2/3")
		{
			checkBin = first + second;
			REQUIRE(checkBin.GetNumerator() == 2);
			REQUIRE(checkBin.GetDenominator() == 3);

		}
	}
	WHEN("CRational and int (1/2 + 1)")
	{
		CRational first(1, 2), checkBin;
		THEN("must be 3/2")
		{
			checkBin = first + 1;
			REQUIRE(checkBin.GetNumerator() == 3);
			REQUIRE(checkBin.GetDenominator() == 2);

		}
	}
	WHEN("int and CRational(1 + 1/2)")
	{
		CRational first(1, 2),checkBin;
		THEN("must be 3/2")
		{
			checkBin = 1 + first;
			REQUIRE(checkBin.GetNumerator() == 3);
			REQUIRE(checkBin.GetDenominator() == 2);

		}
	}
	
}

SCENARIO("check binary -")
{
	WHEN("two CRational(1/2 - 1/6)")
	{
		CRational first(1, 2), second(1, 6), checkBin;
		THEN("must be 1/3")
		{
			checkBin = first - second;
			REQUIRE(checkBin.GetNumerator() == 1);
			REQUIRE(checkBin.GetDenominator() == 3);

		}
	}
	WHEN("CRational and int (1/2 - 1)")
	{
		CRational first(1, 2), checkBin;
		THEN("must be -1/2")
		{
			checkBin = first - 1;
			REQUIRE(checkBin.GetNumerator() == -1);
			REQUIRE(checkBin.GetDenominator() == 2);

		}
	}
	WHEN("int and CRational(1 - 1/2)")
	{
		CRational first(1, 2), checkBin;
		THEN("must be 1/2")
		{
			checkBin = 1 - first;
			REQUIRE(checkBin.GetNumerator() == 1);
			REQUIRE(checkBin.GetDenominator() == 2);

		}
	}

}

SCENARIO("check binary *")
{
	WHEN("two CRational(1/2 * 2/3)")
	{
		CRational first(1, 2), second(2, 3), checkBin;
		THEN("must be 1/3")
		{
			checkBin = first * second;
			REQUIRE(checkBin.GetNumerator() == 1);
			REQUIRE(checkBin.GetDenominator() == 3);

		}
	}
	WHEN("CRational and int (1/2 * (-3))")
	{
		CRational first(1, 2), checkBin;
		THEN("must be -3/2")
		{
			checkBin = first * (-3);
			REQUIRE(checkBin.GetNumerator() == -3);
			REQUIRE(checkBin.GetDenominator() == 2);

		}
	}
	WHEN("int and CRational(7 * 2/3)")
	{
		CRational first(2, 3), checkBin;
		THEN("must be 14/3")
		{
			checkBin = 7 * first;
			REQUIRE(checkBin.GetNumerator() == 14);
			REQUIRE(checkBin.GetDenominator() == 3);

		}
	}

}

SCENARIO("check binary /")
{
	WHEN("two CRational (1/2) / (2/3)")
	{
		CRational first(1, 2), second(2, 3), checkBin;
		THEN("must be 3/4")
		{
			checkBin = first / second;
			REQUIRE(checkBin.GetNumerator() == 3);
			REQUIRE(checkBin.GetDenominator() == 4);

		}
	}
	WHEN("CRational and int (1/2 / 5)")
	{
		CRational first(1, 2), checkBin;
		THEN("must be 1/10")
		{
			checkBin = first / 5;
			REQUIRE(checkBin.GetNumerator() == 1);
			REQUIRE(checkBin.GetDenominator() == 10);

		}
	}
	WHEN("int and CRational(7 / 2/3)")
	{
		CRational first(2, 3), checkBin;
		THEN("must be 21/2")
		{
			checkBin = 7 / first;
			REQUIRE(checkBin.GetNumerator() == 21);
			REQUIRE(checkBin.GetDenominator() == 2);

		}
	}

}

SCENARIO("check +=")
{
	WHEN("two CRational (1/2 += 1/6)")
	{
		CRational variable(1, 2), expr(1, 6);
		THEN("must be 2/3")
		{
			variable += expr;
			REQUIRE(variable.GetNumerator() == 2);
			REQUIRE(variable.GetDenominator() == 3);

		}
	}
	WHEN("CRational and int (1/2 += 1)")
	{
		CRational variable(1, 2);
		THEN("must be 2/3")
		{
			variable += 1;
			REQUIRE(variable.GetNumerator() == 3);
			REQUIRE(variable.GetDenominator() == 2);

		}
	}
}
SCENARIO("check -=")
{
	WHEN("two CRational (1/2 -= 1/6)")
	{
		CRational variable(1, 2), expr(1, 6);
		THEN("must be 1/3")
		{
			variable -= expr;
			REQUIRE(variable.GetNumerator() == 1);
			REQUIRE(variable.GetDenominator() == 3);

		}
	}
	WHEN("CRational and int (1/2 -= 1)")
	{
		CRational variable(1, 2);
		THEN("must be 2/3")
		{
			variable -= 1;
			REQUIRE(variable.GetNumerator() == -1);
			REQUIRE(variable.GetDenominator() == 2);

		}
	}
}
SCENARIO("check *=")
{
	WHEN("two CRational (1/2 *= 2/3)")
	{
		CRational variable(1, 2), expr(2, 3);
		THEN("must be 1/3")
		{
			variable *= expr;
			REQUIRE(variable.GetNumerator() == 1);
			REQUIRE(variable.GetDenominator() == 3);

		}
	}
	WHEN("CRational and int (1/2 *= 3)")
	{
		CRational variable(1, 2);
		THEN("must be 3/2")
		{
			variable *= 3;
			REQUIRE(variable.GetNumerator() == 3);
			REQUIRE(variable.GetDenominator() == 2);

		}
	}
}
SCENARIO("check /=")
{
	WHEN("two CRational (1/2 /= 2/3)")
	{
		CRational variable(1, 2), expr(2, 3);
		THEN("must be 3/4")
		{
			variable /= expr;
			REQUIRE(variable.GetNumerator() == 3);
			REQUIRE(variable.GetDenominator() == 4);

		}
	}
	WHEN("CRational and int (1/2 /= 3)")
	{
		CRational variable(1, 2);
		THEN("must be 1/6")
		{
			variable /= 3;
			REQUIRE(variable.GetNumerator() == 1);
			REQUIRE(variable.GetDenominator() == 6);

		}
	}
	WHEN("two CRational (3/4 /= 3/8)")
	{
		CRational variable(3, 4), expr(3, 8);
		THEN("must be 2/1")
		{
			variable /= expr;
			REQUIRE(variable.GetNumerator() == 2);
			REQUIRE(variable.GetDenominator() == 1);

		}
	}
}

SCENARIO("check == and !=")
{
	WHEN("two equal CRational")
	{
		CRational first(1, 2), second(1, 2);
		THEN(" == must be true")
		{
			REQUIRE(first == second);
		}
		THEN(" != must be false")
		{
			REQUIRE((first != second) == false);
		}
	}
	WHEN("equal CRational and int")
	{
		CRational first(3, 1);
		THEN(" == must be true")
		{
			REQUIRE(first == 3);
		}
		THEN(" != must be false")
		{
			REQUIRE((first != 3) == false);
		}
	}
	WHEN("two diff CRational")
	{
		CRational first(1, 2), second(2, 3);
		THEN(" == must be false")
		{
			REQUIRE((first == second) == false);
		}
		THEN(" != must be true")
		{
			REQUIRE(first != second);
		}
	}
	WHEN("diff CRational and int")
	{
		CRational first(1, 2);
		THEN(" == must be false")
		{
			REQUIRE((7 == first) == false);
		}
		THEN(" != must be true")
		{
			REQUIRE(7 != first);
		}
	}
}

SCENARIO("check compare")
{
	WHEN("1/2 and 1/3")
	{
		CRational first(1, 2), second(1, 3);
		THEN(">= must true")
		{
			REQUIRE(first >= second);
		}
		THEN("<= must be false")
		{
			REQUIRE((first <= second) == false);
		}
	}
	WHEN("compare CRational and int (3/1 and 2)")
	{
		CRational first(3, 1);
		THEN("> must true")
		{
			REQUIRE(first > 2);
		}
		THEN("< must be false")
		{
			REQUIRE((first < 2) == false);
		}
	}
	WHEN("compare int and CRational (1/2 and 7)")
	{
		CRational first(1, 2);
		THEN("> must true")
		{
			REQUIRE(7 > first);
		}
		THEN("< must be false")
		{
			REQUIRE((7 < first) == false);
		}
	}
}

TEST_CASE("Test output operator <<") {
	CRational rational(3, 4);
	std::stringstream ss;
	ss << rational;
	REQUIRE(ss.str() == "3/4");
}

TEST_CASE("Test input operator >>") {
	CRational rational;
	std::stringstream ss("5/6");
	ss >> rational;
	REQUIRE(rational.GetNumerator() == 5);
	REQUIRE(rational.GetDenominator() == 6);
}

TEST_CASE("Test ToCompoundFraction") {
	SECTION("Positive rational number") {
		CRational rational(7, 4);
		auto compoundFraction = rational.ToCompoundFraction();
		REQUIRE(compoundFraction.first == 1); 
		REQUIRE(compoundFraction.second.GetNumerator() == 3); 
		REQUIRE(compoundFraction.second.GetDenominator() == 4); 
	}

	SECTION("Negative rational number") {
		CRational rational(-9, 4);
		auto compoundFraction = rational.ToCompoundFraction();
		REQUIRE(compoundFraction.first == -2);
		REQUIRE(compoundFraction.second.GetNumerator() == 1); 
		REQUIRE(compoundFraction.second.GetDenominator() == 4); 
	}
}