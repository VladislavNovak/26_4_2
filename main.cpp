#include <iostream>
#include <string>
#include <vector>
#include "utilities.h"
#include "record.h"

using std::string;
using std::vector;

int main() {
    Record record;

    record.changeRecord();
    record.changeRecord();
    record.changeRecord();

    auto result = record.getRecord();
    std::cout << result << std::endl;


    return 0;
}
