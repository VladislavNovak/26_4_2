#include "utilities.h"

template<typename T, typename N>
bool isIncludes(const T &range, const N &item) {
    return std::any_of(range.begin(),
                       range.end(),
                       [&item](const N &c) { return c == item; });
}

void resetBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

char putChar(bool isEnd, const std::string &current) {
    const std::string &allowedList = "0123456789";
    char input;

    while (!isEnd) {
        std::cin >> input;

        if (std::cin.fail() || (allowedList.length() && !isIncludes(allowedList, input))) {
            resetBuffer();
            std::cout << "Now in buffer: " << current << ". Current char invalid. Try again:";
            continue;
        }
        break;
    }

    if (isEnd) resetBuffer();

    return input;
}

std::string putNumberAsString(const std::string &msg, int charCount) {
    printf("%s (%i digits):", msg.c_str(), charCount);
    string input;
    while ((charCount--) > 0) { input += putChar(charCount == 0, input); }

    return input;
}

std::string putLineString(const std::string &msg) {
    printf("%s:", msg.c_str());
    while (true) {
        std::string userLineString;
        std::getline(std::cin, userLineString);

        if (userLineString.empty()) {
            std::cout << "The string cannot be empty. Try again:";
            continue;
        }

        return userLineString;
    }
}

template<typename T>
int findKeyIndexInVector(const T &key, const std::vector<T> &list) {
    const int NOT_FOUND = -1;
    auto it = std::find_if(list.cbegin(), list.cend(), [key](const T &i) { return i == key; });

    if (it != list.cend()) {
        return (int) std::distance(list.cbegin(), it);
    }

    return NOT_FOUND;
}

int findKeyInVectors(const string &key, const std::vector<std::vector<string>> &list) {
    for (auto it = list.begin(); it != list.end(); ++it) {
        int result = findKeyIndexInVector(key, *it);
        if (result >= 0) {
            return (int) std::distance(list.begin(), it);
        }
    }

    return -1;
}

int selectMenuItem(const std::vector<std::string> &list, const std::string &msg) {
    string commands;
    for (const auto &item: list)
        commands += (item + (item != list[list.size() - 1] ? "|" : ""));

    printf("%s enter (%s):", msg.c_str(), commands.c_str());
    while (true) {
        std::string userInput;
        std::getline(std::cin, userInput);

        for (int i = 0; i < list.size(); ++i)
            if (list[i] == userInput) return i;

        std::cout << "Error. Try again:";
    }
}

