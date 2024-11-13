#include "door.h"
#include <string>

Door::Door(std::string factory_name) : Part(std::move(factory_name)) {}

std::string Door::GetInfo() const {
    return "[" + factory_name() + "][Door]";
}