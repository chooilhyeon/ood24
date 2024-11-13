#include "car_builder.h"
#include <cassert>
#include <iostream>  // std::cerr 사용

CarBuilder::CarBuilder(const CarPartsFactory* factory)
    : factory_(factory), door_(nullptr), wheel_(nullptr), roof_(nullptr), color_("") {}

CarBuilder& CarBuilder::CreateDoor() {
    assert(door_ == nullptr && "Duplicated Parts retain : Door");
    door_ = factory_->CreateDoor();
    return *this;
}

CarBuilder& CarBuilder::CreateWheel() {
    assert(wheel_ == nullptr && "Duplicated Parts retain : Wheel");
    wheel_ = factory_->CreateWheel();
    return *this;
}

CarBuilder& CarBuilder::CreateRoof() {
    assert(roof_ == nullptr && "Duplicated Parts retain : Roof");
    roof_ = factory_->CreateRoof();
    return *this;
}

CarBuilder& CarBuilder::SetColor(std::string color) {
    color_ = std::move(color);
    return *this;
}

Car* CarBuilder::Build() {

    Car* car = new Car(door_, wheel_, roof_, color_);
    
    door_ = nullptr;
    wheel_ = nullptr;
    roof_ = nullptr;
    color_ = "";

    return car;
}