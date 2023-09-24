#include <iostream>
#include <string>
#include <vector>
#include "include/phone.h"

using std::string;
using std::vector;

int main() {
    vector<string> mainMenu = { "add", "display", "change", "call", "sms", "exit" };

    Phone phone{};

    std::cout << "POWER ON" << std::endl;

    while (true) {
        std::cout << "--- Main menu ---" << std::endl;
        int command = selectMenuItem(mainMenu);

        if (mainMenu[command] == "add") { phone.doAdd(); }
        else if (mainMenu[command] == "display") { phone.displaySubscribers(); }
        else if (mainMenu[command] == "change") { phone.doChange(); }
        else if (mainMenu[command] == "call") { phone.doCall(); }
        else if (mainMenu[command] == "sms") { phone.doSms(); }
        else {
            phone.doExit();
            break;
        }
    }

    std::cout << "POWER OFF" << std::endl;

    return 0;
}
