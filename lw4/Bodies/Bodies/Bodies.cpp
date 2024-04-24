#include <iostream>
#include "CBodies.h"

int main()
{
    //std::cout << "Hello World!\n";

    CSphere sphere(2, 10);
    CSphere sphere1(2, 20);
    std::cout << "Radius: " << sphere.GetRadius() << "\n";
    std::cout << "Mass: " << sphere.GetMass() << "\n";
    std::cout << "Density:  " << sphere.GetDensity() << "\n";
    std::cout << "Volume: " << sphere.GetVolume() << "\n";

    CCompound bodies1;
    bodies1.AddChildBody(std::make_shared<CSphere> (sphere));
    bodies1.AddChildBody(std::make_shared<CSphere>(sphere1));
    std::cout << "Mass: " << bodies1.GetMass() << "\n";
    std::cout << "Density:  " << bodies1.GetDensity() << "\n";
    std::cout << "Volume: " << bodies1.GetVolume() << "\n";
}

