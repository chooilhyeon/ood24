#include "roof.h"
#include <string>

Roof::Roof(std::string factory_name) : Part(std::move(factory_name)) {}


std::string Roof::GetInfo() const {
    return "[" + factory_name() + "][Roof]";
}