#ifndef _CAR_H
#define _CAR_H

#include "part.h"
#include <string>

class CarBuilder;

class Car {
	public:
		std::string GetSpec() const;
		Car(const Car& car);
		Car& operator =(const Car& car);
		~Car();
	private:
		Car(Part* door, Part* wheel, Part* roof, std::string color);
		Part* door_;
		Part* wheel_;
		Part* roof_;
		std::string color_;
		friend CarBuilder;
};

#endif  // _CAR_H