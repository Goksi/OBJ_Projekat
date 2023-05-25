
#ifndef OBJ_PROJEKAT_SERIALIZATIONUTILS_H
#define OBJ_PROJEKAT_SERIALIZATIONUTILS_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "FileException.h"

using namespace std;

class SerializationUtils {
public:
    template<class T>
    static void Serialize(int lastId, std::vector<T> &vector, const std::string &fileName) {
        ofstream file(fileName, ios::binary | ios::trunc);
        if (!file.is_open()) throw FileException();
        file.write();
        size_t size = vector.size();
        file << size;
        for (const T &object: vector) {
            object.Serialize(file);
        }
        file.close();
    }

    /*TOOD: ovde problem sa citanjem*/
    template<class T>
    static void Deserialize(int &lastId, std::vector<T> &vector, const std::string &fileName) {
        ifstream file(fileName, ios::binary);
        if (!file.is_open()) throw FileException("Fajl za deserializaciju nije pronadjen !");
        file.read(reinterpret_cast<char *>(&lastId), sizeof(int));
        cout << "Last id: " << lastId << endl;
        size_t size;
        file.read(reinterpret_cast<char *>(&size), sizeof(size));
        cout << "Velicina vektora: " << size;
        for (size_t i = 0; i < size; i++) {
            T t;
            t.Deserialize(file);
            vector.push_back(t);
        }
        file.close();
    }

private:
    SerializationUtils() = default;
};


#endif //OBJ_PROJEKAT_SERIALIZATIONUTILS_H
