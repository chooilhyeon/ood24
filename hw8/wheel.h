#ifndef _WHEEL_H
#define _WHEEL_H

#include "part.h"

class Wheel : public Part {
public:
    explicit Wheel(std::string factory_name);
    std::string GetInfo() const override;
};

#endif  // _WHEEL_H