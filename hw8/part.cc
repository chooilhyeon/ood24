#include "part.h"

Part::Part(std::string factory_name) : factory_name_(std::move(factory_name)) {}

Part::~Part() {}

std::string Part::factory_name() const {
    return factory_name_;
}
