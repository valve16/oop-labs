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

bool Car::SetGear(int gear)
{
	switch (gear)
	{
	case -1:
		if (m_speed == 0)
		{
			m_gear = -1;
			m_direction = BACKWARD;
			return true;
		};
		break;

	case 0:
		m_gear = 0;
		return true;

	case 1:
		if (m_speed >= 0 && m_speed <= 30)
		{
			m_gear = 1;
			if (m_speed == 0)
			{
				m_direction = FORWARD;
			}
			return true;
		};
		break;

	case 2:
		if (m_speed >= 20 && m_speed <= 50 && m_direction == FORWARD)
		{
			m_gear = 2;
			return true;
		};
		break;

	case 3:
		if (m_speed >= 30 && m_speed <= 60 && m_direction == FORWARD)
		{
			m_gear = 3;
			return true;
		};
		break;

	case 4:
		if (m_speed >= 40 && m_speed <= 90 && m_direction == FORWARD)
		{
			m_gear = 4;
			return true;
		};
		break;

	case 5:
		if (m_speed >= 50 && m_speed <= 150 && m_direction == FORWARD)
		{
			m_gear = 5;
			return true;
		};
		break;

	default: 
		std::cout << "Неверная передача, доступно от -1 до 5\n";
		return false;
	}
	return false;
}