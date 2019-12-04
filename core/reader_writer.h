#pragma once
#include <filesystem>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <stdexcept>

#include <nlohmann/json.hpp>

#include "core.h"

class ReaderWriter
{
public:
	virtual ~ReaderWriter() {};

	ReaderWriter() = default;
	ReaderWriter(const ReaderWriter& copy_from) = default;
	ReaderWriter& operator=(const ReaderWriter& copy_from) = default;
	ReaderWriter(ReaderWriter&&) = default;
	ReaderWriter& operator=(ReaderWriter&&) = default;

	virtual std::vector<std::string> read_file() const
	{
		std::ifstream infile(input_filename);

		std::string line;
		std::vector<std::string> result;

		if (!infile.is_open()) {
			throw std::runtime_error("Couldn't open file at " + input_filename + " for reading!");
		}

		while (std::getline(infile, line)) {
			result.push_back(line);
		}

		return result;
	}

	virtual void write_json_to_file(const nlohmann::json& j, const bool append = false) const
	{
		std::ofstream ofs;

		append ? ofs.open(output_filename, std::ios_base::app)
		       : ofs.open(output_filename, std::ios_base::trunc);

		if (!ofs.is_open()) {
			throw std::runtime_error("Couldn't open file at " + output_filename + " for writing!");
		}

		ofs << std::setw(4) << j << std::endl;
	}

	std::string input_filename;
	std::string output_filename;
};
