# csvpp

A set of functions for reading and writing CSV files.

```cpp
// Example usage:

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "csvpp.h"


int main()
{
    using namespace std;
	
    std::string testFile("my_csv_file.csv");

    std::ifstream ifs;
    ifs.open(testFile);

    std::vector<csv::row> rows;

    if (ifs.is_open()) {
        rows = csv::readRows(&ifs);
    }

    std::ofstream ofs;
    ofs.open(outFile);

    if (ofs.is_open()) {
        csv::writeRows(&ofs, rows, '|');
    }

    return 0;
}
```
