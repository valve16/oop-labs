#include <iostream>
#include <vector>
#include <algorithm>
#include "Sphere/Sphere.h"
#include "Cone/Cone.h"
#include "Cylinder/Cylinder.h"
#include "Parallelepiped/Parallelepiped.h"
#include "СBodies.h"
#include "BodyControl.h"
const double WATER_DENSITY = 1000.0;



std::shared_ptr<CBody> ReadSimpleBody() 
{
    std::string type;
    std::cout << "Enter the type of body (sphere, parallelepiped, cone, cylinder): ";
    std::cin >> type;

    double density;
    std::cout << "Enter the density: ";
    std::cin >> density;

    if (type == "sphere") 
    {
        double radius;
        std::cout << "Enter the radius of the sphere: ";
        std::cin >> radius;
        return std::make_shared<CSphere>(density, radius);
    }
    else if (type == "parallelepiped") 
    {
        double length, width, height;
        std::cout << "Enter the length, width, and height of the parallelepiped: ";
        std::cin >> length >> width >> height;
        return std::make_shared<CParallelepiped>(density, length, width, height);
    }
    else if (type == "cone")
    {
        double radius, height;
        std::cout << "Enter the radius and height of the cone: ";
        std::cin >> radius >> height;
        return std::make_shared<CCone>(density, radius, height);
    }
    else if (type == "cylinder")
    {
        double radius, height;
        std::cout << "Enter the radius and height of the cone: ";
        std::cin >> radius >> height;
        return std::make_shared<CCylinder>(density, radius, height);
    }
    else 
    {
        std::cerr << "Invalid body type." << std::endl;
        return nullptr;
    }
}

std::shared_ptr<CBody> FindHeaviestBody(const std::vector<std::shared_ptr<CBody>>& bodies) 
{
    if (bodies.empty()) {
        return nullptr; 
    }

    auto compareMass = [](const std::shared_ptr<CBody>& body1, const std::shared_ptr<CBody>& body2) 
        {
        return body1->GetMass() < body2->GetMass();
        };

    auto heaviestBodyIterator = std::max_element(bodies.begin(), bodies.end(), compareMass);

    return *heaviestBodyIterator;
}

std::shared_ptr<CBody> FindLightestInWaterBody(const std::vector<std::shared_ptr<CBody>>& bodies)
{
    if (bodies.empty()) {
        return nullptr;
    }

    auto compareMassInWater = [](const std::shared_ptr<CBody>& body1, const std::shared_ptr<CBody>& body2)
        {
            return ((body1->GetDensity() - WATER_DENSITY) * body1->GetVolume()) 
                   < ((body2->GetDensity() - WATER_DENSITY) * body2->GetVolume());
        };

    auto heaviestBodyIterator = std::min_element(bodies.begin(), bodies.end(), compareMassInWater);

    return *heaviestBodyIterator;
}

int main()
{
    std::vector<std::shared_ptr<CBody>> bodies;


  /*  char choice;
    do 
    {
        bodies.push_back(std::move(ReadSimpleBody()));
        std::cout << "Continue? (y/n): ";
        std::cin >> choice;
    } while (choice == 'y');*/

    CBodyControl bodiesControl(bodies, std::cin, std::cout);
    bodiesControl.ReadBodies();

    std::cout << "Information about bodies:" << std::endl;
    for (const auto& body : bodies) 
    {
        std::cout << body->ToString() << std::endl;
    }

    std::shared_ptr<CBody> heaviestBody = FindHeaviestBody(bodies);

    if (heaviestBody != nullptr) 
    {
        std::cout << "Heaviest body: " << heaviestBody->ToString() << std::endl;
    }
    else {
        std::cout << "No bodies found." << std::endl;
    }

    std::shared_ptr<CBody> lightestInWaterBody = FindLightestInWaterBody(bodies);

    if (lightestInWaterBody != nullptr)
    {
        std::cout << "Lightes body in water: " << lightestInWaterBody->ToString() << std::endl;
    }
    else {
        std::cout << "No bodies found." << std::endl;
    }

    return 0;
}

