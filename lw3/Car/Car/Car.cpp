#include <iostream>
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

	RemoteControl remoteControl{ car, std::cin, std::cout };
	remoteControl.ExecuteCommand();

	/*std::string line;
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
			if (car.SetGear(number)) 
			{
				std::cout << "Передача переключена\n";
			}
		}
		else if (operation == "SetSpeed") {
			if (car.SetSpeed(number))
			{
				std::cout << "Скорость изменена\n";
			}
		}
	}*/
}

