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
	for (int i = 0; i < 50; i++) {
		incrementFishQuantity();
	}

	if (getFishQuantity() > 0.0)
	{
		std::cout << "incrementFishQuantity function works!" << std::endl;
	}
	else
	{
		std::cout << "incrementFishQuantity function doesn't work!" << std::endl;
	}
}

void Test::testHasPickaxe()
{
	setHasPickaxe(true);

	if (getHasPickaxe() == true)
	{
		std::cout << "getHasPickaxe function works!" << std::endl;
	}

	else
	{
		std::cout << "getHasPickaxe function doesn't work!" << std::endl;
	}
}