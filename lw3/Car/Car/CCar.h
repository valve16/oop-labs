#pragma once
#include <iostream>
#include <string>
#include <sstream>

const int NULL_SPEED = 0;
const int N_GEAR = 0;
const int R_GEAR = -1;
const int FIRST_GEAR = 1;
const int SECOND_GEAR = 2;
const int THIRD_GEAR = 3;
const int FOURTH_GEAR = 4;
const int FIFTH_GEAR = 5;
const int LIMIT_R_GEAR = 20;
const int LIMIT_FIRST_GEAR = 30;
const int LIMIT_SECOND_GEAR = 50;
const int LIMIT_THIRD_GEAR = 60;
const int LIMIT_FOURTH_GEAR = 90;
const int LIMIT_FIFTH_GEAR = 150;
const int MIN_SPEED_SECOND_GEAR = 20;
const int MIN_SPEED_THIRD_GEAR = 30;
const int MIN_SPEED_FOURTH_GEAR = 40;
const int MIN_SPEED_FIFTH_GEAR = 50;


enum Direction 
{
	STAND,
	FORWARD,
	BACKWARD
};
class Car 
{
public:
	Car (int gear, int speed, bool engineOn, Direction dir)
		: m_gear{ gear }
		, m_speed{ speed }
		, m_turnedOnEngine{ engineOn }
		, m_direction{ dir }
	{
	}
	Car() = default;
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