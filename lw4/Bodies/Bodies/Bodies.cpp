#include <iostream>
#include "Sphere.h"

int main()
{
    //std::cout << "Hello World!\n";

    CSphere sphere(2, 10);
    CSphere sphere1(2, 20);
    std::cout << "Radius: " << sphere.GetRadius() << "\n";
    std::cout << "Mass: " << sphere.GetMass() << "\n";
    std::cout << "Density:  " << sphere.GetDensity() << "\n";
    std::cout << "Volume: " << sphere.GetVolume() << "\n";
    std::cout << sphere.ToString();

   /* CCompound bodies1;
    bodies1.AddChildBody(std::make_shared<CSphere> (sphere));
    bodies1.AddChildBody(std::make_shared<CSphere>(sphere1));
    std::cout << "mass: " << bodies1.GetMass() << "\n";
    std::cout << "density:  " << bodies1.GetDensity() << "\n";
    std::cout << "volume: " << bodies1.GetVolume() << "\n";*/
}

