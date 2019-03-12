/* Inheritance basics: part 1 */

#include <iostream>

class FarmAnimal
{
public:
	FarmAnimal(double water_consumption);
	double getWaterConsumption();
private:
	double water_consumption;
};

class DummyAnimal : public FarmAnimal
{
public:
	DummyAnimal();
};

class DoublingAnimal : public FarmAnimal
{
public:
	DoublingAnimal(double given_water_consumption);
};

FarmAnimal::FarmAnimal(double water_consumption)
{
	this->water_consumption = water_consumption;
}

double FarmAnimal::getWaterConsumption()
{
	return water_consumption;
}

DummyAnimal::DummyAnimal() : FarmAnimal(10.0)
{
	
}

DoublingAnimal::DoublingAnimal(double given_water_consumption)
: FarmAnimal(2 * given_water_consumption)
{
	
}

void printConsumption(FarmAnimal animal)
{
	std::cout << "This animal consumes " << animal.getWaterConsumption() << " liters of water " << std::endl;
}

int main(void)
{
	FarmAnimal animalA(5);
	DummyAnimal animalB;
	DoublingAnimal animalC(21);
	
	std::cout << "animalA consumes " << animalA.getWaterConsumption()
	<< " liters of water." << std::endl;
	std::cout << "What about the others?" << std::endl;
	
	printConsumption(animalB);
	printConsumption(animalC);
	
	return 0;
}







