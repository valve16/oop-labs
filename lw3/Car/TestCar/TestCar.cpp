#define CATCH_CONFIG_MAIN
#include "../../../catch2/catch.hpp"
#include "..\Car\CCar.h"
#include <iostream>

SCENARIO("Turn on offed engine") 
{
	Car car(0, 0, false, STAND);
	CHECK(car.TurnOnEngine() == true);
}

SCENARIO("Turn on engine is on")
{
	Car car(0, 0, true, STAND);
	CHECK(car.TurnOnEngine() == true);
}

SCENARIO("Turn off engine is on")
{
	Car car(0, 0, true, STAND);
	CHECK(car.TurnOffEngine() == true);
}

SCENARIO("Turn off engine is off")
{
	Car car(0, 0, false, STAND);
	CHECK(car.TurnOnEngine() == true);
}

SCENARIO("Turn off engine on gear")
{
	Car car(1, 0, true, STAND);
	CHECK(car.TurnOffEngine() == false);
}

SCENARIO("Turn off engine on gear and speed")
{
	Car car(1, 20, true, STAND);
	CHECK(car.TurnOffEngine() == false);
}

