#include "CBodies.h"
const int PI = 3.14;
const int GAIN = 9.8;


double CSolidBody::GetDensity() const
{
	return m_density;
}

double CSolidBody::GetMass() const
{
	return m_density * GetVolume() * GAIN;
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




