#include "phone.h"

vector<string> Phone::getRecordsKeys() {
    if (records.empty()) return {};

    vector<string> keys;
    keys.reserve(records.size());
    for (const auto &record: records) {
        keys.emplace_back(record->getOwner());
    }

    return keys;
}

vector<vector<string>> Phone::getRecordsValues() {
    if (records.empty()) return {};

    vector<vector<string>> values;
    values.reserve(records.size());
    for (const auto &record: records) {
        values.emplace_back(record->getOwnerPhones());
    }

    return values;
}

void Phone::doPhoneCall(int index) {
    std::cout << "The phone is dialing:" << std::endl;
    std::cout << records[index]->getRecord() << std::endl;
}

void Phone::doPhoneSms(int index) {
    auto smsMsg = putLineString("Enter SMS message");
    std::cout << "SMS message (" << smsMsg << ") sent to subscriber:" << std::endl;
    std::cout << records[index]->getRecord() << std::endl;
}

void Phone::doAction(Action action) {
    if (records.empty()) {
        std::cout << "There are no records yet!" << std::endl;
        return;
    }

    if (action == Action::call || action == Action::sms) {
        vector<string> searchMenu = {"owner", "phone"};

        while (true) {
            displaySubscribers();

            auto selectType = selectMenuItem(searchMenu, "To select a search type");
            if (searchMenu[selectType] == "exit") { return; }

            if (searchMenu[selectType] == "owner") {
                string input = putLineString("Enter owner's name");
                auto ownerIndex = findKeyIndexInVector(input, getRecordsKeys());
                if (ownerIndex >= 0) {
                    if (action == Action::call) { doPhoneCall(ownerIndex); }
                        // Case action == Action::sms
                    else { doPhoneSms(ownerIndex); }
                    return;
                }
            }

            if (searchMenu[selectType] == "phone") {
                string input = putLineString("Enter phone (without +7)");
                auto phoneIndex = findKeyInVectors(input, getRecordsValues());
                if (phoneIndex >= 0) {
                    if (action == Action::call) { doPhoneCall(phoneIndex); }
                        // Case action == Action::sms
                    else { doPhoneSms(phoneIndex); }
                    return;
                }
            }

            // ���� ������� �������� ������:
            std::cout << "Record not found. Try again!" << std::endl;
            if (findKeyIndexInVector<string>("exit", searchMenu) == -1) {
                searchMenu.emplace_back("exit");
            }
        }
    }
        // Case action == Action::change
    else {
        if (records.size() == 1) {
            records[0]->changeRecord();
            return;
        }

        // Case records.size() > 1:
        displaySubscribers("Enter the index of the record you want to change");
        while (true) {
            int index;
            std::cin >> index;
            if (index >= 0 && index < records.size()) {
                resetBuffer();
                records[index]->changeRecord();
                break;
            }
            std::cout << "Input is invalid. Try again:";
            resetBuffer();
        }
    }
}

Phone::Phone() = default;

void Phone::doAdd() {
    std::cout << "Create new record" << std::endl;
    records.emplace_back(new Record());
}

void Phone::displaySubscribers(const string &msg) {
    if (records.empty()) {
        std::cout << "There are no records yet!" << std::endl;
        return;
    }

    printf("%s:\n", msg.c_str());
    for (int i = 0; i < records.size(); ++i) {
        std::cout << i << ": " << records[i]->getRecord() << std::endl;
    }
}

void Phone::doChange() {
    std::cout << "Log: change mode" << std::endl;
    doAction(Action::change);
}

void Phone::doCall() {
    std::cout << "Log: call mode" << std::endl;
    doAction(Action::call);
}

void Phone::doSms() {
    std::cout << "Log: sms mode" << std::endl;
    doAction(Action::sms);
}

void Phone::doExit() {
    for (const auto &item: records) { delete item; }
    records.clear();
}
