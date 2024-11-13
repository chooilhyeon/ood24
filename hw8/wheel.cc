#include "wheel.h"
#include <string>

Wheel::Wheel(std::string factory_name) : Part(std::move(factory_name)) {}

std::string Wheel::GetInfo() const {
    return "[" + factory_name() + "][Wheel]";
}