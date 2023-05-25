//
// Created by Private on 5/24/2023.
//

#include "MiscUtils.h"
#include <iostream>

std::string MiscUtils::ReadString(std::istream &stream) {
    size_t len;
    stream.read(reinterpret_cast<char *>(&len), sizeof(len));
    std::string str(len, '\0');
    stream.read(&str[0], (long long) len);
    return str;
}
