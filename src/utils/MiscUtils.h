//
// Created by Private on 5/24/2023.
//

#ifndef OBJ_PROJEKAT_MISCUTILS_H
#define OBJ_PROJEKAT_MISCUTILS_H

#include <string>
#include <fstream>
#include <string>

class MiscUtils {
private:
    MiscUtils() = default;

public:
    static std::string ReadString(std::istream &stream);
};


#endif //OBJ_PROJEKAT_MISCUTILS_H
