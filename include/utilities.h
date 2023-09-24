#ifndef INC_26_4_2_UTILITIES_H
#define INC_26_4_2_UTILITIES_H

#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>

using std::string;
using std::cout;
using std::endl;

template<typename T, typename N>
bool isIncludes(const T &range, const N &item);

void resetBuffer();

char putChar(bool isEnd, const std::string &current);

std::string putNumberAsString(const std::string &msg, int charCount = 1);

std::string putLineString(const std::string &msg);

template<typename T>
int findKeyIndexInVector(const T &key, const std::vector<T> &list);

int findKeyInVectors(const string &key, const std::vector<std::vector<string>> &list);

int selectMenuItem(const std::vector<std::string> &list, const std::string &msg = "Select and");

#endif //INC_26_4_2_UTILITIES_H
