#pragma once

#include <vector>
#include <string>


namespace csv 
{
	using row = std::vector<std::string>;

	row parseRow(const std::string& row, const char delimiter = ',');
}
