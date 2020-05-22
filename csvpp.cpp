#include <sstream>
#include <vector>

#include "csvpp.h"


csv::row csv::parseRow(const std::string& row, const char delimiter /* = ',' */)
{
	csv::row fields;
	std::ostringstream oss;

	bool quoted = false;

	size_t i = 0;
	do {
		if (row[i] == '\0')
		{
			fields.push_back(oss.str());
			oss.str("");
			oss.clear();
			break;
		}
		else if (row[i] == delimiter && !quoted)
		{
			fields.push_back(oss.str());
			oss.str("");
			oss.clear();
		}
		else if (row[i] == '"')
		{
			quoted = !quoted;
		}
		else
		{
			oss << row[i];
		}
	} while (row[i++]);

	return fields;
}
