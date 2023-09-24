#ifndef INC_26_4_2_PHONE_H
#define INC_26_4_2_PHONE_H

#include <string>
#include <vector>
#include "utilities.h"
#include "record.h"

using std::string;
using std::vector;

// Возможные варианты действий. Реализация - в doAction
enum class Action {
    change, call, sms
};

class Phone {
    vector<Record*> records;

    vector<string> getRecordsKeys();

    vector<vector<string>> getRecordsValues();

    // Вызывается лишь через doAction
    void doPhoneCall(int index);

    // Вызывается лишь через doAction
    void doPhoneSms(int index);

    // Вызывается лишь через doChange, doCall, doSms
    void doAction(Action action);

public:
    Phone();

    void doAdd();

    // Выводит данные о всех записях
    void displaySubscribers(const string &msg = "List of subscribers:");

    void doChange();

    void doCall();

    void doSms();

    // Вызвать перед завершением программы для очистки массива указателей
    void doExit();
};

#endif //INC_26_4_2_PHONE_H
