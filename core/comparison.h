#pragma once
#include "core.h"

bool operator==(const Report& report1, const Report& report2)
{
	json j1 = report1;
	json j2 = report2;
	return j1 == j2;
}

bool operator==(const Forecast& forecast1, const Forecast& forecast2)
{
	json j1 = forecast1;
	json j2 = forecast2;
	return j1 == j2;
}
