#define CATCH_CONFIG_MAIN
#include "../../../catch2/catch.hpp"
#include "..\Bodies\CBodies.h"
#include <iostream>

SCENARIO("check sphere")
{
	CSphere sphere(2, 10);
	REQUIRE(sphere.GetRadius() == 2 );
	REQUIRE(sphere.GetMass() >= 335.102);
	REQUIRE(sphere.GetMass() <= 335.104);
	REQUIRE(sphere.GetVolume() >= 33.5102);
	REQUIRE(sphere.GetVolume() <= 33.5104);
	REQUIRE(sphere.GetDensity() == 10);
}

SCENARIO("check cone")
{
	CCone cone(2, 10, 4);
	REQUIRE(cone.GetBaseRadius() == 2);
	REQUIRE(cone.GetVolume() >= 16.7551);
	REQUIRE(cone.GetVolume() <= 16.7553);
	REQUIRE(cone.GetDensity() == 10);
	REQUIRE(cone.GetHeight() == 4);
	REQUIRE(cone.GetMass() >= 167.551);
	REQUIRE(cone.GetMass() <= 167.553);
}

SCENARIO("check parallelepiped")
{
	CParallelepiped cone(2, 2, 2, 10);
	REQUIRE(cone.GetVolume() == 8);
	REQUIRE(cone.GetDensity() == 10);
	REQUIRE(cone.GetHeight() == 2);
	REQUIRE(cone.GetWidth() == 2);
	REQUIRE(cone.GetDepth() == 2);
	REQUIRE(cone.GetMass() == 80);
}

SCENARIO("check cylinder")
{
	CCylinder cone(2, 10, 4);
	REQUIRE(cone.GetRadius() == 2);
	REQUIRE(cone.GetVolume() >= 50.2654);
	REQUIRE(cone.GetVolume() <= 50.2656);
	REQUIRE(cone.GetDensity() == 10);
	REQUIRE(cone.GetHeight() == 4);
	REQUIRE(cone.GetMass() >= 502.654);
	REQUIRE(cone.GetMass() <= 502.656);
}

