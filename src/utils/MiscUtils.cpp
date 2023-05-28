//
// Created by Private on 5/24/2023.
//

#include "MiscUtils.h"
#include <iostream>
#include <sstream>

std::string MiscUtils::ReadString(std::istream &stream) {
    size_t len;
    stream.read(reinterpret_cast<char *>(&len), sizeof(len));
    std::string str(len, '\0');
    stream.read(&str[0], (long long) len);
    return str;
}

std::queue<std::string> *MiscUtils::SplitString(const std::string &str, char delimiter) {
    auto queue = new std::queue<std::string>();
    std::string temp;
    std::stringstream ss(str);
    while (std::getline(ss, temp, delimiter)) {
        queue->push(temp);
    }
    return queue;
}
