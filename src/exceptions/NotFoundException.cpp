//
// Created by Private on 5/24/2023.
//

#include "NotFoundException.h"

const char *NotFoundException::what() const noexcept {
    return "Zahtevan entitet nije pronadjen";
}
