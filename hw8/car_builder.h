#ifndef _CAR_BUILDER_H
#define _CAR_BUILDER_H

#include "car_parts_factory.h"
#include "car.h"
#include <string>

class CarBuilder {
	public:
		explicit CarBuilder(const CarPartsFactory* factory);
		CarBuilder& CreateDoor();
		CarBuilder& CreateWheel();
		CarBuilder& CreateRoof();
		CarBuilder& SetColor(std::string color);
		Car* Build();
	private:
		Part* door_;
		Part* wheel_;
		Part* roof_;
		std::string color_;
		const CarPartsFactory* factory_;
};

#endif  // _CAR_BUILDER_H