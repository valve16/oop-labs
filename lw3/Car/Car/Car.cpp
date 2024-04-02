﻿#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <sstream>
#include "CCar.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Car car;
	std::cout << "Info. Выводит состояние двигателя автомобиля, направление движения, скорость и передачу " << std::endl;
	std::cout << "EngineOn. Включает двигатель" << std::endl;
	std::cout << "EngineOff. Выключает двигатель " << std::endl;
	std::cout << "SetGear передача. " << std::endl;
	std::cout << "SetSpeed скорость. " << std::endl;

	std::string line;
	while (std::getline(std::cin, line))
	{
		std::istringstream iss(line);
		std::string operation;
		int number;
		iss >> operation >> number;
		if (operation == "Info")
		{
			std::cout << "Engine: " << (car.IsTurnedOn() ? "On" : "Off") << std::endl;
			std::string textDirection;
			switch (car.GetDirection())
			{
			case STAND:
				textDirection = "standing still";
				break;
			case FORWARD:
				textDirection = "forward";
				break;
			case BACKWARD:
				textDirection = "backward";
				break;
			}
			std::cout << "Direction: " << textDirection << std::endl;
			std::cout << "Gear: " << car.GetGear() << std::endl;
			std::cout << "Speed: " << car.GetSpeed() << std::endl;
		}
		else if (operation == "EngineOn")
		{
			if (car.TurnOnEngine())
			{
				std::cout << "Двигатель включен" << std::endl;
			}
		}
		else if (operation == "EngineOff")
		{
			if (!car.TurnOffEngine())
			{
				std::cout << "Двигатель не может быть в данный момент выключен\n";
			}
			else
			{
				std::cout << "Двигатель выключен\n";
			}
		}
		else if (operation == "SetGear")
		{
			std::cout << operation << " " << number << std::endl;
		}
		else if (operation == "SetSpeed") {

		}
	}
}
