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

	return 0;
}

