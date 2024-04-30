#include "Compound.h"


bool CCompound::AddChildBody(std::shared_ptr<CBody> child) {
	m_childs.push_back(child);
	return true;
}

double CCompound::GetVolume() const
{
	double totalVolume = 0;
	for (const auto& child : m_childs) {
		totalVolume += child->GetVolume();
	}
	return totalVolume;
}

double CCompound::GetMass() const
{
	double totalMass = 0;
	for (const auto& part : m_childs)
	{
		totalMass += part->GetMass();
	}
	return totalMass;
}

double CCompound::GetDensity() const
{
	double totalMass = 0;
	for (const auto& part : m_childs)
	{
		totalMass += part->GetMass();
	};
	double totalVolume = 0;
	for (const auto& child : m_childs) {
		totalVolume += child->GetVolume();
	};
	return totalMass / totalVolume;
}
