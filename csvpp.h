#pragma once

#include <fstream>
#include <string>
#include <vector>


namespace csv 
{
	using row = std::vector<std::string>;

	row parseRow(const std::string& line, const char delimiter = ',');
	bool stringContainsDelim(const std::string& str, const char delimiter = ',');
	std::string joinFields(const csv::row& fields, const char delimiter = ',');
	void writeRow(std::ofstream* fs, const csv::row& row, const char delimiter = ',');
}
