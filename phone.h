#ifndef INC_26_4_2_PHONE_H
#define INC_26_4_2_PHONE_H

#include <string>
#include <vector>
#include "utilities.h"
#include "record.h"

using std::string;
using std::vector;

enum class Action { change, call };

class Phone {
    vector<Record*> records;

    vector<string> getRecordsKeys() {
        if (records.empty()) return {};

        vector<string> keys;
        keys.reserve(records.size());
        for (const auto &record : records) {
            keys.emplace_back(record->getOwner());
        }

        return keys;
    }

    vector<vector<string>> getRecordsValues() {
        if (records.empty()) return {};

        vector<vector<string>> values;
        values.reserve(records.size());
        for (const auto &record : records) {
            values.emplace_back(record->getOwnerPhones());
        }

        return values;
    }

    void doPhoneCall(int index) {
        std::cout << "The phone is dialing:" << std::endl;
        std::cout << records[index]->getRecord() << std::endl;
    }

    void doAction(Action action) {
        if (records.empty()) {
            std::cout << "There are no records yet!" << std::endl;
            return;
        }

        if (action == Action::call) {
            vector<string> searchMenu = { "owner", "phone" };

            while (true) {
                auto selectType = selectMenuItem(searchMenu, "To select a search type");
                if (searchMenu[selectType] == "exit") { return; }

                std::cout << "List:" << std::endl;
                for (const auto &record : records) {
                    std::cout << record->getRecord() << std::endl;
                }

                if (searchMenu[selectType] == "owner") {
                    string input = putLineString("Enter owner's name");
                    auto ownerIndex = findKeyIndexInVector(input, getRecordsKeys());
                    if (ownerIndex >= 0) {
                        doPhoneCall(ownerIndex);
                        return;
                    }
                }

                if (searchMenu[selectType] == "phone") {
                    string input = putLineString("Enter phone (without +7");
                    auto phoneIndex = findKeyInVectors(input, getRecordsValues());
                    if (phoneIndex >= 0) {
                        doPhoneCall(phoneIndex);
                        return;
                    }
                }

                // Если введены неверные данные:
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
            std::cout << "Enter the index of the record you want to change:" << std::endl;
            for (int i = 0; i < records.size(); ++i) {
                std::cout << i << ": " << records[i]->getRecord() << std::endl;
            }
            while(true) {
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
public:
    Phone() = default;

    void doAdd() {
        std::cout << "Create new record" << std::endl;
        records.emplace_back(new Record());
    }

    void doChange() {
        std::cout << "Log: change mode" << std::endl;
        doAction(Action::change);
    }

    void doCall() {
        std::cout << "Log: call mode" << std::endl;
        doAction(Action::call);
    }
};

#endif //INC_26_4_2_PHONE_H
