#ifndef INC_26_4_2_PHONE_H
#define INC_26_4_2_PHONE_H

#include <string>
#include <vector>
#include "utilities.h"
#include "record.h"

using std::string;
using std::vector;

// ��������� �������� ��������. ���������� - � doAction
enum class Action {
    change, call, sms
};

class Phone {
    vector<Record*> records;

    vector<string> getRecordsKeys();

    vector<vector<string>> getRecordsValues();

    // ���������� ���� ����� doAction
    void doPhoneCall(int index);

    // ���������� ���� ����� doAction
    void doPhoneSms(int index);

    // ���������� ���� ����� doChange, doCall, doSms
    void doAction(Action action);

public:
    Phone();

    void doAdd();

    // ������� ������ � ���� �������
    void displaySubscribers(const string &msg = "List of subscribers:");

    void doChange();

    void doCall();

    void doSms();

    // ������� ����� ����������� ��������� ��� ������� ������� ����������
    void doExit();
};

#endif //INC_26_4_2_PHONE_H
