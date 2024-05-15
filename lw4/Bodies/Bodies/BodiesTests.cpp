#define CATCH_CONFIG_MAIN
#include "../../../catch2/catch.hpp"
#include "../Bodies/Cone/Cone.h"
#include "../Bodies/Cylinder/Cylinder.h"
#include "../Bodies/Parallelepiped/Parallelepiped.h"
#include "../Bodies/СBody.h"
#include "../Bodies/Sphere/Sphere.h"
#include <iostream>

SCENARIO("check sphere")
{
	const CSphere sphere(10, 2);
	REQUIRE(sphere.GetDensity() == 10.0 );
	REQUIRE(sphere.GetMass() >= 335.102);
	REQUIRE(sphere.GetMass() <= 335.104);
	REQUIRE(sphere.GetVolume() >= 33.5102);
	REQUIRE(sphere.GetVolume() <= 33.5104);
	REQUIRE(sphere.GetDensity() == 10.0);
}

SCENARIO("check cone")
{
	CCone cone(10, 2, 4);
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
	CParallelepiped parallelepiped(10, 2, 2, 2);
	REQUIRE(parallelepiped.GetVolume() == 8);
	REQUIRE(parallelepiped.GetDensity() == 10);
	REQUIRE(parallelepiped.GetDensity() == 10);
	REQUIRE(parallelepiped.GetHeight() == 2);
	REQUIRE(parallelepiped.GetWidth() == 2);
	REQUIRE(parallelepiped.GetDepth() == 2);
	REQUIRE(parallelepiped.GetMass() == 80);
}

SCENARIO("check cylinder")
{
	CCylinder cylinder(10, 2, 4);
	REQUIRE(cylinder.GetRadius() == 2);
	REQUIRE(cylinder.GetVolume() >= 50.2654);
	REQUIRE(cylinder.GetVolume() <= 50.2656);
	REQUIRE(cylinder.GetDensity() == 10);
	REQUIRE(cylinder.GetHeight() == 4);
	REQUIRE(cylinder.GetMass() >= 502.654);
	REQUIRE(cylinder.GetMass() <= 502.656);
}

SCENARIO("check to string paralelepiped")
{
	CParallelepiped parallelepiped(10, 2, 2, 2);
	std::string testString = 
R"(Parallelepiped:
	density = 10
	volume = 8
	mass = 80
	height = 2
	width = 2
	depth = 2
)";
	REQUIRE(parallelepiped.ToString() == testString);
	parallelepiped.ToString();
	
}


SCENARIO("check to string sphere")
{
	const CSphere sphere(10, 2);
	std::string testString =
R"(Sphere:
	density = 10
	volume = 33.51032164
	mass = 335.1032164
	radius = 2
)";
	REQUIRE(sphere.ToString() == testString);

}

