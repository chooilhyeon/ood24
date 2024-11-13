#include "car.h"
#include "door.h"
#include "wheel.h"
#include "roof.h"
#include <utility>  // std::move 사용
#include <sstream>  // std::ostringstream 사용

Car::Car(Part* door, Part* wheel, Part* roof, std::string color)
    : door_(door), wheel_(wheel), roof_(roof), color_(std::move(color)) {}

Car::Car(const Car& car) {
    if (const Door* door = dynamic_cast<const Door*>(car.door_)) {
        door_ = new Door(*door);
    } else if (const Wheel* wheel = dynamic_cast<const Wheel*>(car.door_)) {
        door_ = new Wheel(*wheel);
    } else if (const Roof* roof = dynamic_cast<const Roof*>(car.door_)) {
        door_ = new Roof(*roof);
    } else {
        door_ = nullptr;
    }

    if (const Door* door = dynamic_cast<const Door*>(car.wheel_)) {
        wheel_ = new Door(*door);
    } else if (const Wheel* wheel = dynamic_cast<const Wheel*>(car.wheel_)) {
        wheel_ = new Wheel(*wheel);
    } else if (const Roof* roof = dynamic_cast<const Roof*>(car.wheel_)) {
        wheel_ = new Roof(*roof);
    } else {
        wheel_ = nullptr;
    }

    if (const Door* door = dynamic_cast<const Door*>(car.roof_)) {
        roof_ = new Door(*door);
    } else if (const Wheel* wheel = dynamic_cast<const Wheel*>(car.roof_)) {
        roof_ = new Wheel(*wheel);
    } else if (const Roof* roof = dynamic_cast<const Roof*>(car.roof_)) {
        roof_ = new Roof(*roof);
    } else {
        roof_ = nullptr;
    }

    color_ = car.color_;
}

Car& Car::operator=(const Car& car) {
    if (this == &car) {
        return *this;
    }

    delete door_;
    delete wheel_;
    delete roof_;

    if (const Door* door = dynamic_cast<const Door*>(car.door_)) {
        door_ = new Door(*door);
    } else if (const Wheel* wheel = dynamic_cast<const Wheel*>(car.door_)) {
        door_ = new Wheel(*wheel);
    } else if (const Roof* roof = dynamic_cast<const Roof*>(car.door_)) {
        door_ = new Roof(*roof);
    } else {
        door_ = nullptr;
    }

    if (const Door* door = dynamic_cast<const Door*>(car.wheel_)) {
        wheel_ = new Door(*door);
    } else if (const Wheel* wheel = dynamic_cast<const Wheel*>(car.wheel_)) {
        wheel_ = new Wheel(*wheel);
    } else if (const Roof* roof = dynamic_cast<const Roof*>(car.wheel_)) {
        wheel_ = new Roof(*roof);
    } else {
        wheel_ = nullptr;
    }

    if (const Door* door = dynamic_cast<const Door*>(car.roof_)) {
        roof_ = new Door(*door);
    } else if (const Wheel* wheel = dynamic_cast<const Wheel*>(car.roof_)) {
        roof_ = new Wheel(*wheel);
    } else if (const Roof* roof = dynamic_cast<const Roof*>(car.roof_)) {
        roof_ = new Roof(*roof);
    } else {
        roof_ = nullptr;
    }

    color_ = car.color_;
    return *this;
}

Car::~Car() {
    delete door_;
    delete wheel_;
    delete roof_;
}

std::string Car::GetSpec() const {
    std::string result = "Car(";
    bool first = true;

    if (door_) {
        result += door_->GetInfo();
        first = false;
    }

    if (wheel_) {
        if (!first) result += ", ";
        result += wheel_->GetInfo();
        first = false;
    }

    if (roof_) {
        if (!first) result += ", ";
        result += roof_->GetInfo();
        first = false;
    }

    if (!color_.empty()) {
        if (!first) result += ", ";
        result += color_;
    }

    result += ")";
    return result;
}