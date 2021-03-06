#include <sstream>
#include <vector>

#include "csvpp.h"


csv::row 
csv::parseRow(const std::string& line, 
              const char delimiter /* = ',' */)
{
	csv::row fields;
	std::ostringstream oss;

	bool quoted = false;

	size_t i = 0;
	do {
		if (line[i] == '\0')
		{
			fields.push_back(oss.str());
			oss.str("");
			oss.clear();
			break;
		}
		else if (line[i] == delimiter && !quoted)
		{
			fields.push_back(oss.str());
			oss.str("");
			oss.clear();
		}
		else if (line[i] == '"')
		{
			quoted = !quoted;
		}
		else
		{
			oss << line[i];
		}
	} while (line[i++]);

	return fields;
}

bool 
csv::stringContainsDelim(const std::string& str, 
                         const char delimiter /* = ',' */)
{
	for (auto c : str) {
		if (c == delimiter)
		{
			return true;
		}
	}
	return false;
}

std::string 
csv::joinFields(const csv::row& fields, 
                const char delimiter /* = ',' */)
{
	std::ostringstream oss;
	for (auto it = fields.begin(); it != fields.end(); ++it)
	{
		if (csv::stringContainsDelim(*it, delimiter)) 
		{
			// enclose the field in double-quotes
			oss << '"' << *it << '"';
		}
		else {
			oss << *it;
		}
		// if not processing the last field, add a delimiter
		if (it+1 != fields.end()) {
			oss << delimiter;
		}
	}
	return oss.str();
}

std::vector<csv::row> 
csv::readRows(std::ifstream* fs, 
              const char delimiter /* = ',' */)
{
	std::vector<csv::row> rows;
	std::string line;
	while (std::getline(*fs, line))
	{
		csv::row fields = csv::parseRow(line, delimiter);
		rows.push_back(fields);
	}
	return rows;
}

void 
csv::writeRow(std::ofstream* fs, 
              const csv::row& fields, 
              const char delimiter /* = ',' */)
{
	*fs << joinFields(fields, delimiter) << '\n';
}

void 
csv::writeRows(std::ofstream* fs, 
               const std::vector<csv::row>& rows, 
               const char delimiter /* = ',' */)
{
    for (auto r : rows)
    {
        csv::writeRow(fs, r, delimiter);
    }
}
