#include "../ÑBody.h"

class CParallelepiped final : public CBody
{
public:
	CParallelepiped(double density, double length, double width, double height);
	double GetVolume() const override;
	double GetDepth() const;
	double GetWidth() const;
	double GetHeight() const;
private:
	void AppendProperties(std::ostream& strm) const override;
	double m_depth, m_width, m_height;
};
