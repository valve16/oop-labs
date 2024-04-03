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
	if (!m_turnedOnEngine)
	{
		if (gear == 0) 
		{
			m_gear = 0;
			return true;
		}
		else 
		{ 
			std::cout << "Двигатель выключен, не удалось включить передачу\n";
			return false;
		}
	}
	else
	{
		switch (gear)
		{
		case -1:
			if (m_speed == 0)
			{
				m_gear = -1;
				return true;
			};
			break;

		case 0:
			m_gear = 0;
			return true;

		case 1:
			if (m_speed >= 0 && m_speed <= 30 && m_direction != BACKWARD)
			{
				m_gear = 1;
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
		std::cout << "Скорость вне диапазона передачи";
		return false;
	}
}

bool Car::SetSpeed(int speed) 
{
	if (m_gear == 0) 
	{
		if (speed < m_speed) 
		{
			m_speed = speed;
			if (speed == 0)
			{
				m_direction = STAND;
			}
			return true;
		}
		std::cout << "На нейтральной передаче можно только понизить скорость";
	}
	else if (speed >= 0) 
	{
		switch (m_gear)
		{
		case -1: 
			if (speed >= 0 && speed <= 20)
			{
				m_speed = speed;
				if (speed == 0)
				{
					m_direction = STAND;
				}
				else 
				{
					m_direction = BACKWARD;
				}
				return true;
			}
			break;

		case 1:
			if (speed >= 0 && speed <= 30)
			{
				m_speed = speed;
				if (speed == 0)
				{
					m_direction = STAND;
				}
				else
				{
					m_direction = FORWARD;
				}
				return true;
			}
			break;

		case 2:
			if (speed >= 20 && speed <= 50)
			{
				m_speed = speed;
				return true;
			}
			break;

		case 3: 
			if (speed >= 30 && speed <= 60)
			{
				m_speed = speed;
				return true;
			}
			break;

		case 4:
			if (speed >= 40 && speed <= 90)
			{
				m_speed = speed;
				return true;
			}
			break;

		case 5:
			if (speed >= 50 && speed <= 150)
			{
				m_speed = speed;
				return true;
			}
			break;
		}
		std::cout << "Скорость вне диапазона передачи";
	}
	return false;
}