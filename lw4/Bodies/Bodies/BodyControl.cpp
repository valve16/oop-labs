#include "BodyControl.h"
#include "Sphere/Sphere.h"
#include "Cone/Cone.h"
#include "Cylinder/Cylinder.h"
#include "Parallelepiped/Parallelepiped.h"

CBodyControl::CBodyControl(std::vector<std::shared_ptr<CBody>>& bodies
	, std::istream& input
	, std::ostream& output)
	: m_bodies(bodies)
	, m_input(input)
	, m_output(output)
{
}

void CBodyControl::ReadBodies()
{
	char choice;
	do
	{
		m_bodies.push_back(std::move(ReadSimpleBody()));
        m_output << "Continue? (y/n): ";
        m_input >> choice;
	} while (choice == 'y');
}

std::shared_ptr<CBody> CBodyControl::ReadSimpleBody()
{
    std::string type;
    m_output << "Enter the type of body (sphere, parallelepiped, cone, cylinder): ";
    m_input >> type;

    double density;
    m_output << "Enter the density: ";
    m_input >> density;

    if (type == "sphere")
    {
        double radius;
        m_output << "Enter the radius of the sphere: ";
        m_input >> radius;
        return std::make_shared<CSphere>(density, radius);
    }
    else if (type == "parallelepiped")
    {
        double length, width, height;
        m_output << "Enter the length, width, and height of the parallelepiped: ";
        m_input >> length >> width >> height;
        return std::make_shared<CParallelepiped>(density, length, width, height);
    }
    else if (type == "cone")
    {
        double radius, height;
        m_output << "Enter the radius and height of the cone: ";
        m_input >> radius >> height;
        return std::make_shared<CCone>(density, radius, height);
    }
    else if (type == "cylinder")
    {
        double radius, height;
        m_output << "Enter the radius and height of the cone: ";
        m_input >> radius >> height;
        return std::make_shared<CCylinder>(density, radius, height);
    }
    else
    {
        std::cerr << "Invalid body type." << std::endl;
        return nullptr;
    }
}