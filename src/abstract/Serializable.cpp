//
// Created by Private on 5/24/2023.
//
#include "Serializable.h"

int Serializable::GetId() const {
    return id;
}

Serializable::Serializable(int id) {
    this->id = id;
}

void Serializable::Serialize(std::ostream &stream) const {
    stream << id;
}

void Serializable::Deserialize(std::istream &stream) {
    int idFromFile;
    stream.read(reinterpret_cast<char *>(&idFromFile), sizeof(idFromFile));
    this->id = idFromFile;
}
