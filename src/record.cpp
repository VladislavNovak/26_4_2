#include "record.h"

bool Record::setPhone() {
    auto input = putNumberAsString("Enter phone", PHONE_LENGTH);
    if (values.empty()) {
        values.emplace_back(input);
        return true;
    }

    auto result = findKeyIndexInVector(input, values);
    if (result < 0) {
        std::cout << "Phone added successfully!" << std::endl;
        values.emplace_back(input);
        return true;
    }

    std::cout << "There is already such a phone!" << std::endl;
    return false;
}

void Record::setOwner() {
    key = putLineString("Enter name of owner");
}

Record::Record() {
    setOwner();
    setPhone();
    std::cout << "Data saved successfully!" << std::endl;
}

void Record::changeRecord() {
    std::cout << "Selected data: " << getRecord() << std::endl;
    const vector<string> menuTop = {"owner", "phone"};
    auto inputTop = selectMenuItem(menuTop, "To change owner's name or phone number");
    if (menuTop[inputTop] == "owner") {
        setOwner();
        std::cout << "The previous owner's name has been replaced!" << std::endl;
        return;
    }

    // Case menuTop->phone:
    vector<string> menuPhone = {"add"};
    string msg = "To add new phone";
    if (!values.empty()) {
        menuPhone.emplace_back("delete");
        msg += " or delete";
    }

    auto inputPhone = selectMenuItem(menuPhone, msg);
    if (menuPhone[inputPhone] == "add") {
        setPhone();
        return;
    }

    // Case menuPhone->delete
    if (values.size() == 1) {
        values.clear();
        std::cout << "Phone deleted!" << std::endl;
    } else {
        std::cout << "Enter the phone number to be deleted (0 - " << values.size() - 1 << "):";
        while (true) {
            int index;
            std::cin >> index;
            if (index >= 0 && index < values.size()) {
                resetBuffer();
                values.erase(values.begin() + index);
                std::cout << "Phone deleted!" << std::endl;
                break;
            }
            std::cout << "Input is invalid. Try again:";
            resetBuffer();
        }
    }
}

string Record::getOwner() { return key; }

vector<string> Record::getOwnerPhones() { return values; }

string Record::getRecord() {
    string data = (key + ": ");
    if (values.empty()) { return (data + "no entry yet"); }
    for (const auto &phone: values) { data += (" +7 " + phone); }

    return data;
}