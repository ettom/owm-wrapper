#include "parser.h"

json to_json(const std::string& input)
{
	return json::parse(input);
}

std::string get_city(const std::string& response)
{
	return to_json(response)["name"];
}

std::string get_string_value(json& input)
{
	if (input.is_string()) {
		return input.get<std::string>();
	}
	return "";
}
