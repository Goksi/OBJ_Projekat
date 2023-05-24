
#include "SerializationUtils.h"

using namespace std;

template<class T>
void SerializationUtils::Serialize(const vector<T> vector, const string &fileName) {
    ofstream file(fileName, ios::binary | ios::trunc);
    if (!file.is_open()) throw FileException();
    size_t size = vector.size();
    file.write(reinterpret_cast<const char *>(&size), sizeof(size));

    for (const T &object: vector) {
        object.Serialize(file);
    }
    file.close();
}

template<class T>
void SerializationUtils::Deserialize(vector<T> &vector, const string &fileName) {
    ifstream file(fileName, ios::binary);
    if (!file.is_open()) throw FileException("Fajl za deserializaciju nije pronadjen !");
    size_t size;
    file.read(reinterpret_cast<char *>(&size), sizeof(size));

    for (size_t i = 0; i < size; i++) {
        T t;
        t.Deserialize(file);
        vector.push_back(t);
    }
    file.close();
}
