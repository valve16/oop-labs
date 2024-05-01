#include "BodyControl.h"
#include "Sphere/Sphere.h"
#include "Cone/Cone.h"
#include "Cylinder/Cylinder.h"
#include "Parallelepiped/Parallelepiped.h"

const double WATER_DENSITY = 1000.0;

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
	char choise = 'y';
    while (!m_input.eof())
        {
            m_bodies.push_back(std::move(ReadSimpleBody()));
            m_output << "Continue? ('y' for continue): ";
            m_input >> choise;
            if (choise != 'y')
            {
                break;
            }
        };
}

void CBodyControl::WriteBodies()
{
    m_output << "Information about bodies:" << std::endl;
    for (const auto& body : m_bodies)
    {
        if (body != nullptr)
        {
            m_output << body->ToString() << std::endl;
        }
    }
}

 std::shared_ptr<CBody> CBodyControl::ReadSimpleBody() const
{
    std::string type;
    m_output << "Enter the type of body (sphere, parallelepiped, cone, cylinder): ";
    m_input >> type;

    if (type == "sphere" || type == "parallelepiped" || type == "cone" || type == "cylinder")
    {
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
    }
    else
    {
        m_output << "Invalid body type." << std::endl;
        return nullptr;
    }
}

void CBodyControl::WriteHaviestBody() const
{
    std::shared_ptr<CBody> heaviestBody = FindHeaviestBody();

    if (heaviestBody != nullptr)
    {
        m_output << "Heaviest body: " << heaviestBody->ToString() << std::endl;
    }
    else {
        m_output << "No bodies found." << std::endl;
    }
}

std::shared_ptr<CBody> CBodyControl::FindHeaviestBody() const
{
    if (m_bodies.empty()) {
        return nullptr;
    }

    auto compareMass = [](const std::shared_ptr<CBody>& body1, const std::shared_ptr<CBody>& body2)
        {
            return body1->GetMass() < body2->GetMass();
        };

    auto heaviestBodyIterator = std::max_element(m_bodies.begin(), m_bodies.end(), compareMass);

    return *heaviestBodyIterator;
}

void CBodyControl::WriteLightestBodyInWater() const
{
    std::shared_ptr<CBody> lightestInWaterBody = FindLightestInWaterBody();

    if (lightestInWaterBody != nullptr)
    {
        m_output << "Lightes body in water: " << lightestInWaterBody->ToString() << std::endl;
    }
    else {
        m_output << "No bodies found." << std::endl;
    }
}

std::shared_ptr<CBody> CBodyControl::FindLightestInWaterBody() const
{
    if (m_bodies.empty()) {
        return nullptr;
    }

    auto compareMassInWater = [](const std::shared_ptr<CBody>& body1, const std::shared_ptr<CBody>& body2)
        {
            return ((body1->GetDensity() - WATER_DENSITY) * body1->GetVolume())
                < ((body2->GetDensity() - WATER_DENSITY) * body2->GetVolume());
        };

    auto heaviestBodyIterator = std::min_element(m_bodies.begin(), m_bodies.end(), compareMassInWater);

    return *heaviestBodyIterator;
}