//
// Created by Private on 5/23/2023.
//

#include "FileException.h"

#include <utility>


FileException::FileException() {
    message = "Greska pri otvaranju fajla !";
}

const char *FileException::what() const noexcept {
    return message.c_str();
}

FileException::FileException(std::string message) {
    this->message = std::move(message);
}
