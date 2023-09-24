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

    // Вызывается лишь конструктором или через changeRecord
    bool setPhone();

    // Вызывается лишь конструктором или через changeRecord
    void setOwner();

public:
    Record();

    // Вызывается, если необходимо поменять в записи string key или vector<string> values
    void changeRecord();

    string getOwner();

    vector<string> getOwnerPhones();

    // Возвращает key + values в виде одной строки
    string getRecord();
};

#endif //INC_26_4_2_RECORD_H