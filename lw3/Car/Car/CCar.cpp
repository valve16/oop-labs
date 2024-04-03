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
	if (!m_turnedOnEngine || (m_speed == NULL_SPEED && m_gear == N_GEAR))
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
		if (gear == N_GEAR)
		{
			m_gear = N_GEAR;
			return true;
		}
		else 
		{ 
			return false;
		}
	}
	else
	{
		switch (gear)
		{
		case R_GEAR:
			if (m_speed == NULL_SPEED)
			{
				m_gear = R_GEAR;
				return true;
			};
			break;

		case N_GEAR:
			m_gear = N_GEAR;
			return true;

		case FIRST_GEAR:
			if (m_speed >= NULL_SPEED && m_speed <= LIMIT_FIRST_GEAR && m_direction != BACKWARD)
			{
				m_gear = FIRST_GEAR;
				return true;
			};
			break;

		case SECOND_GEAR:
			if (m_speed >= MIN_SPEED_SECOND_GEAR && m_speed <= LIMIT_SECOND_GEAR && m_direction == FORWARD)
			{
				m_gear = SECOND_GEAR;
				return true;
			};
			break;

		case THIRD_GEAR:
			if (m_speed >= MIN_SPEED_THIRD_GEAR && m_speed <= LIMIT_THIRD_GEAR && m_direction == FORWARD)
			{
				m_gear = THIRD_GEAR;
				return true;
			};
			break;

		case FOURTH_GEAR:
			if (m_speed >= MIN_SPEED_FOURTH_GEAR && m_speed <= LIMIT_FOURTH_GEAR && m_direction == FORWARD)
			{
				m_gear = FOURTH_GEAR;
				return true;
			};
			break;

		case FIFTH_GEAR:
			if (m_speed >= MIN_SPEED_FIFTH_GEAR && m_speed <= LIMIT_FIFTH_GEAR && m_direction == FORWARD)
			{
				m_gear = FIFTH_GEAR;
				return true;
			};
			break;

		default:
			return false;
		}
		return false;
	}
}

bool Car::SetSpeed(int speed) 
{
	if (m_gear == NULL_SPEED)
	{
		if (speed < m_speed) 
		{
			m_speed = speed;
			if (speed == NULL_SPEED)
			{
				m_direction = STAND;
			}
			return true;
		}
	}
	else if (speed >= NULL_SPEED)
	{
		switch (m_gear)
		{
		case R_GEAR:
			if (speed >= NULL_SPEED && speed <= LIMIT_R_GEAR)
			{
				m_speed = speed;
				if (speed == NULL_SPEED)
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

		case FIRST_GEAR:
			if (speed >= NULL_SPEED && speed <= LIMIT_FIRST_GEAR)
			{
				m_speed = speed;
				if (speed == NULL_SPEED)
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

		case SECOND_GEAR:
			if (speed >= MIN_SPEED_SECOND_GEAR && speed <= LIMIT_SECOND_GEAR)
			{
				m_speed = speed;
				return true;
			}
			break;

		case THIRD_GEAR:
			if (speed >= MIN_SPEED_THIRD_GEAR && speed <= LIMIT_THIRD_GEAR)
			{
				m_speed = speed;
				return true;
			}
			break;

		case FOURTH_GEAR:
			if (speed >= MIN_SPEED_FOURTH_GEAR && speed <= LIMIT_FOURTH_GEAR)
			{
				m_speed = speed;
				return true;
			}
			break;

		case FIFTH_GEAR:
			if (speed >= MIN_SPEED_FIFTH_GEAR && speed <= LIMIT_FIFTH_GEAR)
			{
				m_speed = speed;
				return true;
			}
			break;
		}
	}
	return false;
}

bool RemoteControl::ExecuteCommand() const
{
	std::string command;

	m_output << "Info. Выводит состояние двигателя автомобиля, направление движения, скорость и передачу " << std::endl;
	m_output << "EngineOn. Включает двигатель" << std::endl;
	m_output << "EngineOff. Выключает двигатель " << std::endl;
	m_output << "SetGear передача. " << std::endl;
	m_output << "SetSpeed скорость. " << std::endl;
	m_output << "Exit заввершить. " << std::endl;

	while (std::getline(std::cin, command)) {
		if (command == "TurnOn")
		{
			m_car.TurnOnEngine();
			m_output << "TV is turned on" << std::endl;
		}
		std::istringstream iss(command);
		std::string operation;
		int number;
		iss >> operation >> number;

		if (operation == "Info")
		{
			m_output << "Engine: " << (m_car.IsTurnedOn() ? "On" : "Off") << std::endl;
			std::string textDirection;
			switch (m_car.GetDirection())
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
			m_output << "Direction: " << textDirection << std::endl;
			m_output << "Gear: " << m_car.GetGear() << std::endl;
			m_output << "Speed: " << m_car.GetSpeed() << std::endl;
		}

		else if (operation == "EngineOn")
		{
			if (m_car.TurnOnEngine())
			{
				m_output << "Двигатель включен\n" << std::endl;
			}
		}

		else if (operation == "EngineOff")
		{
			if (!m_car.TurnOffEngine())
			{
				m_output << "Двигатель не может быть в данный момент выключен\n";
			}
			else
			{
				m_output << "Двигатель выключен\n";
			}
		}
		else if (operation == "SetGear")
		{
			if (m_car.SetGear(number))
			{
				m_output << "Передача переключена\n";
			}
			else
			{
				m_output << "Не удалось изменить передачу\n";
			}
		}
		else if (operation == "SetSpeed") {
			if (m_car.SetSpeed(number))
			{
				m_output << "Скорость изменена\n";
			}
			else
			{
				m_output << "Не удалось изменить скорость\n";
			}
		}
		else if (operation == "Exit") {
			return true;
		}
	}
}