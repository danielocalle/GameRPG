#include "Test.h"

void Test::testGetWoodQuantity()
{
	setWoodQuantity(10);

	if (getWoodQuantity() == 10)
	{
		std::cout << "getWoodQuantity function and setWoodQuantity function works!" << std::endl;
	}

	else
	{
		std::cout << "getWoodQuantity function and setWoodQuantity function doesn't work!" << std::endl;
	}
}

void Test::testIncrementFishQuantity()
{
	// have to repeat incrementFishQuantity many times because it only increments by 0.106 and
	// the getFishQuantity returns an integer.
	incrementFishQuantity();
	incrementFishQuantity();
	incrementFishQuantity();
	incrementFishQuantity();
	incrementFishQuantity();
	incrementFishQuantity();
	incrementFishQuantity();
	incrementFishQuantity();
	incrementFishQuantity();
	incrementFishQuantity();

	if (getFishQuantity() > 0.0)
	{
		std::cout << "incrementFishQuantity function works!" << std::endl;
	}

	else
	{
		std::cout << "incrementFishQuantity function doesn't work!" << std::endl;
	}
}
