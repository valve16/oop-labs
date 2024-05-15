#include"..\ÑBody.h"

class CCylinder final: public CBody
{
public:
	CCylinder(double density, double radius, double height);
	double GetVolume() const override;
	double GetRadius() const;
	double GetHeight() const;
private:
	void AppendProperties(std::ostream& strm) const override;
	double m_radius, m_height;
};
