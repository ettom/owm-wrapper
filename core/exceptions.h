#pragma once
#include <stdexcept>

class InvalidCityException : public std::runtime_error
{
public:
	InvalidCityException(): std::runtime_error("Received city does not match the given city") {}
};
