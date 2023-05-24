
#ifndef OBJ_PROJEKAT_SERIALIZATIONUTILS_H
#define OBJ_PROJEKAT_SERIALIZATIONUTILS_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "FileException.h"

class SerializationUtils {
public:
    template<class T>
    static void Serialize(int lastId, std::vector<T> vector, const std::string &fileName);

    template<class T>
    static void Deserialize(int &lastId, std::vector<T> &vector, const std::string &fileName);

private:
    SerializationUtils() = default;
};


#endif //OBJ_PROJEKAT_SERIALIZATIONUTILS_H
