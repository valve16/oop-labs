#include <string>
#include "StringProcess.h"

const std::string QUOT = "&quot;";
const std::string APOS = "&apos;";
const std::string LT = "&lt;";
const std::string AMP = "&amp;";
const std::string GT = "&gt;";

const int LT_SIZE = 4;
const int GT_SIZE = 4;
const int AMP_SIZE = 5;
const int QUOT_SIZE = 6;
const int APOS_SIZE = 6;

//разбить на подфункции
std::string HtmlDecode(std::string const& html)
{
	std::string result;
	size_t startPos = 0;
	while (startPos < html.size())
	{
		if (html[startPos] != '&') // не корректно &&lt;hello
		{
			result += html[startPos];
			startPos++;
		}
		else
		{
			if (html.substr(startPos, QUOT_SIZE) == QUOT)
			{
				result += '"';
				startPos += QUOT_SIZE;
			}
			else if (html.substr(startPos, APOS_SIZE) == APOS)
			{
				result += '\'';
				startPos += APOS_SIZE;
			}
			else if (html.substr(startPos, LT_SIZE) == LT)
			{
				result += '<';
				startPos += LT_SIZE;
			}
			else if (html.substr(startPos, GT_SIZE) == GT)
			{
				result += '>';
				startPos += GT_SIZE;
			}
			else if (html.substr(startPos, AMP_SIZE) == AMP)
			{
				result += '&';
				startPos += AMP_SIZE;
			}
			else
			{
				result += html[startPos];
				startPos++;
			}
		}
	}
	return result;
};