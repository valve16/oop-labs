#pragma once
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
private:
	int m_gear = 0;
	int m_speed = 0;
	bool m_turnedOnEngine = false;
	Direction m_direction = STAND;
};