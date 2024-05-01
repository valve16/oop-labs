#pragma once

#include "ÑBodies.h"
#include <vector>

class CBodyControl
{
public:
	CBodyControl(std::vector<std::shared_ptr<CBody>>& bodies
		, std::istream& input
		, std::ostream& output);
	void ReadBodies();
private:
	std::shared_ptr<CBody> ReadSimpleBody();
	std::vector<std::shared_ptr<CBody>>& m_bodies;
	std::istream& m_input;
	std::ostream& m_output;

};