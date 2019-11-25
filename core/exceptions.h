#pragma once
#include <stdexcept>

class InvalidCityException : public std::runtime_error
{
public:
	InvalidCityException(const std::string& message) : std::runtime_error(message) {}
};
