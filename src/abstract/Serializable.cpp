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
