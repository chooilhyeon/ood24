#include "kia_parts_factory.h"

KiaPartsFactory* KiaPartsFactory::instance_ = nullptr;

KiaPartsFactory* KiaPartsFactory::GetInstance() {
    if (instance_ == nullptr) {
        instance_ = new KiaPartsFactory();
    }
    return instance_;
}

KiaPartsFactory::KiaPartsFactory() {}

Part* KiaPartsFactory::CreateDoor() const {
    return new Door("Kia");
}

Part* KiaPartsFactory::CreateWheel() const {
    return new Wheel("Kia");
}

Part* KiaPartsFactory::CreateRoof() const {
    return new Roof("Kia");
}