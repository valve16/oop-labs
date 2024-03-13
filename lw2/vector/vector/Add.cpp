#include "Add.h"
#include <algorithm>
#include <iomanip>
#include <vector>


void DivVectorOnHalfOfMax(std::vector<double>& numbers)
{
	if (!numbers.empty())
	{
		double maxElement = *std::max_element(numbers.begin(), numbers.end());
		std::transform(numbers.begin(), numbers.end(), numbers.begin(), [maxElement](double num) { return num /= (maxElement / 2); });
	}
}