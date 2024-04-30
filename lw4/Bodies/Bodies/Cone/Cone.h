#include "../Bodies.h"

class CCone final : public CBody
{
public:
	CCone(double density, double radius, double height);

	double GetBaseRadius() const;
	double GetVolume() const override;
	double GetHeight() const;

private:
	void AppendProperties(std::ostream& strm) const override;
	double m_radius, m_height;
};