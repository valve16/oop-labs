#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
#define _USE_MATH_DEFINES

// разнести по файлам
// деструкторы добавитьь

class CBody
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


class RemoteControl
{
public:
	RemoteControl(std::istream& input, std::ostream& output)
		: m_input{ input }
		, m_output{ output }
	{
	}
	bool ExecuteCommand() const;
private:
	std::istream& m_input;
	std::ostream& m_output;
};