#include <iostream>
#include <vector>
#include <algorithm>
#include "Sphere/Sphere.h"
#include "Cone/Cone.h"
#include "Cylinder/Cylinder.h"
#include "Parallelepiped/Parallelepiped.h"
#include "..\Bodies\СBody.h"
#include "BodyControl.h"



int main()
{
    std::vector<std::shared_ptr<CBody>> bodies;
    CBodyControl bodiesControl(bodies, std::cin, std::cout);
    bodiesControl.ReadBodies();
    bodiesControl.WriteBodies();
    bodiesControl.WriteHaviestBody();
    bodiesControl.WriteLightestBodyInWater();

    return 0;
}

