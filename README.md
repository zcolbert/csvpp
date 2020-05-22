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

	std::ifstream fs;
	fs.open(testFile);

	std::vector<csv::row> rows;

	if (fs.is_open())
	{
		std::string line;
		while (std::getline(fs, line))
		{
			rows.push_back(csv::parseRow(line));
		}
	}
	std::cout << "Finished\n";

	return 0;
}
```
