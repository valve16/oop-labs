#include "Parallelepiped.h"



CParallelepiped::CParallelepiped(double length, double width, double height, double density) 
	: CBody("Parallelepiped",density)
	, m_depth(length)
	, m_width(width)
	, m_height(height) 
{
}

double CParallelepiped::GetVolume() const
{
	return m_depth * m_width * m_height;
}


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

void CParallelepiped::AppendProperties(std::ostream& strm) const
{
	strm << "\theight = " << GetHeight() << std::endl;
	strm << "\twidth = " << GetWidth() << std::endl;
	strm << "\tdepth = " << GetDepth() << std::endl;
}
