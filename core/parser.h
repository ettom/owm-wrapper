#pragma once
#include <string>

#include <nlohmann/json.hpp>

using json = nlohmann::json;

std::string get_city(const std::string& response);
nlohmann::json to_json(const std::string& input);
std::string get_string_value(json& input);
