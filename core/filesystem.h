#pragma once
#include <vector>
#include <string>
#include <filesystem>
#include <fstream>

#include <nlohmann/json.hpp>

using json = nlohmann::json;

std::vector<std::string> read_file(const std::string& filename)
{
	std::ifstream infile(filename);

	std::string line;
	std::vector<std::string> result;

	if (!infile.is_open()) {
		throw std::runtime_error("Couldn't open file at " + filename + " for reading!");
	}

	while (std::getline(infile, line)) {
		result.push_back(line);
	}

	return result;
}

void write_json_to_file(const std::string& filename, const json& to_write)
{
	std::ofstream ofs(filename);

	if (!ofs.is_open()) {
		throw std::runtime_error("Couldn't open file at " + filename + " for writing!");
	}

	ofs << std::setw(4) << to_write << std::endl;
}
