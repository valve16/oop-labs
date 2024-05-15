#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
#define _USE_MATH_DEFINES


class CBody // переименоватть
{
public:
	CBody(const std::string& type, double density);
	virtual double GetVolume() const = 0;
	double GetMass() const;
	double GetDensity() const;
	std::string ToString() const;
	virtual ~CBody() = default;
private:
	virtual void AppendProperties(std::ostream& strm) const = 0;
	double m_density;
	std::string m_type;
};
