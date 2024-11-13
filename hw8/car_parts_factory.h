#ifndef _CAR_PARTS_FACTORY_H
#define _CAR_PARTS_FACTORY_H

#include "part.h"

class CarPartsFactory {
public:
    virtual ~CarPartsFactory() = default;
    virtual Part* CreateDoor() const = 0;
    virtual Part* CreateWheel() const = 0;
    virtual Part* CreateRoof() const = 0;
};

#endif  // _CAR_PARTS_FACTORY_H