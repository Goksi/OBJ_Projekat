//
// Created by Private on 5/24/2023.
//

#include "AuthException.h"

const char *AuthException::what() const noexcept {
    return "Greska u autentikaciji !";
}
