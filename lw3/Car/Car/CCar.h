#pragma once
#include <iostream>
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