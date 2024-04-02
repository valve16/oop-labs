#include "CCar.h"

bool Car::IsTurnedOn() const 
{
	return m_turnedOnEngine;
}

Direction Car::GetDirection() const 
{
	return m_direction;
}

int Car::GetSpeed() const 
{
	return m_speed;
}

int Car::GetGear() const
{
	return m_gear;
}

bool Car::TurnOnEngine()
{
	if (!m_turnedOnEngine) 
	{
		m_turnedOnEngine = true;
	}
	return m_turnedOnEngine;
}
bool Car::TurnOffEngine()
{
	if (!m_turnedOnEngine || (m_speed == 0 && m_gear == 0))
	{
		m_turnedOnEngine = false;
		return true;
	}
	else
	{
		return false;
	}
}