#pragma once
#include <iostream>
#include <string>
#include <sstream>

class CBody
{
public:
	CBody() = default;
	virtual double GetVolume() const = 0;
	virtual double GetMass() const = 0;
	virtual double GetDensity() const = 0;
	std::string ToString();
private:

};

class CSolidBody : public CBody 
{
protected:
	double m_density;
public:
	CSolidBody(double density) : m_density(density) {}
	double GetMass() const override;
	double GetDensity() const override;
	//virtual double GetVolume() const override;
};

class CSphere : public CSolidBody 
{
public:
	CSphere(double radius, double density) : CSolidBody(density), m_radius(radius) {}
	double GetVolume() const override;
	//double GetMass() const override;
	double GetRadius() const;
private:
	double m_radius;
};

class CParallelepiped : public CSolidBody 
{
public:
	CParallelepiped(double length, double width, double height, double density) :
		CSolidBody(density), m_depth(length), m_width(width), m_height(height) {}
	double GetVolume() const override;
	//double GetMass() const override;
	double GetDepth() const;
	double GetWidth() const;
	double GetHeight() const;
private:
	double m_depth, m_width, m_height;
};

class CCone : public CSolidBody 
{
public:
	CCone(double radius, double density, double height) : CSolidBody(density), m_baseRadius(radius), m_height(height) {}
	double GetVolume() const override;
	//double GetMass() const override;
	double GetBaseRadius() const;
	double GetHeight() const;
private:
	double m_baseRadius, m_height;
};

class CCylinder : public CSolidBody 
{
public:
	CCylinder(double radius, double density, double height): CSolidBody(density), m_radius(radius), m_height(height){}
	double GetVolume() const override;
	double GetRadius() const;
	double GetHeight() const;
private:
	double m_radius, m_height;
};