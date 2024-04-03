#define CATCH_CONFIG_MAIN
#include "../../../catch2/catch.hpp"
#include "..\Car\CCar.h"
#include <iostream>

SCENARIO("Turn on offed engine") 
{
	Car car;
	CHECK(car.TurnOnEngine() == true);
}