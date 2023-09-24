#ifndef INC_26_4_2_RECORD_H
#define INC_26_4_2_RECORD_H

#include <string>
#include <vector>
#include "utilities.h"

using std::string;
using std::vector;

class Record {
    const int PHONE_LENGTH = 10;
    string key;
    vector<string> values;

    // ���������� ���� ������������� ��� ����� changeRecord
    bool setPhone();

    // ���������� ���� ������������� ��� ����� changeRecord
    void setOwner();

public:
    Record();

    // ����������, ���� ���������� �������� � ������ string key ��� vector<string> values
    void changeRecord();

    string getOwner();

    vector<string> getOwnerPhones();

    // ���������� key + values � ���� ����� ������
    string getRecord();
};

#endif //INC_26_4_2_RECORD_H