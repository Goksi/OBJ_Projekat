//
// Created by Private on 5/24/2023.
//

#ifndef OBJ_PROJEKAT_AUTHEXCEPTION_H
#define OBJ_PROJEKAT_AUTHEXCEPTION_H

#include <exception>

class AuthException : public std::exception {
public:
    const char *what() const noexcept override;

};


#endif //OBJ_PROJEKAT_AUTHEXCEPTION_H
