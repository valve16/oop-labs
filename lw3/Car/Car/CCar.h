#pragma once
#include <iostream>
#include <string>
#include <sstream>
enum Direction 
{
	STAND,
	FORWARD,
	BACKWARD
};
class Car 
{
public:
	//Car();
	bool IsTurnedOn() const;
	Direction GetDirection() const;
	int GetSpeed() const;
	int GetGear() const;
	bool TurnOnEngine();
	bool TurnOffEngine();
	bool SetGear(int gear);
	bool SetSpeed(int speed);
private:
	int m_gear = 0;
	int m_speed = 0;
	bool m_turnedOnEngine = false;
	Direction m_direction = STAND;
};

class RemoteControl
{
public:
	RemoteControl(Car& car, std::istream& input, std::ostream& output)
		: m_car{ car }
		, m_input{ input }
		, m_output{ output }
	{
	}

	bool ExecuteCommand() const;
	
private:
	Car& m_car;
	std::istream& m_input;
	std::ostream& m_output;
};