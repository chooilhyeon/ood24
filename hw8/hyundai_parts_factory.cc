#include "hyundai_parts_factory.h"

HyundaiPartsFactory* HyundaiPartsFactory::instance_ = nullptr;

HyundaiPartsFactory* HyundaiPartsFactory::GetInstance() {
    if (instance_ == nullptr) {
        instance_ = new HyundaiPartsFactory();
    }
    return instance_;
}

HyundaiPartsFactory::HyundaiPartsFactory() {}

Part* HyundaiPartsFactory::CreateDoor() const {
    return new Door("Hyundai");
}

Part* HyundaiPartsFactory::CreateWheel() const {
    return new Wheel("Hyundai");
}

Part* HyundaiPartsFactory::CreateRoof() const {
    return new Roof("Hyundai");
}