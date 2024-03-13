#define CATCH_CONFIG_MAIN
#include <vector\Add.h>
#include <..\..\catch2\catch.hpp>
#include <vector>

bool VectorsAreEqual(std::vector<double> const& x, std::vector<double> const& y)
{
	return x == y;
}



TEST_CASE("divide_vector_on_half_of_max_element")
{
	std::vector<double> emptyVector;
	DivVectorOnHalfOfMax(emptyVector);
	CHECK(emptyVector.empty());
	CHECK(2 + 2 == 4);

	std::vector<double> numbers = { 10, 20, 30 };
	DivVectorOnHalfOfMax(numbers);

	double first = 10.00 / 15;
	double second = 20.00 / 15;
	double third = 2;
	CHECK(VectorsAreEqual(numbers, { first, second, third }));

	std::vector<double> numbers1 = { -10, -5, 0 };
	DivVectorOnHalfOfMax(numbers1);

	/*double first1 = -10.00 / 0;
	double second1 = -5.00 / 0;
	double third1 = 0;
	CHECK(VectorsAreEqual(numbers1, { first1, second1, third1 }));*/
}
