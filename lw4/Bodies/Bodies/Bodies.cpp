#include <iostream>
#include <vector>
#include <algorithm>
#include "Sphere/Sphere.h"
#include "Cone/Cone.h"
#include "Cylinder/Cylinder.h"
#include "Parallelepiped/Parallelepiped.h"
#include "СBodies.h"
#include "BodyControl.h"



//std::shared_ptr<CBody> FindLightestInWaterBody(const std::vector<std::shared_ptr<CBody>>& bodies)
//{
//    if (bodies.empty()) {
//        return nullptr;
//    }
//
//    auto compareMassInWater = [](const std::shared_ptr<CBody>& body1, const std::shared_ptr<CBody>& body2)
//        {
//            return ((body1->GetDensity() - WATER_DENSITY) * body1->GetVolume()) 
//                   < ((body2->GetDensity() - WATER_DENSITY) * body2->GetVolume());
//        };
//
//    auto heaviestBodyIterator = std::min_element(bodies.begin(), bodies.end(), compareMassInWater);
//
//    return *heaviestBodyIterator;
//}

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

