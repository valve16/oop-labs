#include <vector>
#include <iomanip> 
#include <math.h>
#define _USE_MATH_DEFINES
#include "Bodies.h"
const double GAIN = 9.8;


CBody::CBody(const std::string& type, double density)
	: m_density(density)
	, m_type(type)
{
}

double CBody::GetDensity()const
{
	return m_density;
}

double CBody::GetMass()const
{
	return GetVolume() * GetDensity();
}


std::string CBody::ToString()const
{
	std::ostringstream strm;
	strm << m_type << ":" << std::endl << std::setprecision(10)
		<< "\tdensity = " << GetDensity() << std::endl
		<< "\tvolume = " << GetVolume() << std::endl
		<< "\tmass = " << GetMass() << std::endl;
	AppendProperties(strm);
	return strm.str();
}

//bool RemoteControl::ExecuteCommand() const
//{
//	std::string command;
//
//	m_output << "Info. ������� ��������� ��������� ����������, ����������� ��������, �������� � �������� " << std::endl;
//	m_output << "EngineOn. �������� ���������" << std::endl;
//	m_output << "EngineOff. ��������� ��������� " << std::endl;
//	m_output << "SetGear ��������. " << std::endl;
//	m_output << "SetSpeed ��������. " << std::endl;
//	m_output << "Exit ����������. " << std::endl;
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
//				m_output << "��������� �������\n" << std::endl;
//			}
//		}
//
//		else if (operation == "EngineOff")
//		{
//			if (!m_car.TurnOffEngine())
//			{
//				m_output << "��������� �� ����� ���� � ������ ������ ��������\n";
//			}
//			else
//			{
//				m_output << "��������� ��������\n";
//			}
//		}
//		else if (operation == "SetGear")
//		{
//			if (m_car.SetGear(number))
//			{
//				m_output << "�������� �����������\n";
//			}
//			else
//			{
//				m_output << "�� ������� �������� ��������\n";
//			}
//		}
//		else if (operation == "SetSpeed") {
//			if (m_car.SetSpeed(number))
//			{
//				m_output << "�������� ��������\n";
//			}
//			else
//			{
//				m_output << "�� ������� �������� ��������\n";
//			}
//		}
//		else if (operation == "Exit") {
//			return true;
//		}
//	}
//}
//

