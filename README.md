# csvpp

```cpp
// Example:

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "csvpp.h"

std::string testFile("my_csv_file.csv");


int main()
{
	using namespace std;

	std::ifstream ifs;
	ifs.open(testFile);

	std::vector<csv::row> rows;

	if (ifs.is_open())
	{
		rows = csv::readRows(&ifs);
	}

	std::ofstream ofs;
	ofs.open(outFile);

	if (ofs.is_open())
	{
		csv::writeRows(&ofs, rows, '|');
	}

	return 0;
}
```
