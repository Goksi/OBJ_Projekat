//
// Created by Private on 5/24/2023.
//

#ifndef OBJ_PROJEKAT_MISCUTILS_H
#define OBJ_PROJEKAT_MISCUTILS_H

#include <string>
#include <fstream>
#include <string>
#include <queue>

class MiscUtils {
private:
    MiscUtils() = default;

public:
    static std::string ReadString(std::istream &stream);

    static std::queue<std::string> *SplitString(const std::string &, char = ' ');
};


#endif //OBJ_PROJEKAT_MISCUTILS_H
