#include "CBodies.h"
const double PI = 3.141592;
const double GAIN = 9.8;


double CSolidBody::GetDensity() const
{
	return m_density;
}

double CSolidBody::GetMass() const
{
	return m_density * GetVolume();
}


double CSphere::GetVolume() const
{
	return (4.0 / 3.0) * PI * pow(m_radius, 3);
}

//double CSphere::GetMass() const 
//{
//	return m_density * GetVolume();
//}

double CSphere::GetRadius() const 
{
	return m_radius;
}

double CParallelepiped::GetVolume() const 
{
	return m_depth * m_width * m_height;
}

//double CParallelepiped::GetMass() const 
//{
//	return GetVolume() * m_density;
//}

double CParallelepiped::GetWidth() const 
{
	return m_width;
}

double CParallelepiped::GetDepth() const 
{
	return m_depth;
}

double CParallelepiped::GetHeight() const 
{
	return m_height;
}

double CCone::GetHeight() const 
{
	return m_height;
}

double CCone::GetBaseRadius() const 
{
	return m_baseRadius;
}

double CCone::GetVolume() const 
{
	return 1/3 * PI * pow(m_baseRadius, 2) * m_height;
}

double CCylinder::GetHeight() const
{
	return m_height;
}

double CCylinder::GetRadius() const
{
	return m_radius;
}

double CCylinder::GetVolume() const
{
	return PI * pow(m_radius, 2) * m_height;
}

bool CCompound::AddChildBody(std::shared_ptr<CBody> child) {
	m_childs.push_back(child);
	return true;
}

double CCompound::GetVolume() const 
{
	double totalVolume = 0;
	for (const auto& child : m_childs) {
		totalVolume += child->GetVolume();
	}
	return totalVolume;
}

double CCompound::GetMass() const 
{
	double totalMass = 0;
	for (const auto& part : m_childs) 
	{
		totalMass += part->GetMass();
	}
	return totalMass;
}

double CCompound::GetDensity() const 
{
	double totalMass = 0;
	for (const auto& part : m_childs)
	{
		totalMass += part->GetMass();
	};
	double totalVolume = 0;
	for (const auto& child : m_childs) {
		totalVolume += child->GetVolume();
	};
	return totalMass / totalVolume;
}

//bool RemoteControl::ExecuteCommand() const
//{
//	std::string command;
//
//	m_output << "Info. Выводит состояние двигателя автомобиля, направление движения, скорость и передачу " << std::endl;
//	m_output << "EngineOn. Включает двигатель" << std::endl;
//	m_output << "EngineOff. Выключает двигатель " << std::endl;
//	m_output << "SetGear передача. " << std::endl;
//	m_output << "SetSpeed скорость. " << std::endl;
//	m_output << "Exit заввершить. " << std::endl;
//
//	while (std::getline(std::cin, command)) {
//		if (command == "TurnOn")
//		{
//			m_car.TurnOnEngine();
//			m_output << "TV is turned on" << std::endl;
//		}
//		std::istringstream iss(command);
//		std::string operation;
//		int number;
//		iss >> operation >> number;
//
//		if (operation == "Info")
//		{
//			m_output << "Engine: " << (m_car.IsTurnedOn() ? "On" : "Off") << std::endl;
//			std::string textDirection;
//			switch (m_car.GetDirection())
//			{
//			case STAND:
//				textDirection = "standing still";
//				break;
//			case FORWARD:
//				textDirection = "forward";
//				break;
//			case BACKWARD:
//				textDirection = "backward";
//				break;
//			}
//			m_output << "Direction: " << textDirection << std::endl;
//			m_output << "Gear: " << m_car.GetGear() << std::endl;
//			m_output << "Speed: " << m_car.GetSpeed() << std::endl;
//		}
//
//		else if (operation == "EngineOn")
//		{
//			if (m_car.TurnOnEngine())
//			{
//				m_output << "Двигатель включен\n" << std::endl;
//			}
//		}
//
//		else if (operation == "EngineOff")
//		{
//			if (!m_car.TurnOffEngine())
//			{
//				m_output << "Двигатель не может быть в данный момент выключен\n";
//			}
//			else
//			{
//				m_output << "Двигатель выключен\n";
//			}
//		}
//		else if (operation == "SetGear")
//		{
//			if (m_car.SetGear(number))
//			{
//				m_output << "Передача переключена\n";
//			}
//			else
//			{
//				m_output << "Не удалось изменить передачу\n";
//			}
//		}
//		else if (operation == "SetSpeed") {
//			if (m_car.SetSpeed(number))
//			{
//				m_output << "Скорость изменена\n";
//			}
//			else
//			{
//				m_output << "Не удалось изменить скорость\n";
//			}
//		}
//		else if (operation == "Exit") {
//			return true;
//		}
//	}
//}
//

