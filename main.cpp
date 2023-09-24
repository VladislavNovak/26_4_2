#include <iostream>
#include <string>
#include <vector>
#include "phone.h"

using std::string;
using std::vector;

int main() {
    Phone phone{};

    phone.doAdd();
    phone.doAdd();
    phone.doChange();
    phone.doCall();

    return 0;
}
