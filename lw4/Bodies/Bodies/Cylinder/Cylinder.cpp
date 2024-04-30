#define _USE_MATH_DEFINES
#include "Cylinder.h"

CCylinder::CCylinder(double radius, double density, double height)
	: CBody("Cylinder", density)
	, m_height(height)
	, m_radius(radius)
{
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
	return M_PI * pow(m_radius, 2) * m_height;
}

void CCylinder::AppendProperties(std::ostream& strm) const
{
	strm << "\tbase radius = " << GetRadius() << std::endl;
	strm << "\theight = " << GetHeight() << std::endl;
}
