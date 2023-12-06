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

void Test2::testThresholds()
{
	setFuelQuantity(10);
	setFishQuantity(5);
	setIngotQuantity(20);

	if (fuelThreshold() == true)
	{
		std::cout << "fuelThreshold is working! (>=10)" << std::endl;
	}
	else
	{
		std::cout << "fuelThreshold is NOT working! (<10)" << std::endl;
	}
	if (fishThreshold() == false)
	{
		std::cout << "fishThreshold is working! (<10)" << std::endl;
	}
	else
	{
		std::cout << "fishThreshold is working! (>=10)" << std::endl;
	}
	if (ingotThreshold() == true)
	{
		std::cout << "ingotThreshold is working! (>=10)" << std::endl;
	}
	else
	{
		std::cout << "ingotThreshold is NOT working! (<10)" << std::endl;
	}
}

void Test2::testIsRepaired()
{
	setFuelQuantity(10);
	setFishQuantity(10);
	setIngotQuantity(10);

	if (isRepaired() == true)
	{
		std::cout << "isRepaired is working! (resource thresholds met)" << std::endl;
	}
	else
	{
		std::cout << "isRepaired is NOT working! (resource thresholds not met)" << std::endl;
	}
}